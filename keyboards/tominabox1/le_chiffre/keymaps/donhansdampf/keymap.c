#include QMK_KEYBOARD_H

enum layers {
    _BASED,
    _NUMBER,
    _SYMBOL,
    _MOUSE,
    _GAME,
    _GAMENR,
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

// Hold Taps
#define C_CMD LGUI_T(KC_SPC)
#define C_CTL LCTL_T(KC_Z)
#define C_ALT LALT_T(KC_SLSH)
#define C_SFT LSFT_T(KC_9)

// Layer (Taps)
#define L_NUM MO(_NUMBER)
#define L_SYM LT(_SYMBOL, KC_DQUO)
// #define L_GMN MO(_GAMENR)
// Special 34 Key: 2 Thumb Game Space Combo - Scary!
#define L_GMN LT(_GAMENR, KC_SPC)
#define L_MSE LT(_MOUSE, KC_LCTL)

// Layer Switch
#define GAME TO(_GAME)
#define BASE TO(_BASED)
// Special 34 Key: Mouse Layer activation
#define MOSE TO(_MOUSE)

// Shortcuts
#define C_SPC LGUI(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASED] = LAYOUT(
        KC_TAB,   KC_W,     KC_E,     KC_R,     KC_T,    KC_NO,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,             KC_H,     KC_J,     KC_K,     KC_L,     KC_BSPC,
        C_CTL,    KC_X,     KC_C,     KC_V,     KC_B,             KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_ALT,
                                      L_NUM,    C_CMD,            KC_LSFT,  L_SYM
    ),
    [_NUMBER] = LAYOUT(
        KC_NO,    GAME,     MOSE,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_1,     KC_2,     KC_3,     KC_4,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_MINS,
        KC_PLUS,  KC_EQL,   KC_COMM,  KC_DOT,   KC_NO,            KC_NO,    KC_5,     KC_6,     KC_7,     KC_8,
                                      KC_NO,    KC_NO,            C_SFT,    KC_0
    ),
    [_SYMBOL] = LAYOUT(
        KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_NO,   KC_NO,   KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  SS_TILD,          KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
        KC_BSLS,  KC_PIPE,  KC_LPRN,  KC_RPRN,  SS_GRV,           KC_F13,   KC_F5,    KC_F6,    KC_F7,    KC_F8,
                                      KC_TAB,   KC_SPC,           QK_BOOT,  KC_NO
    ),
    [_MOUSE] = LAYOUT(
        KC_BTN3,  KC_WH_D,  KC_MS_U,  KC_WH_U,  KC_NO,   KC_NO,   KC_NO,    KC_PGDN,  KC_UP,    KC_PGUP,  KC_NO,
        BASE,     KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,            KC_NO,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                      KC_BTN2,  KC_BTN1,          KC_NO,    KC_NO
    ),
    [_GAME] = LAYOUT(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_NO,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,             KC_H,     KC_J,     KC_K,     KC_L,     KC_BSPC,
        KC_LALT,  KC_Z,     KC_X,     KC_C,     KC_V,             KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_ALT,
                                      KC_LSFT,  L_GMN,            BASE,     KC_ENT
    ),
    [_GAMENR] = LAYOUT(
        KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_T,    KC_NO,   KC_TRNS,  KC_PGDN,  KC_UP,    KC_PGUP,  KC_TRNS,
        KC_TRNS,  KC_4,     KC_5,     KC_6,     KC_G,             KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,
        KC_TRNS,  KC_8,     KC_9,     KC_0,     KC_B,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                      KC_TRNS,  KC_NO,            KC_ESC,   KC_TRNS
    ),
    [_EMPTY] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                      KC_NO,    KC_NO,            KC_NO,    KC_NO                              
    )
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

enum combos {
  E_W_Q,
  D_F_ESC,
  J_K_ENT,
  M_COMM_COLN,
  COMM_DOT_SCLN,
  C_V_DQT,
  X_C_QUOT,
};

const uint16_t PROGMEM e_w_q[] = { KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM d_f_esc[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM j_k_ent[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM m_comm_coln[] = { KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_scln[] = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_v_dqt[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM x_c_quot[] = { KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [E_W_Q] = COMBO(e_w_q, KC_Q),
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
        case L_MSE:
            if (record->tap.count && record->event.pressed) {
                // Tap Function
                layer_move(_MOUSE);
            } else if (record->event.pressed) {
                // Hold Function
                register_code(KC_LCTL);
           } else {
                // (Hold) Keyup
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case C_SFT:
            // Immediately select the hold action when another key is tapped.
            return true;
        case L_SYM:
            // Does it also work with custom keycodes?!
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
