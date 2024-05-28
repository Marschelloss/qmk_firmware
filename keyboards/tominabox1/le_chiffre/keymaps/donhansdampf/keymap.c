/* Copyright 2023 donhansdampf
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _BASED,
    _NUMBER,
    _SYSTEM,
    _MOUSE
};

enum custom_keycodes {
    NUM = SAFE_RANGE,
    SYM,
    SS_QUOT,
    SS_DQT,
    SS_TILD,
    SS_GRV,
    RATE_4,
    RATE_5
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASED] = LAYOUT(
                KC_Q,            KC_W,     KC_E,        KC_R,                   KC_T,             KC_NO,  KC_Y,     KC_U,                 KC_I,     KC_O,     KC_P,
                KC_A,            KC_S,     KC_D,        KC_F,                   KC_G,                     KC_H,     KC_J,                 KC_K,     KC_L,     KC_BSPC,
                CTL_T(KC_Z),     KC_X,     KC_C,        KC_V,                   KC_B,                     KC_N,     KC_M,                 KC_COMM,  KC_DOT,   ALT_T(KC_SLSH),
                                                        MO(_NUMBER),            LGUI_T(KC_SPC),           KC_LSFT,  LT(_SYSTEM, KC_DQUO)
    ),
    [_NUMBER] = LAYOUT(
                KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,    KC_NO,  KC_DOT,       KC_1,         KC_2,      KC_3,     KC_4,
                KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, DF(_MOUSE),         KC_LEFT,      KC_DOWN,      KC_UP,     KC_RIGHT, KC_MINS,
                KC_PLUS, KC_EQL,  KC_LPRN, KC_RPRN, SS_GRV,             KC_COMM,      KC_5,         KC_6,      KC_7,     KC_8,
                                           KC_NO,   KC_NO,              LSFT_T(KC_9), KC_0
    ),
    [_SYSTEM] = LAYOUT(
             KC_MUTE,   KC_MPRV,    KC_MPLY,   KC_MNXT,       KC_NO,     KC_NO, KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,
             KC_LGUI,   KC_LALT,    KC_LCTL,   KC_LSFT,       DF(_MOUSE),       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
             DM_REC1,   DM_REC2,    DM_PLY1,   DM_PLY2,       DM_RSTP,          KC_F12,   KC_F5,    KC_F6,    KC_F7,    KC_F8,
                                               LGUI(KC_SPC),  KC_TAB,           QK_BOOT,  KC_NO
    ),
    [_MOUSE] = LAYOUT(
                DF(_BASED), KC_WH_D,   KC_MS_U,   KC_WH_U,   KC_NO,       KC_NO, KC_NO,   KC_PGUP,   KC_UP,     KC_PGDN,    KC_NO,
                KC_NO,      KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_NO,              RATE_5,  KC_LEFT,   KC_DOWN,   KC_RIGHT,   RATE_4,
                KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_NO,   KC_NO,     KC_NO,     KC_NO,      KC_NO,
                                                  KC_BTN2,   KC_BTN1,            KC_BTN2, KC_BTN1
    )
};
// clang-format on

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

enum combos {
  D_F_ESC,
  J_K_ENT,
  M_COMM_COLN,
  COMM_DOT_SCLN,
  C_V_TAB,
  X_C_QUOT,

};

const uint16_t PROGMEM d_f_esc[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM j_k_ent[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM m_comm_coln[] = { KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_scln[] = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_v_tab[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM x_c_quot[] = { KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [D_F_ESC] = COMBO(d_f_esc, KC_ESC),
  [J_K_ENT] = COMBO(j_k_ent, KC_ENT),
  [M_COMM_COLN] = COMBO(m_comm_coln, KC_COLN),
  [COMM_DOT_SCLN] = COMBO(comm_dot_scln, KC_SCLN),
  [C_V_TAB] = COMBO(c_v_tab, KC_TAB),
  [X_C_QUOT] = COMBO(x_c_quot, SS_QUOT),

};

// --- Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RATE_4:
        if (record->event.pressed) {
            SEND_STRING("r4");
        }
        break;
    case RATE_5:
        if (record->event.pressed) {
            SEND_STRING("r5");
        }
        break;
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
    case LT(_SYSTEM, KC_DQUO):
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
    case LSFT_T(KC_9):
        // Immediately select the hold action when another key is tapped.
        return true;
    default:
        // Do not select the hold action when another key is tapped.
        return false;
    }
}
