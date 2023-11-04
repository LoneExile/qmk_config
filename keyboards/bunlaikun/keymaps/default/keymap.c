#include QMK_KEYBOARD_H
#include "keycodes.h"

#include "features/combo.c"
#include "features/encoder.c"
#include "features/RGB.c"
#include "oled/init.c"

#define THUMB_0 LT(_NUM,KC_SPC)
#define THUMB_1 MO(_NAV)
#define THUMB_2 TD(TD_PLAY_SKIP)
#define THUMB_3 KC_BSPC

enum {
  TD_PLAY_SKIP,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_PLAY_SKIP] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_PLAY_SKIP):
            return TAPPING_TERM + 300;
        default:
            return TAPPING_TERM;
    }
}

// BUG: not working
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            return true;
        default:
            return false;
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(

//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  Q       │  W       │  E       │  R       │  T       │   │  Y       │  U       │  I       │  O       │  P       │
          KC_Q,      KC_W,       KC_E,      KC_R,     KC_T,           KC_Y,      KC_U,     KC_I,       KC_O,     KC_P,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  A       │  S       │  D       │  F       │  G       │   │  H       │  J       │  K       │  L       │  ' "     │
          KC_A, MT(MOD_LCTL,KC_S), MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), KC_G, KC_H, MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), MT(MOD_RCTL,KC_L), KC_QUOT,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  C       │  V       │  B       │   │  N       │  M       │  , <     │  . >     │  CAPS_W  │
          KC_Z,      KC_X,       KC_C,      KC_V,     KC_B,           KC_N,      KC_M,     KC_COMM,    KC_DOT,    CW_TOGG,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
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
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
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
            KC_F10,    KC_F1,     KC_F2,     KC_F3,    KC_NO,          KC_NO,         KC_NO,         KC_NO,        KC_NO,          KC_NO,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────────┴─────────────┴──────────────┴──────────────┴──────────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_MOUSE] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │   X      │  BTN1    │  BTN3    │  BTN2    │   X      │   │   ESC    │   X      │  MOVE_UP │   X      │   X      │
          KC_NO,     KC_BTN1,   KC_BTN3,   KC_BTN2,     KC_NO,         KC_ESC,    KC_NO,     KC_MS_U,   KC_NO,     KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │   X      │   X      │   X      │   X      │   X      │   │   X      │ MOVE_LEFT│ MOVE_DOWN│MOVE_RIGHT│   X      │
          KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │   X      │   X      │   X      │   X      │   X      │   │  WH_L    │  WH_DN   │  WH_UP   │  WH_R    │   X      │
          KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,        KC_WH_L,    KC_WH_D,   KC_WH_U,   KC_WH_R,   KC_NO,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),

    [_RGB] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  RGB_TOG │    X     │  RGB_HUI │  RGB_SAI │   X      │   │  X       │  X       │  X       │  X       │  X       │
          RGB_TOG,    KC_NO,   RGB_HUI,   RGB_SAI,     KC_NO,         KC_NO,    KC_NO,     KC_NO,   KC_NO,     KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  RGB_MOD │  RGB_SAD │  RGB_VAI │  RGB_VAD │  RGB_SAI │   │  X       │  X       │  X       │  X       │  X       │
          RGB_MOD,    RGB_SAD,   RGB_VAI,   RGB_VAD,   RGB_SAI,       KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  RGB_RMOD│    X     │  RGB_SPI │  RGB_SPD │   X      │   │  X       │  X       │  X       │  X       │  X       │
          RGB_RMOD,   KC_NO,     RGB_SPI,   RGB_SPD,   KC_NO,         KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),
    [_NAV] = LAYOUT(
//      ╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//      │  BASE    │   THAI   │  MOUSE   │  MEDIA   │  FN      │   │  REDO    │  PASTE   │  COPY    │  CUT     │  UNDO    │
         TO(_BASE),  KC_NO,    TG(_MOUSE),  KC_NO,   TG(_FN),        KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  LSHIFT  │  LCTRL   │  LALT    │  LMETA   │  NUM     │   │  LEFT    │  DOWN    │    UP    │  RIGHT   │  CAPS    │
          KC_LSFT,    KC_LCTL,   KC_LALT,   KC_LGUI,  TG(_NUM),        KC_LEFT,    KC_DOWN,   KC_UP,    KC_RIGHT,  KC_CAPS,
//      ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//      │  X       │  X       │  X       │  X       │  RGB     │   │  HOME    │  PG_DN   │  PG_UP   │  END     │  INS     │
          KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG(_RGB),        KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,    KC_INS,
//      ╰──────────┴──────────┴──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────┴──────────┴──────────╯
//                                  ╭─────────────┬────────────╮   ╭────────────┬─────────────╮
//                                  │     Space   │  NAV       │   │ PLAY/PAUSE │  Backspace  │
                                         THUMB_0,   THUMB_1,          THUMB_2,     THUMB_3
//                                  ╰─────────────┴────────────╯   ╰────────────┴─────────────╯
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */
        case MT(MOD_LCTL,KC_S):
        case MT(MOD_RCTL,KC_L):
        case KC_LCTL:
        case KC_RCTL:
            // ocean_dream
            // is_calm = (record->event.pressed) ? true : false;
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case LT(_NUM,KC_SPC):
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* KEYBOARD PET STATUS END */

        /* BACKSPACE DELETE START */
        case KC_BSPC:
            {
                // Initialize a boolean variable that keeps track
                // of the delete key status: registered or not?
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (get_mods() & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the boolean variable to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(get_mods());
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
                // Let QMK process the KC_BSPC keycode as usual outside of shift
                return true;
            }
        /* BACKSPACE DELETE END */

        // '('
        case LPRN_SHIFT_RPRN:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    // Clear the shift modifier temporarily
                    uint8_t current_mods = get_mods();
                    clear_mods();
                    tap_code16(S(KC_0)); // Send ')' with Shift
                    // Restore the shift modifier
                    set_mods(current_mods);
                } else {
                    // Add the shift modifier temporarily
                    uint8_t current_mods = get_mods();
                    add_mods(MOD_MASK_SHIFT);
                    tap_code16(S(KC_9)); // Send '(' with Shift
                    // Restore the original modifiers
                    set_mods(current_mods);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            break;

        // '{'
        case LCBR_SHIFT_RCBR:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    // Clear the shift modifier temporarily
                    uint8_t current_mods = get_mods();
                    clear_mods();
                    tap_code16(S(KC_RBRC)); // Send '}' with Shift
                    // Restore the shift modifier
                    set_mods(current_mods);
                } else {
                    // Add the shift modifier temporarily
                    uint8_t current_mods = get_mods();
                    add_mods(MOD_MASK_SHIFT);
                    tap_code16(S(KC_LBRC)); // Send '{' with Shift
                    // Restore the original modifiers
                    set_mods(current_mods);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            break;

        // '['
        case LBRC_SHIFT_RBRC:
            if (record->event.pressed) {
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    uint8_t current_mods = get_mods();
                    // BUG:
                    set_mods(current_mods);
                    clear_mods();
                    tap_code16(KC_RBRC);
                    tap_code16(KC_BSPC);
                    set_mods(current_mods);

                    set_mods(current_mods);
                    clear_mods();
                    tap_code16(KC_RBRC);
                    set_mods(current_mods);

                } else {
                    uint8_t current_mods = get_mods();
                    clear_mods();
                    tap_code16(KC_LBRC);
                    set_mods(current_mods);
                }
                return false;
            }
            break;

      case KC_PSCR:
      if (record->event.pressed) {
        // When the KC_PSCR key is pressed
        tap_code(KC_PSCR); // Send the Print Screen key press
        layer_clear(); // Clear the current layer
        layer_on(_BASE); // Go back to the _BASE layer
      }
      return false;
    }
    return true;
}
