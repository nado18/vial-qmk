#include "user_macros.h"

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
