enum combos {

// left
  WE_ESC,
  ER_TAB,
  ED_HASH,
  DC_BSLS,
  SD_SFT,
  DF_ENT,

  XC_CP,
  CV_V,
  WS_AT,
  RF_AMP,
  SX_GRV,
  FV_PIPE,
  TG_PERC,
  GB_TILD,

// right
  YH_CIRC,
  HN_UNDS,
  UJ_PLUS,
  JM_MINUS,
  IK_ASTR,
  KCOM_SLSH,
  UI_LCBR,
  IO_RCBR,
  JK_LPRN,
  KL_SFT,
  // TODO: )
  MLEN_LBRC,
  COMDOT_RBRC,
  OL_DLR,
  LDOT_EQL,
  OP_COLN,
  LQU_SCLN,
  PQUOT_EXLM,
  QUC_QUES,


  COMBO_LENGTH
};

enum custom_keycodes {
  LPRN_SHIFT_RPRN = SAFE_RANGE,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// left
const uint16_t PROGMEM ab_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ed_combo[] = {KC_E, MT(MOD_LALT,KC_D), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {MT(MOD_LCTL,KC_S), MT(MOD_LALT,KC_D), COMBO_END};
const uint16_t PROGMEM dc_combo[] = {MT(MOD_LALT,KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), COMBO_END};

const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ws_combo[] = {KC_W, MT(MOD_LCTL,KC_S), COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, MT(MOD_LGUI,KC_F), COMBO_END};
const uint16_t PROGMEM sx_combo[] = {MT(MOD_LCTL,KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {MT(MOD_LGUI,KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};

// right
const uint16_t PROGMEM yh_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM uj_combo[] = {KC_U, MT(MOD_RGUI,KC_J), COMBO_END};
const uint16_t PROGMEM jm_combo[] = {MT(MOD_RGUI,KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, MT(MOD_RALT,KC_K), COMBO_END};
const uint16_t PROGMEM kcom_combo[] = {MT(MOD_RALT,KC_K), KC_COMM, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {MT(MOD_RALT,KC_K), MT(MOD_RCTL,KC_L), COMBO_END};
  // TODO: )
const uint16_t PROGMEM mlen_lbrc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comdot_rbrc_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ol_dlr_combo[] = {KC_O, MT(MOD_RCTL,KC_L), COMBO_END};
const uint16_t PROGMEM ldot_eql_combo[] = {MT(MOD_RCTL,KC_L), KC_DOT, COMBO_END};
const uint16_t PROGMEM op_coln_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM lqu_scln_combo[] = {MT(MOD_RCTL,KC_L), KC_QUOT, COMBO_END};
const uint16_t PROGMEM pquot_exlm_combo[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM quc_ques_combo[] = {KC_QUOT, CW_TOGG, COMBO_END};


combo_t key_combos[] = {

// left
  [WE_ESC]  = COMBO(ab_combo, KC_ESC),
  [ER_TAB]  = COMBO(er_combo, KC_TAB),
  [ED_HASH] = COMBO(ed_combo, KC_HASH),
  [DC_BSLS] = COMBO(dc_combo, KC_BSLS),
  [SD_SFT]  = COMBO(sd_combo, OSM(MOD_LSFT)),

  [DF_ENT]  = COMBO(df_combo, KC_ENT),

  [XC_CP]   = COMBO(xc_combo, LCTL(KC_C)),
  [CV_V]    = COMBO(cv_combo, LCTL(KC_V)),
  [WS_AT]   = COMBO(ws_combo, KC_AT),
  [RF_AMP]  = COMBO(rf_combo, KC_AMPR),
  [SX_GRV]  = COMBO(sx_combo, KC_GRV),
  [FV_PIPE] = COMBO(fv_combo, KC_PIPE),
  [TG_PERC] = COMBO(tg_combo, KC_PERC),
  [GB_TILD] = COMBO(gb_combo, KC_TILD),

// right
    [YH_CIRC]   = COMBO(yh_combo, KC_CIRC),
    [HN_UNDS]   = COMBO(hn_combo, KC_UNDS),
    [UJ_PLUS]   = COMBO(uj_combo, KC_PLUS),
    [JM_MINUS]  = COMBO(jm_combo, KC_MINS),
    [IK_ASTR]   = COMBO(ik_combo, KC_ASTR),
    [KCOM_SLSH] = COMBO(kcom_combo, KC_SLSH),
    [UI_LCBR]   = COMBO(ui_combo, KC_LCBR),
    [IO_RCBR]   = COMBO(io_combo, KC_RCBR),
    [JK_LPRN]   = COMBO(jk_combo, LPRN_SHIFT_RPRN),
    // [JK_LPRN]   = COMBO(jk_combo, KC_LPRN),
    [KL_SFT]   = COMBO(kl_combo, OSM(MOD_RSFT)),
  // TODO: )
    [MLEN_LBRC] = COMBO(mlen_lbrc_combo, KC_LBRC),
    [COMDOT_RBRC] = COMBO(comdot_rbrc_combo, KC_RBRC),
    [OL_DLR] = COMBO(ol_dlr_combo, KC_DLR),
    [LDOT_EQL] = COMBO(ldot_eql_combo, KC_EQL),
    [OP_COLN] = COMBO(op_coln_combo, KC_COLN),
    [LQU_SCLN] = COMBO(lqu_scln_combo, KC_SCLN),
    [PQUOT_EXLM] = COMBO(pquot_exlm_combo, KC_EXLM),
    [QUC_QUES] = COMBO(quc_ques_combo, KC_QUES),

};
