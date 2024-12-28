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
#include "keymap_us_international.h"
#include "sendstring_us_international.h"
#include "rgb_matrix_map.h"

#include "timer.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


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
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, US_HASH, KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // length 84

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          KC_PWR,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, US_AT,   _______, US_EURO, RGB_VAI, _______, _______, US_UDIA, _______, US_ODIA, _______, _______, _______,                   _______,
        _______, US_ADIA, US_SS,   _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, US_DCIR, _______,          KC_PGUP,
        _______, _______, _______, _______, RGB_HUI, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, KC_PGDN,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

   [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};

typedef struct {
    uint8_t row;
    uint8_t col;
} KeyPosition;
// clang-format on
uint8_t                led_index                      = 0;
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [2] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [3] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
const uint8_t led_location_map_sorted_to_actual[] = {
    [0]  = LED_ESC, // 0, ESC, k13
    [1]  = LED_F1,  // 6, F1, k26
    [2]  = LED_F2,  // 12, F2, k36
    [3]  = LED_F3,  // 18, F3, k31
    [4]  = LED_F4,  // 23, F4, k33
    [5]  = LED_F5,  // 28, F5, k07
    [6]  = LED_F6,  // 34, F6, k63
    [7]  = LED_F7,  // 39, F7, k71
    [8]  = LED_F8,  // 44, F8, k76
    [9]  = LED_F9,  // 50, F9, ka6
    [10] = LED_F10, // 56, F10, ka7
    [11] = LED_F11, // 61, F11, ka3
    [12] = LED_F12, // 66, F12, ka5
    [13] = LED_PRT, // 69, Prt, k97  -- re
    [14] = LED_PRT, // rotary knob

    [15] = LED_GRV,  // 1, ~, k16
    [16] = LED_1,    // 7, 1, k17
    [17] = LED_2,    // 13, 2, k27
    [18] = LED_3,    // 19, 3, k37
    [19] = LED_4,    // 24, 4, k47
    [20] = LED_5,    // 29, 5, k46
    [21] = LED_6,    // 35, 6, k56
    [22] = LED_7,    // 40, 7, k57
    [23] = LED_8,    // 45, 8, k67
    [24] = LED_9,    // 51, 9, k77
    [25] = LED_0,    // 57, 0, k87
    [26] = LED_MINS, // 62, -, k86
    [27] = LED_EQL,  // 78, =, k66
    [28] = LED_BSPC, // 85, BSpc, ka1
    [29] = LED_INS,  // 72, Del, k65

    [30] = LED_TAB,  // 2, Tab, k11
    [31] = LED_Q,    // 8, Q, k10
    [32] = LED_W,    // 14, W, k20
    [33] = LED_E,    // 20, E, k30
    [34] = LED_R,    // 25, R, k40
    [35] = LED_T,    // 30, T, k41
    [36] = LED_Y,    // 36, Y, k51
    [37] = LED_U,    // 41, U, k50
    [38] = LED_I,    // 46, I, k60
    [39] = LED_O,    // 52, O, k70
    [40] = LED_P,    // 58, P, k80
    [41] = LED_LBRC, // 63, [, k81
    [42] = LED_RBRC, // 89, ], k61
    [43] = LED_DEL,  // 75, PgUp, k15 <---

    [44] = LED_CAPS,      // 3, Caps, k21
    [45] = LED_A,         // 9, A, k12
    [46] = LED_S,         // 15, S, k22
    [47] = LED_D,         // 21, D, k32
    [48] = LED_F,         // 26, F, k42
    [49] = LED_G,         // 31, G, k43
    [50] = LED_H,         // 37, H, k53
    [51] = LED_J,         // 42, J, k52
    [52] = LED_K,         // 47, K, k62
    [53] = LED_L,         // 53, L, k72
    [54] = LED_SCLN,      // 59, ;, k82
    [55] = LED_QUOT,      // 64, ", k83
    [56] = LED_RBACKSLSH, // 80, LED, l05 M
    [57] = LED_ENT,       // 96, Enter, ka4
    [58] = LED_HOME,      // 86, PgDn, k25

    [59] = LED_LSFT,  // 4, Sh_L, k00
    [60] = LED_BSLS,  // 93, \, ka2
    [61] = LED_Z,     // 10, Z, k14
    [62] = LED_X,     // 16, X, k24
    [63] = LED_C,     // 22, C, k34
    [64] = LED_V,     // 27, V, k44
    [65] = LED_B,     // 32, B, k45
    [66] = LED_N,     // 38, N, k55
    [67] = LED_M,     // 43, M, k54
    [68] = LED_COMM,  // 48, ,, k64
    [69] = LED_DOT,   // 54, ., k74
    [70] = LED_RSLSH, // 60, ?, k85
    [71] = LED_RSFT,  // 90, Sh_R, k91
    [72] = LED_UP,    // 94, Up, k35
    [73] = LED_END,   // 82, End, k75 <---

    [74] = LED_LCTL,  // 5, Ct_L, k06
    [75] = LED_LWIN,  // 11, Win_L, k90
    [76] = LED_LALT,  // 17, Alt_L, k93
    [77] = LED_SPC,   // 33, SPACE, k94
    [78] = LED_RALT,  // 49, Alt_R, k95
    [79] = LED_FN,    // 55, FN, k92
    [80] = LED_RCTL,  // 65, Ct_R, k04
    [81] = LED_LEFT,  // 95, Left, k03
    [82] = LED_DOWN,  // 97, Down, k73
    [83] = LED_RIGHT, // 79, Right, k05
};

