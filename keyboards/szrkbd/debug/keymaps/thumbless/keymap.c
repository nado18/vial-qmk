#include QMK_KEYBOARD_H
#include "user_macros.c"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT(
    KC_Q,                 KC_W,                 KC_E,                 KC_R,                 KC_T,
    LT(4,KC_A),           LT(1,KC_S),           LT(2,KC_D),           LT(3,KC_F),           KC_G,
    MT(MOD_LSFT,KC_Z),    MT(MOD_LCTL,KC_X),    MT(MOD_LGUI,KC_C),    MT(MOD_LALT,KC_V),    KC_B,
                                                XXXXXXX,              XXXXXXX,              XXXXXXX,

    KC_Y,                 KC_U,                 KC_I,                 KC_O,                 KC_P,
    KC_H,                 LT(3,KC_J),           LT(2,KC_K),           LT(1,KC_L),           LT(4,KC_SPC),
    KC_N,                 MT(MOD_RALT,KC_M),    MT(MOD_RGUI,KC_COMM), MT(MOD_RCTL,KC_DOT),  KC_RSFT,
    XXXXXXX,              XXXXXXX,              XXXXXXX
  ),


  [1] = LAYOUT(
    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU,
    KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN1, KC_VOLD,
    KC_MSEL, KC_MPLY, XXXXXXX, KC_PGDN, MS_BTN2,
                      XXXXXXX, XXXXXXX, XXXXXXX,

    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
    MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_ENT,
    XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),


  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   DM_RSTP,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   DM_PLY1,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,
                      XXXXXXX, XXXXXXX, XXXXXXX,

    KC_ESC,  KC_7,    KC_8,    KC_9,    DM_REC1,
    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SPC,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_RSFT,
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


  [4] = LAYOUT(
    FR_ETRM, FR_ECIR, FR_EACU, FR_EGRA, XXXXXXX,
    FR_AGRA, FR_ACIR, FR_UCIR, FR_UGRA, XXXXXXX,
    FR_ITRM, FR_ICIR, FR_CCED, FR_OCIR, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),


};

bool rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color_all(0, 0, 0);

	const int max = 64;
	static int index = 0;
	static int count = 0;

    rgb_matrix_set_color(index+0, max, 0, 0);
    rgb_matrix_set_color(index+1, 0, max, 0);
    rgb_matrix_set_color(index+2, 0, 0, max);

	if( 0 == count++ % 20 ) {
	  index = (index + 1) % 18;
	}

    rgb_matrix_update_pwm_buffers();
    return false;
}