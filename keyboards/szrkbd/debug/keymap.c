#include QMK_KEYBOARD_H

enum user_macros {
  UM_ANGL = SAFE_RANGE,
  UM_SQUA,
  UM_CURL,
  UM_PARN,

  FR_ETRM, FR_ECIR, FR_EACU, FR_EGRA, // ë ê é è
  FR_AGRA, FR_ACIR, FR_UCIR, FR_UGRA, // à â û ù
  FR_ITRM, FR_ICIR, FR_CCED, FR_OCIR  // ï î ç ô
};

bool macos = false;
bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
	return false;
  }

  switch (detected_os) {
  case OS_MACOS:
  case OS_IOS:
	uprintf(">> OS Detection: macOS or iOS\n");
	macos = true;
	break;
  default:
	uprintf(">> OS Detection: NOT macOS or iOS\n");
	break;
  }
  return true;
}

bool send_french_macos(uint16_t keycode) {
  switch(keycode) {

  case FR_ETRM: // ë
    register_code(KC_LGUI);
    tap_code(KC_U);
    unregister_code(KC_LGUI);
    tap_code(KC_E);
    return false;

  case FR_ECIR: // ê
    register_code(KC_LGUI);
    tap_code(KC_I);
    unregister_code(KC_LGUI);
    tap_code(KC_E);
    return false;

  case FR_EACU: // é
    register_code(KC_LGUI);
    tap_code(KC_E);
    unregister_code(KC_LGUI);
    tap_code(KC_E);
    return false;

  case FR_EGRA: // è
    register_code(KC_LGUI);
    tap_code(KC_GRAVE);
    unregister_code(KC_LGUI);
    tap_code(KC_E);
    return false;

  case FR_AGRA: // à
    register_code(KC_LGUI);
    tap_code(KC_GRAVE);
    unregister_code(KC_LGUI);
    tap_code(KC_A);
    return false;

  case FR_ACIR: // â
    register_code(KC_LGUI);
    tap_code(KC_I);
    unregister_code(KC_LGUI);
    tap_code(KC_A);
    return false;

  case FR_UCIR: // û
    register_code(KC_LGUI);
    tap_code(KC_I);
    unregister_code(KC_LGUI);
    tap_code(KC_U);
    return false;

  case FR_UGRA: // ù
    register_code(KC_LGUI);
    tap_code(KC_GRAVE);
    unregister_code(KC_LGUI);
    tap_code(KC_U);
    return false;

  case FR_ITRM: // ï
    register_code(KC_LGUI);
    tap_code(KC_U);
    unregister_code(KC_LGUI);
    tap_code(KC_I);
    return false;

  case FR_ICIR: // î
    register_code(KC_LGUI);
    tap_code(KC_I);
    unregister_code(KC_LGUI);
    tap_code(KC_I);
    return false;

  case FR_CCED: // ç
    register_code(KC_LGUI);
    tap_code(KC_C);
    unregister_code(KC_LGUI);
    return false;

  case FR_OCIR: // ô
    register_code(KC_LGUI);
    tap_code(KC_I);
    unregister_code(KC_LGUI);
    tap_code(KC_O);
    return false;

  }

  return true;
}

