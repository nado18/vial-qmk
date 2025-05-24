#include QMK_KEYBOARD_H

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,
    KC_A,    KC_S,    KC_D,     KC_F,    KC_G,
    KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,
                      KC_LCTL,  KC_LWIN, KC_LALT,

    KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,
    KC_H,    KC_J,    KC_K,     KC_L,   KC_SPC,
    KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_RSFT,
    MO(3),   MO(2),   MO(1)
  ),


  [1] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,
                      KC_LCTL, KC_LWIN, KC_LALT,

    KC_ESC,  KC_7,    KC_8,    KC_9,    XXXXXXX,
    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SPC,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_RSFT,
    MO(3),   XXXXXXX, MO(1)
  ),


  [2] = LAYOUT(
    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU,
    KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN1, KC_VOLD,
    KC_MSEL, KC_MPLY, XXXXXXX, KC_PGDN, MS_BTN2,
                      KC_LCTL, KC_LWIN, KC_LALT,

    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
    MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_ENT,
    XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, KC_RSFT,
    MO(3),   XXXXXXX, MO(1)
  ),


  [3] = LAYOUT(
    KC_TAB,  KC_GRV,  KC_PERC, KC_CIRC, KC_AMPR,
    KC_AT,   KC_UNDS, KC_HASH, KC_DLR,  KC_EQL,
    KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_BSLS,
    /*^^^TODO^^^*/    KC_LCTL, KC_LWIN, KC_LALT,

    KC_PIPE, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN,
    KC_DQUO, KC_BSPC, KC_ASTR, KC_QUOT, KC_ENT,
    KC_DEL,  KC_MINS, KC_PLUS, KC_TILD, KC_SLSH,
    XXXXXXX, TO(2),   TO(1)
  ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t row = record->event.key.row;
        uint8_t col = record->event.key.col;
        uprintf(
                "[%c] Key pressed at row %u, col %u\n",
                is_keyboard_master() ? 'm' : 's',
                row,
                col
                );
    }
    return true;
}
