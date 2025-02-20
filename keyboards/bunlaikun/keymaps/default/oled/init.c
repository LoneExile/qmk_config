#ifdef OLED_ENABLE

#include "luna.c"
// #include "custom.c"
// #include "demon.c"
#include "crab.c"
// #include "ocean_dream.c"

#define is_master is_keyboard_master()

// oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;
  } else {
    return OLED_ROTATION_270;
  }
  return rotation;

  // ocean_dream
  // return OLED_ROTATION_270;

}

static void print_status_narrow(void) {

  // static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  static const char PROGMEM linux_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfe,
0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x1e, 0x1f, 0x1f, 0x03, 0x01,
0x03, 0x1f, 0x1f, 0x1e, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

  // static const char PROGMEM man_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x90, 0xb8, 0xc8, 0xc0, 0xc0,
  //   0xc0, 0xd0, 0xe0, 0xc0, 0x88, 0x70, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  //   0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xd8, 0xfc, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  //   0xff, 0xff, 0xf3, 0xc1, 0x82, 0x84, 0xc0, 0xff, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  //   0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x20, 0x3f, 0xff, 0xff, 0x93, 0xff, 0xff, 0xff, 0xff,
  //   0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00,
  //   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x09, 0x00, 0x01, 0x03, 0xc3, 0xe7,
  //   0xef, 0xef, 0x47, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


  /* Print current mode */
  oled_set_cursor(0, 0);
  if (keymap_config.swap_lctl_lgui) {
    oled_write_raw_P(mac_logo, sizeof(mac_logo));
  } else {
    oled_write_raw_P(linux_logo, sizeof(linux_logo));
  }

  oled_set_cursor(0, 3);

  switch (get_highest_layer(default_layer_state)) {
    case _BASE:
      oled_write("LINUX", false);
      break;
    default:
      oled_write("UNDEF", false);
  }

  oled_set_cursor(0, 5);

  /* Print current layer */
  oled_write("LAYER", false);

  oled_set_cursor(0, 6);

  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write("Base ", false);
      break;
    case _NUM:
      oled_write("Num.", false);
      break;
    case _FN:
      oled_write("Func", false);
      break;
    case _MOUSE:
      oled_write("Mouse", false);
      break;
    case _RGB:
      oled_write("RGB", false);
      break;
    case _NAV:
      oled_write("Nav  ", false);
      break;
    default:
      oled_write("Undef", false);
  }

  /* caps lock */
  oled_set_cursor(0, 8);
  oled_write("CPSLK", led_usb_state.caps_lock || is_caps_word_on());

  /* KEYBOARD PET RENDER START */

  render_luna(0, 13);

  /* KEYBOARD PET RENDER END */
}

bool oled_task_user(void) {

    /* KEYBOARD PET VARIABLES START */
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    /* KEYBOARD PET VARIABLES END */

    if (is_master) {
        print_status_narrow();
    } else {
        // print_logo_narrow();
        oled_render_anim();
        // render_stars();
    }

    return false;
}
#endif
