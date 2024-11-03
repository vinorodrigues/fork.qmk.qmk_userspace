/* (c) 2024 Vino Rodrigues */
/* SPDX-License-Identifier: GPL-3.0-or-later */

#include QMK_KEYBOARD_H
#include <version.h>
#include "vinorodrigues_common.h"
#include "caffeine.h"
#include "konami.h"

enum {
    KC_SIRI = QK_KB_0,
    KC_SCREEN_SHOT,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_CORTANA,
    KC_CAFFEINE,
    KC_SNAPTAP_A,
    KC_SNAPTAP_D,
    // 8
    // 9
    KC_VERSION = QK_KB_10
};

#define KC_VRSN KC_VERSION  // deprecated
#define KC_SNAP KC_SCREEN_SHOT
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_CRTA KC_CORTANA
#define KC_CAFF KC_CAFFEINE
#define KC_SN_A KC_SNAPTAP_A
#define KC_SN_D KC_SNAPTAP_D

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(  // Base
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_SNAP, KC_VOLD, KC_VOLU,  KC_SIRI,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          TG(1),   KC_PSLS, KC_PAST,  KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_HOME, KC_UP,   KC_PGUP,  KC_PPLS,
        KC_CAPS, KC_SN_A, KC_S,    KC_SN_D, KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_LEFT, KC_NO,   KC_RIGHT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,  KC_DOWN, KC_PGDN,  KC_ENT,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT,          MO(2),            KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,   KC_DEL),

    [1] = LAYOUT(  // Mac Numlock
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_P7,   KC_P8,   KC_P9,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_P4,   KC_P5,   KC_P6,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        _______, _______, _______,                   _______,                            _______,          _______,          _______, _______, _______, KC_P0,   KC_PDOT),

    [2] = LAYOUT(  // FN1
        KC_CAFF, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_F13,           KC_F14,  KC_F15,  KC_F16,  KC_F17,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_NUM,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______,
        KC_RSFT, _______, QK_BOOT, EE_CLR,  _______, _______, _______, NK_TOGG, _______, _______, _______,                   KC_LSFT, _______, _______, _______, _______, _______,
        KC_RCTL, KC_RALT, KC_RGUI,                   _______,                            _______,          _______,          _______, _______, _______, _______, _______)
};
// clang-format on

bool is_a_pressed = false;
bool is_d_pressed = false;

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_indicators_caffeine()) return false;
    return true;
}
#endif

bool led_update_user(led_t led_state) {
    if (!led_update_caffeine(led_state)) return false;
    return true;
}

void matrix_scan_user(void) {
    matrix_scan_caffeine();
}

void housekeeping_task_user(void) {
    housekeeping_task_caffeine();
}

// Process keystrokes

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // --- macOS ---

        case KC_SIRI:
            return kc_register_code_2(record, KC_LOPT, KC_SPACE);
            break;

        case KC_SCREEN_SHOT:
           return kc_register_code_3(record, KC_LSFT, KC_LCMD, KC_4);
           break;

        // --- Windows ---

        case KC_TASK_VIEW:
            return kc_register_code_2(record, KC_LWIN, KC_TAB);
            break;

        case KC_FILE_EXPLORER:
             return kc_register_code_2(record, KC_LWIN, KC_E);
             break;

        case KC_CORTANA:
            return kc_register_code_2(record, KC_LWIN, KC_C);
            break;

        // --- Other ---

        case KC_SNAPTAP_A:
            if (record->event.pressed) {
                is_a_pressed = true;
                if (is_d_pressed) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
            } else {
                is_a_pressed = false;
                unregister_code(KC_A);
                if (is_d_pressed) {
                    register_code(KC_D);
                }
            }
            return false; // no more processing

        case KC_SNAPTAP_D:
            if (record->event.pressed) {
                is_d_pressed = true;
                if (is_a_pressed) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
            } else {
                is_d_pressed = false;
                unregister_code(KC_D);
                if (is_a_pressed) {
                    register_code(KC_A);
                }
            }
            return false; // no more processing

        case KC_CAFFEINE:
            return caffeine_process_toggle_keycode(record);
            break;

        case KC_VERSION:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;

        default:
          break;
    }

    bool res = process_record_konami_code(keycode, record);
    return res;
}