// uint8_t get_mapped_led_index(uint8_t sorted_index) {
//     return led_location_map_sorted_to_actual[sorted_index];
// }

// uint8_t actual_led_index = 0;

// void blink_all_keys(void) {
//     uprintf("%d\n", led_index);

//     actual_led_index = get_mapped_led_index(led_index);
//     led_index++;
//     uprintf("led-id: %d\n", actual_led_index);
// }
bool rgb_matrix_indicators_user(void) {
    for (uint8_t i = 0; i < sizeof(LED_LIST_CUSTOM_KEYCAPS); i++) {
        rgb_matrix_set_color(LED_LIST_CUSTOM_KEYCAPS[i], 50, 255, 0);
    }

    // custom_led_parsing(1, 255, 0, 0); // Setzt alle Tasten im Layer 1 auf Rot

    return false;
}
// for debugging
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_RCTL:
//             if (record->event.pressed) {
//                 blink_all_keys();
//             }
//             return false; // Skip all further processing of this key
//         default:
//             return true; // Process all other keycodes normally
//     }
// }

#ifdef RGB_MATRIX_ENABLE
// caps log flash side bars red, press fn and all mapped keys are highlighted red
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static uint32_t cycle_led_timer    = 0;
    static uint8_t  current_value      = 0;
    static uint8_t  left_side_leds[8]  = {68, 71, 74, 77, 81, 84, 88, 92};
    static uint8_t  right_side_leds[8] = {69, 72, 75, 78, 82, 85, 89, 93};

    if (host_keyboard_led_state().caps_lock) {
        if (timer_elapsed32(cycle_led_timer) > 500) {
            current_value   = current_value == 0 ? 255 : 0;
            cycle_led_timer = timer_read32();
        }

        HSV tempHSV = {.h = 0, .s = 255, .v = current_value};
        RGB tempRGB = hsv_to_rgb(tempHSV);

        for (uint8_t i = 0; i < sizeof(left_side_leds) / sizeof(left_side_leds[0]); i++) {
            rgb_matrix_set_color(left_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
            rgb_matrix_set_color(right_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_CAPS, tempRGB.r, tempRGB.g, tempRGB.b);
        }
    }

    return false;
}
#endif