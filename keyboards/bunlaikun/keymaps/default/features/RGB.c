// #include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  // rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif
