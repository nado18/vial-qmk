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
