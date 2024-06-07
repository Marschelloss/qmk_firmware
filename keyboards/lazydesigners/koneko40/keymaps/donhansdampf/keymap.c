#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_NO,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_NO,    KC_H,     KC_J,     KC_K,     KC_L,     KC_BSPC,
        KC_LALT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
        KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SPC,   QK_BOOT,  KC_LSFT,  KC_NO,    KC_NO,    KC_NO,    KC_ENT
    ),
    [9] = LAYOUT_ortho(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    )
};

