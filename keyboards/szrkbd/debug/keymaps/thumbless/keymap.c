#include QMK_KEYBOARD_H

enum user_macros {
  UM_ANGL = SAFE_RANGE,
  UM_SQUA,
  UM_CURL,
  UM_PARN
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT(
    KC_Q,                 KC_W,                 KC_E,                 KC_R,                 KC_T,
    KC_A,                 LT(1,KC_S),           LT(2,KC_D),           LT(3,KC_F),           KC_G,
    MT(MOD_LSFT,KC_Z),    MT(MOD_LCTL,KC_X),    MT(MOD_LGUI,KC_C),    MT(MOD_LALT,KC_V),    KC_B,
                                                XXXXXXX,              XXXXXXX,              XXXXXXX,

    KC_Y,                 KC_U,                 KC_I,                 KC_O,                 KC_P,
    KC_H,                 LT(1,KC_J),           LT(2,KC_K),           LT(3,KC_L),           KC_SPC,
    KC_N,                 MT(MOD_RALT,KC_M),    MT(MOD_RGUI,KC_COMM), MT(MOD_RCTL,KC_DOT),  KC_RSFT,
    XXXXXXX,              XXXXXXX,              XXXXXXX
  ),


  [1] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,
                      XXXXXXX,  XXXXXXX, XXXXXXX,

    KC_ESC,  KC_7,    KC_8,    KC_9,    XXXXXXX,
    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SPC,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [2] = LAYOUT(
    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU,
    KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN1, KC_VOLD,
    KC_MSEL, KC_MPLY, XXXXXXX, KC_PGDN, MS_BTN2,
                      XXXXXXX,  XXXXXXX, XXXXXXX,

    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
    MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_ENT,
    XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [3] = LAYOUT(
    KC_TAB,  KC_GRV,  KC_PERC, KC_CIRC, KC_AMPR,
    KC_AT,   KC_UNDS, KC_HASH, KC_DLR,  KC_EQL,
    UM_ANGL, UM_SQUA, UM_CURL, UM_PARN, KC_BSLS,
                      XXXXXXX, XXXXXXX, XXXXXXX,

    KC_PIPE, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN,
    KC_DQUO, KC_BSPC, KC_ASTR, KC_QUOT, KC_ENT,
    KC_DEL,  KC_MINS, KC_PLUS, KC_TILD, KC_SLSH,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),


};

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
