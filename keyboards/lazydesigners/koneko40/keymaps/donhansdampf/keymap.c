#include QMK_KEYBOARD_H

enum layers {
    _BASED,
    _NUMBER,
    _SYMBOL,
    _MOUSE,
    _EMPTY
};

enum custom_keycodes {
    NUM = SAFE_RANGE,
    SYM,
    SS_QUOT,
    SS_DQT,
    SS_TILD,
    SS_GRV,
    SS_DEAD,
};

#define C_CMD LGUI_T(KC_SPC)
#define C_CTL LCTL_T(KC_Z)
#define C_ALT LALT_T(KC_SLSH)
#define C_SFT LSFT_T(KC_9)

#define C_SPC LGUI(KC_SPC)

#define L_NUM MO(_NUMBER)
#define L_SYM LT(_SYMBOL, KC_DQUO)
#define L_MSE DF(_MOUSE)
#define L_BSE DF(_BASED)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASED] = LAYOUT_ortho(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_NO,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_NO,    KC_H,     KC_J,     KC_K,     KC_L,     KC_BSPC,
        KC_LALT,  C_CTL,    KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_ALT,
        KC_ESC,   KC_NO,    KC_NO,    KC_NO,    L_NUM,    C_CMD,    KC_NO,    KC_LSFT,  L_SYM,    KC_NO,    KC_NO,    KC_NO
    ),
    [_NUMBER] = LAYOUT_ortho(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_1,     KC_2,     KC_3,     KC_4,
        KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_MINS,
        KC_NO,    KC_PLUS,  KC_EQL,   KC_DOT,   KC_COMM,  KC_NO,    KC_NO,    KC_NO,    KC_5,     KC_6,     KC_7,     KC_8,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    C_SFT,    KC_0,     KC_NO,    KC_NO,    KC_NO
    ),
    [_SYMBOL] = LAYOUT_ortho(
        KC_NO,    KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_NO,    KC_NO,    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,
        KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,
        KC_NO,    KC_BSLS,  KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_NO,    KC_NO,    KC_F12,   KC_F5,    KC_F6,    KC_F7,    KC_F8,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TAB,   C_SPC,    KC_NO,    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),
    [_EMPTY] = LAYOUT_ortho(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    )
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

enum combos {
  D_F_ESC,
  J_K_ENT,
  M_COMM_COLN,
  COMM_DOT_SCLN,
  C_V_DQT,
  X_C_QUOT,
};

const uint16_t PROGMEM d_f_esc[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM j_k_ent[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM m_comm_coln[] = { KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_scln[] = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_v_dqt[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM x_c_quot[] = { KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [D_F_ESC] = COMBO(d_f_esc, KC_ESC),
  [J_K_ENT] = COMBO(j_k_ent, KC_ENT),
  [M_COMM_COLN] = COMBO(m_comm_coln, KC_COLN),
  [COMM_DOT_SCLN] = COMBO(comm_dot_scln, KC_SCLN),
  [C_V_DQT] = COMBO(c_v_dqt, SS_DQT),
  [X_C_QUOT] = COMBO(x_c_quot, SS_QUOT),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_DEAD:
            if (record->event.pressed) {
                tap_code16(KC_DQUO);
            }
            return false;
        case SS_QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
            }
            return false;
        case SS_DQT:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'") SS_TAP(X_SPC));
            }
            return false;
        case SS_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
            }
            return false;
        case SS_TILD:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("`") SS_TAP(X_SPC));
            }
            return false;
        case L_SYM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                return false;
            }
            break;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case C_SFT:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
