enum combos {

// left
  COMBO_ESC,
  COMBO_TAB,
  COMBO_STAB,
  COMBO_HASH,
  COMBO_BSLS,
  COMBO_LSFT,
  COMBO_ENT,

  COMBO_CP,
  COMBO_V,
  COMBO_AT,
  COMBO_AMP,
  COMBO_GRV,
  COMBO_PIPE,
  COMBO_PERC,
  COMBO_TILD,

// right
  COMBO_CIRC,
  COMBO_UNDS,
  COMBO_PLUS,
  COMBO_MINUS,
  COMBO_ASTR,
  COMBO_SLSH,
  COMBO_LCBR,
  COMBO_LPRN,
  COMBO_RSFT,
  COMBO_LBRC,
  COMBO_DLR,
  COMBO_EQL,
  COMBO_COLN,
  COMBO_SCLN,
  COMBO_EXLM,
  COMBO_QUES,


  COMBO_LENGTH
};

enum custom_keycodes {
  LPRN_SHIFT_RPRN = SAFE_RANGE,
  LCBR_SHIFT_RCBR,
  LBRC_SHIFT_RBRC,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// left
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM stab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_E, MT(MOD_LALT,KC_D), COMBO_END};
const uint16_t PROGMEM lsft_combo[] = {MT(MOD_LCTL,KC_S), MT(MOD_LALT,KC_D), COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {MT(MOD_LALT,KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), COMBO_END};

const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM at_combo[] = {KC_W, MT(MOD_LCTL,KC_S), COMBO_END};
const uint16_t PROGMEM ampr_combo[] = {KC_R, MT(MOD_LGUI,KC_F), COMBO_END};
const uint16_t PROGMEM grv_combo[] = {MT(MOD_LCTL,KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {MT(MOD_LGUI,KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {KC_G, KC_B, COMBO_END};

// right
const uint16_t PROGMEM circ_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_U, MT(MOD_RGUI,KC_J), COMBO_END};
const uint16_t PROGMEM mins_combo[] = {MT(MOD_RGUI,KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM astr_combo[] = {KC_I, MT(MOD_RALT,KC_K), COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {MT(MOD_RALT,KC_K), KC_COMM, COMBO_END};
const uint16_t PROGMEM cbr_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM prn_combo[] = {MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {MT(MOD_RALT,KC_K), MT(MOD_RCTL,KC_L), COMBO_END};
const uint16_t PROGMEM brc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM dlr_combo[] = {KC_O, MT(MOD_RCTL,KC_L), COMBO_END};
const uint16_t PROGMEM eql_combo[] = {MT(MOD_RCTL,KC_L), KC_DOT, COMBO_END};
const uint16_t PROGMEM coln_combo[] = {KC_I, KC_O, COMBO_END}; // :
const uint16_t PROGMEM scln_combo[] = {KC_COMM, KC_DOT, COMBO_END};  // ;
const uint16_t PROGMEM exlm_combo[] = {KC_Y, KC_U, COMBO_END};  // !
const uint16_t PROGMEM ques_combo[] = {KC_O, KC_P, COMBO_END}; // ?

combo_t key_combos[] = {

    // left
    [COMBO_ESC]  = COMBO(esc_combo, KC_ESC),
    [COMBO_TAB]  = COMBO(tab_combo, KC_TAB),
    [COMBO_STAB] = COMBO(stab_combo, S(KC_TAB)),
    [COMBO_HASH] = COMBO(hash_combo, KC_HASH),
    [COMBO_BSLS] = COMBO(bsls_combo, KC_BSLS),
    [COMBO_LSFT]  = COMBO(lsft_combo, OSM(MOD_LSFT)),

    [COMBO_ENT]  = COMBO(ent_combo, KC_ENT),

    [COMBO_CP]   = COMBO(copy_combo, LCTL(KC_C)),
    [COMBO_V]    = COMBO(paste_combo, LCTL(KC_V)),
    [COMBO_AT]   = COMBO(at_combo, KC_AT),
    [COMBO_AMP]  = COMBO(ampr_combo, KC_AMPR),
    [COMBO_GRV]  = COMBO(grv_combo, KC_GRV),
    [COMBO_PIPE] = COMBO(pipe_combo, KC_PIPE),
    [COMBO_PERC] = COMBO(perc_combo, KC_PERC),
    [COMBO_TILD] = COMBO(tild_combo, KC_TILD),

    // right
    [COMBO_CIRC]   = COMBO(circ_combo, KC_CIRC),
    [COMBO_UNDS]   = COMBO(unds_combo, KC_UNDS),
    [COMBO_PLUS]   = COMBO(plus_combo, KC_PLUS),
    [COMBO_MINUS]  = COMBO(mins_combo, KC_MINS),
    [COMBO_ASTR]   = COMBO(astr_combo, KC_ASTR),
    [COMBO_SLSH] = COMBO(slsh_combo, KC_SLSH),
    [COMBO_LCBR]   = COMBO(cbr_combo, LCBR_SHIFT_RCBR),
    [COMBO_LPRN]   = COMBO(prn_combo, LPRN_SHIFT_RPRN),
    [COMBO_RSFT]   = COMBO(rsft_combo, OSM(MOD_RSFT)),
    [COMBO_LBRC] = COMBO(brc_combo, LBRC_SHIFT_RBRC),
    [COMBO_DLR] = COMBO(dlr_combo, KC_DLR),
    [COMBO_EQL] = COMBO(eql_combo, KC_EQL),
    [COMBO_COLN] = COMBO(coln_combo, KC_COLN),
    [COMBO_SCLN] = COMBO(scln_combo, KC_SCLN),
    [COMBO_EXLM] = COMBO(exlm_combo, KC_EXLM),
    [COMBO_QUES] = COMBO(ques_combo, KC_QUES),

};
