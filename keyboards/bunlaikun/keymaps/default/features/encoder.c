
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 and 1 are left-half encoders
    // 2 and 3 are right-half encoders
    // if (index == 0) {
    //     tap_code(KC_0);
    // } else if (index == 1) {
    //     tap_code(KC_1);
    // } else if (index == 2) {
    //     tap_code(KC_2);
    // } else if (index == 3) {
    //     tap_code(KC_3);
    // }

    if (clockwise) {
        // tap_code16(KC_PLUS);
        tap_code(KC_VOLU);
    } else {
        // tap_code(KC_MINUS);
        tap_code(KC_VOLD);
    }

    return false;
}
#endif
