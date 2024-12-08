/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _MAC = 0,
    _Windows = 1,
    _Functions = 2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Home || Mute |
     * |=============================================================================================================|
     * | ISO  |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] } |        || PgUp |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+       ++------|
     * |  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  | ISO| Enter || PgDn |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * | LShift | ISO |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || End  |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  Ctrl  |   LAlt  |  Cmd   |               Space                  | RAlt |  Fn  | Ctrl || Left | Down | Rght |
     * `-------------------------------------------------------------------------------------------------------------'
     */

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

    // MAC layout
    [_MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Windows layout
    [_Windows] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // FN layer
    [_Functions] = LAYOUT(
        _______, KC_BRMD, KC_BRMU, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   DF(0),   DF(1), QK_BOOT,          _______,
        _______, _______, _______, _______,  EE_CLR, _______, _______, RM_TOGG, RM_HUEU, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, RM_SATU, RM_VALD, RM_VALU, RM_SATD, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RM_NEXT, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RM_SPDD, RM_PREV, RM_SPDU
    ),


};
// clang-format on

// RGB LED layout

// led index number, function of the key
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

const int SIDELEDSCOUNT = 8;

int leftSideLEDs[] = { 68, 71, 74, 77, 81, 84, 88, 92 };
int rightSideLEDs[] = { 69, 72, 75, 78, 82, 85, 89, 93 };

bool isCapsLedOff = false;

static uint16_t recording_timer;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        if(timer_elapsed(recording_timer) >= 500) {
            isCapsLedOff = !isCapsLedOff;
            recording_timer = timer_read();
        }

        if(isCapsLedOff) {
            rgb_matrix_set_color(3, RGB_BLACK);

            for (int i = 0; i < SIDELEDSCOUNT; i++) {
                rgb_matrix_set_color(leftSideLEDs[i], RGB_BLACK);
            }
            for (int i = 0; i < SIDELEDSCOUNT; i++) {
                rgb_matrix_set_color(rightSideLEDs[i], RGB_BLACK);
            }
        }
    }

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        switch (layer) {
        case _Functions:
            // Set Media control colors
            rgb_matrix_set_color(34, RGB_RED); // F6. "Prev Track"
            rgb_matrix_set_color(39, RGB_BLUE); // F7. "Play/Pause"
            rgb_matrix_set_color(44, RGB_RED); // F8. "Next track"

            // Set Windows/Mac Keyboard Toggle colors
            rgb_matrix_set_color(62, RGB_BLUE); // 1 "Windows Layout"
            rgb_matrix_set_color(79, RGB_RED); // 2 "Mac Layout"

            // Set Hue, Saturation, and Value keys
            rgb_matrix_set_color(41, RGB_PURPLE); // U. "Toggle"
            rgb_matrix_set_color(46, RGB_CYAN); // I. "Cycle hue"
            rgb_matrix_set_color(37, RGB_GREEN); // H. "Saturation Increase"
            rgb_matrix_set_color(42, RGB_TURQUOISE); // J "Brightness Decrease"
            rgb_matrix_set_color(47, RGB_BLACK); // K. "Brightness Increase"
            rgb_matrix_set_color(53, RGB_WHITE); // L. "Saturation Decrease"
            break;
        default:
            break;
        }
    }

    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    switch (layer) {
    case _MAC:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_mac_mode_effect);
        break;
    case _Windows:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_windows_mode_effect);
        break;
    default: //  for any other layers, or the default layer
        break;
    }

  return state;
}
