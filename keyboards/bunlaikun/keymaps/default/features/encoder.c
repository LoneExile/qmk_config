#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // index 0 and 1 are left-half encoders
    // index 2 and 3 are right-half encoders

    uint16_t key;
    if (layer_state_is(_BASE)) {
        key = clockwise ? KC_VOLU : KC_VOLD;
    } else if (layer_state_is(_NAV)) {
        key = clockwise ? KC_WH_U : KC_WH_D;
    } else {
        key = clockwise ? KC_VOLU : KC_VOLD;
        // return false; // Do nothing if no match
    }

    tap_code(key);


    return false;
}
#endif
