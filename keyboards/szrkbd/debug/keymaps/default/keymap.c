#include QMK_KEYBOARD_H

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(

    /* Left */
    KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,
    KC_A,    KC_S,    KC_D,     KC_F,    KC_G,
    KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,
                      KC_LCTL,  KC_LWIN, KC_LALT,

    /* Right */
    KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,
    KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,
    KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLASH,
    KC_RALT, KC_RWIN, KC_RCTL

  )
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