bool send_french_windows(uint16_t keycode) {
  switch(keycode) {

  case FR_ETRM: // ë
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P5);
    unregister_code(KC_LALT);
    return false;

  case FR_ECIR: // ê
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P4);
    unregister_code(KC_LALT);
    return false;

  case FR_EACU: // é
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P3);
    unregister_code(KC_LALT);
    return false;

  case FR_EGRA: // è
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P2);
    unregister_code(KC_LALT);
    return false;

  case FR_AGRA: // à
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P2);
    tap_code(KC_P4);
    unregister_code(KC_LALT);
    return false;

  case FR_ACIR: // â
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P2);
    tap_code(KC_P6);
    unregister_code(KC_LALT);
    return false;

  case FR_UCIR: // û
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P5);
    tap_code(KC_P1);
    unregister_code(KC_LALT);
    return false;

  case FR_UGRA: // ù
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P4);
    tap_code(KC_P9);
    unregister_code(KC_LALT);
    return false;

  case FR_ITRM: // ï
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P9);
    unregister_code(KC_LALT);
    return false;

  case FR_ICIR: // î
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P8);
    unregister_code(KC_LALT);
    return false;

  case FR_CCED: // ç
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P3);
    tap_code(KC_P1);
    unregister_code(KC_LALT);
    return false;

  case FR_OCIR: // ô
    register_code(KC_LALT);
    tap_code(KC_P0);
    tap_code(KC_P2);
    tap_code(KC_P4);
    tap_code(KC_P4);
    unregister_code(KC_LALT);
    return false;

  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t row = record->event.key.row;
  uint8_t col = record->event.key.col;
  uprintf("[%c] Key pressed at row %u, col %u\n",
		  is_keyboard_master() ? 'm' : 's',
		  row, col);

  if (record->event.pressed) {

	switch(keycode) {
	case UM_ANGL:
	  SEND_STRING("<>");
	  tap_code(KC_LEFT);
	  return false;
	case UM_SQUA:
	  SEND_STRING("[]");
	  tap_code(KC_LEFT);
	  return false;
	case UM_CURL:
	  SEND_STRING("{}");
	  tap_code(KC_LEFT);
	  return false;
	case UM_PARN:
	  SEND_STRING("()");
	  tap_code(KC_LEFT);
	  return false;
	}

	if( macos && !send_french_macos(keycode) ) {
	  return false;
	}

	if( !macos && !send_french_windows(keycode) ) {
	  return false;
	}
  }

  return true;
}

#define LAYOUT_split_3x5_3( \
    L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24, R20, R21, R22, R23, R24, \
              L30, L31, L32, R30, R31, R32 \
) \
{ \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { R30, R31, R32 } \
}

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT_split_3x5_3(
    KC_Q,                 KC_W,                 KC_E,                 KC_R,                 KC_T,                                    KC_Y,                 KC_U,                 KC_I,                 KC_O,                 KC_P,
    LT(4,KC_A),           LT(1,KC_S),           LT(2,KC_D),           LT(3,KC_F),           KC_G,                                    KC_H,                 LT(3,KC_J),           LT(2,KC_K),           LT(1,KC_L),           LT(4,KC_SPC),
    MT(MOD_LSFT,KC_Z),    MT(MOD_LCTL,KC_X),    MT(MOD_LGUI,KC_C),    MT(MOD_LALT,KC_V),    KC_B,                                    KC_N,                 MT(MOD_RALT,KC_M),    MT(MOD_RGUI,KC_COMM), MT(MOD_RCTL,KC_DOT),  KC_RSFT,
                                                XXXXXXX,              XXXXXXX,              XXXXXXX,                                 XXXXXXX,              XXXXXXX,              XXXXXXX
  ),


  [1] = LAYOUT_split_3x5_3(
    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU,          MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
    KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN1, KC_VOLD,          MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_ENT,
    KC_MSEL, KC_MPLY, XXXXXXX, KC_PGDN, MS_BTN2,          XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, KC_RSFT,
                      XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [2] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   DM_RSTP,          KC_ESC,  KC_7,    KC_8,    KC_9,    DM_REC1,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   DM_PLY1,          KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SPC,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          KC_0,    KC_1,    KC_2,    KC_3,    KC_RSFT,
                      XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [3] = LAYOUT_split_3x5_3(
    KC_TAB,  KC_GRV,  KC_PERC, KC_CIRC, KC_AMPR,          KC_PIPE, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN,
    KC_AT,   KC_UNDS, KC_HASH, KC_DLR,  KC_EQL,           KC_DQUO, KC_BSPC, KC_ASTR, KC_QUOT, KC_ENT,
    UM_ANGL, UM_SQUA, UM_CURL, UM_PARN, KC_BSLS,          KC_DEL,  KC_MINS, KC_PLUS, KC_TILD, KC_SLSH,
                      XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [4] = LAYOUT_split_3x5_3(
    FR_ETRM, FR_ECIR, FR_EACU, FR_EGRA, RM_TOGG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    FR_AGRA, FR_ACIR, FR_UCIR, FR_UGRA, RM_NEXT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    FR_ITRM, FR_ICIR, FR_CCED, FR_OCIR, QK_BOOT,          QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),


};
