/* Copyright 2022
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


enum layers {
    _BASE = 0,
    _NUM = 1,
    _FN = 2,
    _MOUSE = 3,
    _NAV = 4,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(

//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  Q       │  W       │  E       │  R       │  T       │   │  Y       │  U       │  I       │  O       │  P       │
          KC_Q,      KC_W,       KC_E,      KC_R,     KC_T,           KC_Y,      KC_U,     KC_I,       KC_O,     KC_P,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  A       │  S       │  D       │  F       │  G       │   │  H       │  J       │  K       │  L       │  ' "     │
          KC_A, MT(MOD_LCTL,KC_S), MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), KC_G, KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_QUOT,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  C       │  V       │  B       │   │  N       │  M       │  , <     │  . >     │  CAPS_W  │
          KC_Z,      KC_X,       KC_C,      KC_V,     KC_B,           KC_N,      KC_M,     KC_COMM,    KC_DOT,    CW_TOGG,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                          KC_SPC,       KC_ESC,      KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_NUM] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  X       │  X       │  X       │  X       │  X       │   │     *    │    7     │     8    │     9    │    -     │
           KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,         KC_ASTR,    KC_7,     KC_8,      KC_9,     KC_MINS,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  LSHIFT  │  LCTRL   │  LALT    │  LMETA   │  X       │   │     /    │    4     │     5    │     6    │    +     │
          KC_LSFT,   KC_LCTL,   KC_LALT,    KC_LGUI,  KC_NO,         KC_SLSH,    KC_4,     KC_5,      KC_6,     KC_PLUS,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  X       │  X       │  X       │   │     0    │    1     │     2    │     3    │    .     │
          KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,         KC_0,       KC_1,     KC_2,      KC_3,     KC_DOT,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                        KC_SPC,      KC_ESC,          KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_FN] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────────┬─────────────┬──────────────┬──────────────┬──────────────╮
//      │   F12    │    F7    │    F8    │    F9    │  PSCRN   │   │     x        │     x       │      x       │     x        │      x       │
            KC_F12,    KC_F7,     KC_F8,     KC_F9,    KC_PSCR,        KC_NO,         KC_NO,         KC_NO,        KC_NO,          KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────────┼─────────────┼──────────────┼──────────────┼──────────────┤
//      │   F11    │    F4    │    F5    │    F6    │  NUMLOCK │   │     x        │    RMETA    │    RALT      │     RCTRL    │   RSHIFT     │
            KC_F11,    KC_F4,     KC_F5,     KC_F6,    KC_NUM,         KC_NO,         KC_RGUI,      KC_RALT,      KC_RCTL,       KC_RSFT,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────────┼─────────────┼──────────────┼──────────────┼──────────────┤
//      │   F10    │    F1    │    F2    │    F3    │    x     │   │     x        │     x       │      x       │     x        │      x       │
            KC_F10,    KC_F1,     KC_F2,     KC_F3,    KC_NO,          KC_NO,         KC_NO          KC_NO,        KC_NO,          KC_NO,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────────┴─────────────┴──────────────┴──────────────┴──────────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                        KC_SPC,      KC_ESC,          KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_MOUSE] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │   X      │  BTN1    │  BTN2    │  BTN3    │   X      │   │   ESC    │   X      │  MOVE_UP │   X      │   X      │
          KC_NO,     KC_BTN1,   KC_BTN2,   KC_BTN3,     KC_NO,         KC_ESC,    KC_NO,     KC_MS_U,   KC_NO,     KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │   X      │   X      │   X      │   X      │   X      │   │   X      │ MOVE_LEFT│ MOVE_DOWN│MOVE_RIGHT│   X      │
          KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │   X      │   X      │   X      │   X      │   X      │   │  WH_L    │  WH_DN   │  WH_UP   │  WH_R    │   X      │
          KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,        KC_WH_L,    KC_WH_D,   KC_WH_U,   KC_WH_R,   KC_NO,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                        KC_SPC,      KC_ESC,          KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_NAV] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  BASE    │   THAI   │  MOUSE   │  MEDIA   │  FN      │   │  REDO    │  PASTE   │  COPY    │  CUT     │  UNDO    │
          KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  LSHIFT  │  LCTRL   │  LALT    │  LMETA   │  NUM     │   │  LEFT    │  DOWN    │    UP    │  RIGHT   │  CAPS    │
          KC_LSFT,    KC_LCTL,   KC_LALT,   KC_LGUI,   KC_NO,        KC_LEFT,    KC_DOWN,   KC_UP,    KC_RIGHT,  KC_CAPS,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  X       │  X       │    X     │   │  HOME    │  PG_DN   │  PG_UP   │  END     │  INS     │
          KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,    KC_INS,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  Esc       │   │  Enter     │  Backspace  │
                                        KC_SPC,      KC_ESC,          KC_ENT,      KC_BSPC
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  // rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 and 1 are left-half encoders
    // 2 and 3 are right-half encoders
    if (index == 0) {
        tap_code(KC_0);
    } else if (index == 1) {
        tap_code(KC_1);
    } else if (index == 2) {
        tap_code(KC_2);
    } else if (index == 3) {
        tap_code(KC_3);
    }

    if (clockwise) {
        tap_code16(KC_PLUS);
    } else {
        tap_code(KC_MINUS);
    }

    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif
