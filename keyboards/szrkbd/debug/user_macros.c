#pragma once

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
	macos = true;
	break;
  default:
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
  if (record->event.pressed) {
	uint8_t row = record->event.key.row;
	uint8_t col = record->event.key.col;
	uprintf("[%c] Key pressed at row %u, col %u\n",
			is_keyboard_master() ? 'm' : 's',
			row, col);

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
  }
  return true;
}
