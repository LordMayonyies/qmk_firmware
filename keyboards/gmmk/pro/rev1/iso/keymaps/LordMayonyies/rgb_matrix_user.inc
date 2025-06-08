/* Base Layout
 *
 * | 68 |                                                                                                               | 69 |
 * |    |,-------------------------------------------------------------------------------------------------------------.|    |
 * | 71 || Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Home || Mute || 72 |
 * |    ||=============================================================================================================||    |
 * | 74 || ISO  |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Del  || 75 |
 * |    ||------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------||    |
 * | 77 ||   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] } |        || PgUp || 78 |
 * |    ||---------+------+------+------+------+------+------+------+------+------+------+------+------+       ++------||    |
 * | 81 ||  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  | ISO| Enter || PgDn || 82 |
 * |    ||------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------||    |
 * | 84 || LShift | ISO |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || End  || 85 |
 * |    ||--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======||    |
 * | 88 ||  Ctrl  |   LAlt  |  Cmd   |               Space                  | RAlt |  Fn  | Ctrl || Left | Down | Rght || 89 |
 * |    |`-------------------------------------------------------------------------------------------------------------'|    |
 * | 92 |                                                                                                               | 93 |
 */
/* LED INDEX
 *   0 - ESC           6 - F1       12 - F2       18 - F3       23 - F4       28 - F5       34 - F6       39 - F7       44 - F8       50 - F9       56 - F10      61 - F11      66 - F12      70 - DEL       Rotary(Mute)
 *   1 - §±            7 - 1        13 - 2        19 - 3        24 - 4        29 - 5        35 - 6        40 - 7        45 - 8        51 - 9        57 - 0        62 - -_       79 - (=+)     86 - BackSpc   73 - PgUp
 *   2 - Tab           8 - Q        14 - W        20 - E        25 - R        30 - T        36 - Y        41 - U        46 - I        52 - O        58 - P        63 - [{       90 - ]}       95 - \|        76 - PgDn
 *   3 - Caps          9 - A        15 - S        21 - D        26 - F        31 - G        37 - H        42 - J        47 - K        53 - L        59 - ;:       64 - '"                    97 - Enter      87 - Home
 *   4 - Sh_L  67 - `~  10 - Z       16 - X        22 - C        27 - V        32 - B        38 - N        43 - M        48 - ,<       54 - .<       60 - /?                    91 - Sh_R     94 - Up       83 - End
 *   5 - Ct_L 11 -Win_L    17 - Alt_L                                        33 - SPACE                                          49 - Alt_R    55 - FN                    65 - Ct_R     96 - Left   98 - Down  80 - Right
 */

// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(mac_mode_effect)
RGB_MATRIX_EFFECT(windows_mode_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static const int EXTERIOR_LEDS_COUNT = 22;
static const int exteriorLeds[] = { 0, 6, 12, 18, 23, 28, 34, 39, 44, 50, 56, 61, 66, 70, 73, 76, 87, 83, 94, 96, 98, 80 };

static const int MIDDLE_LEDS_COUNT = 27;
static const int middleLeds[] = { 1, 2, 3, 4, 5, 7, 11, 13, 17, 19, 24, 29, 33, 35, 40, 45, 49, 51, 55, 57, 62, 65, 67, 79, 86, 91, 97 };

static const int SIDE_LEDS_COUNT = 8;
static const int leftSideLEDs[] = { 68, 71, 74, 77, 81, 84, 88, 92 };
static const int rightSideLEDs[] = { 69, 72, 75, 78, 82, 85, 89, 93 };

static const int INTERIOR_LEDS_COUNT = 34;
static const int interiorLeds[] = { 8, 9, 10, 14, 15, 16, 20, 21, 22, 25, 26, 27, 30, 31, 32, 36, 37, 38, 41, 42, 43, 46, 47, 48, 52, 53, 54, 58, 59, 60, 63, 64, 90, 95 };

// e.g: A simple effect, self-contained within a single method
static bool mac_mode_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for(uint8_t i = 0; i < SIDE_LEDS_COUNT; i++) {
    rgb_matrix_set_color(leftSideLEDs[i], RGB_RED);
  }

  for (uint8_t i = 0; i < EXTERIOR_LEDS_COUNT; i++) {
    rgb_matrix_set_color(exteriorLeds[i], RGB_RED);
  }

  for(uint8_t i = 0; i < MIDDLE_LEDS_COUNT; i++) {
    rgb_matrix_set_color(middleLeds[i], RGB_PINK);
  }

  for(uint8_t i = 0; i < INTERIOR_LEDS_COUNT; i++) {
    rgb_matrix_set_color(interiorLeds[i], RGB_WHITE);
  }

  return rgb_matrix_check_finished_leds(led_max);
}

static bool windows_mode_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for(uint8_t i = 0; i < SIDE_LEDS_COUNT; i++) {
    rgb_matrix_set_color(leftSideLEDs[i], RGB_BLUE);
  }

  for (uint8_t i = 0; i < EXTERIOR_LEDS_COUNT; i++) {
    rgb_matrix_set_color(exteriorLeds[i], RGB_BLUE);
  }

  for(uint8_t i = 0; i < MIDDLE_LEDS_COUNT; i++) {
    rgb_matrix_set_color(middleLeds[i], RGB_PINK);
  }

  for(uint8_t i = 0; i < INTERIOR_LEDS_COUNT; i++) {
    rgb_matrix_set_color(interiorLeds[i], RGB_WHITE);
  }

  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
