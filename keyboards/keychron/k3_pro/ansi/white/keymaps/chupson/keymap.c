/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "print.h"

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  MAC_MOUSE,
  WIN_MOUSE
};

enum custom_keycodes {
    KC_M_MO = NEW_SAFE_RANGE,
    KC_W_MO,
    KC_MACB,
    KC_WINB,
    RST_LED
};

#define CHUPSON_DEF_SPEED 140
#define CHUPSON_DEF_MODE LED_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define CHUPSON_DEF_ENABLED 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_SNAP,  KC_DEL,   BL_TOGG,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,MO(MAC_FN),KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  BL_STEP,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            RST_LED,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_M_MO,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   BL_STEP,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  BL_TOGG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            RST_LED,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_W_MO,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[MAC_MOUSE] = LAYOUT_ansi_84(
     KC_MACB,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  XXXXXXX,  KC_MS_U,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,  KC_WH_L,  KC_WH_U,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX,            XXXXXXX,            RST_LED,
     XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,                                KC_BTN1,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

[WIN_MOUSE] = LAYOUT_ansi_84(
     KC_WINB,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ACL0,  KC_ACL1,  KC_ACL2,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  XXXXXXX,  KC_MS_U,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,  KC_WH_L,  KC_WH_U,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX,            XXXXXXX,            RST_LED,
     XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,                                KC_BTN1,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX)
};


bool chupson_led_enabled = CHUPSON_DEF_ENABLED;
uint16_t chupson_led_mode = CHUPSON_DEF_MODE;
uint16_t chupson_led_speed = CHUPSON_DEF_SPEED;



void chupson_mouse_mode_led(void) {
    chupson_led_enabled = led_matrix_is_enabled();
    chupson_led_mode = led_matrix_get_mode();
    chupson_led_speed = led_matrix_get_speed();

    led_matrix_enable_noeeprom();
    led_matrix_mode_noeeprom(LED_MATRIX_BREATHING);
    led_matrix_set_speed_noeeprom(255);
}


void chupson_normal_mode_led(void) {
    led_matrix_enable();
    led_matrix_mode(chupson_led_mode);
    led_matrix_set_speed(chupson_led_speed);
    led_matrix_disable();
    if (!chupson_led_enabled) {
        led_matrix_disable();
    } else {
        led_matrix_enable();
    }

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MACB:
            if (record->event.pressed) {
                set_single_persistent_default_layer(MAC_BASE);
                chupson_normal_mode_led();
            }
            return false;
        case KC_WINB:
            if (record->event.pressed) {
                set_single_persistent_default_layer(WIN_BASE);
                chupson_normal_mode_led();
            }
            return false;
        case KC_M_MO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(MAC_MOUSE);
                chupson_mouse_mode_led();
            }
            return false;
        case KC_W_MO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(WIN_MOUSE);
                chupson_mouse_mode_led();
            }
            return false;
        case RST_LED:
            if (record->event.pressed) {
                chupson_led_enabled = CHUPSON_DEF_ENABLED;
                chupson_led_mode = CHUPSON_DEF_MODE;
                chupson_led_speed = CHUPSON_DEF_SPEED;
                chupson_normal_mode_led();
            }
            return false;
    }
    return true;
}


void keyboard_post_init_user(void) {
    set_single_persistent_default_layer(MAC_BASE);
    chupson_normal_mode_led();
}

