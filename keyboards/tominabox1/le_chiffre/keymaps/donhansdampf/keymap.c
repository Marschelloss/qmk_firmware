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

enum layers { _BASE, _NUM, _NAV, _SYM };

enum custom_keycodes {
    SS_QUOT = SAFE_RANGE,
    SS_DQT,
    SS_TILD,
    SS_GRV,
    SS_UE,
    SS_AE,
    SS_OE,
    SS_SZ,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,         KC_W,   KC_E,  KC_R,           KC_T,              KC_NO, KC_Y,    KC_U, KC_I,    KC_O,   KC_P,
        KC_A,         KC_S,   KC_D,  KC_F,           KC_G,                     KC_H,    KC_J, KC_K,    KC_L,   KC_BSPC,
        LCTL_T(KC_Z), KC_X,   KC_C,  KC_V,           KC_B,                     KC_N,    KC_M, KC_COMM, KC_DOT, LALT_T(KC_SLSH),
                              MO(1), LGUI_T(KC_SPC),                           KC_LSFT, MO(2)
    ),
	[_NUM] = LAYOUT(
        KC_LBRC,       KC_RBRC,       KC_LCBR,       KC_RCBR,       KC_NUBS,      KC_NO,   KC_PLUS, KC_1,    KC_2,    KC_3,    KC_4,
        KC_LGUI,       KC_LALT,       KC_LCTL,       KC_LSFT,       KC_TILD,               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
        KC_DQT,        KC_QUOT,       KC_LPRN,       KC_RPRN,       KC_GRV,                KC_EQL,  KC_5,    KC_6,    KC_7,    KC_8,
                                                     KC_TRNS,       KC_SPC,                LSFT_T(KC_9), LT(2, KC_0)
    ),
	[_NAV] = LAYOUT(
        KC_MUTE,    KC_MPRV,    KC_MPLY, KC_MNXT,      KC_NO, KC_NO, KC_F11,  KC_F1,   KC_F2,   KC_F3,      KC_F4,
        KC_NO,      KC_NO,      KC_NO,   KC_NO,        KC_NO,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,     KC_DEL,
        KC_NO,      KC_NO,      KC_NO,   KC_NO,        KC_NO,        KC_F12,  KC_F5,   KC_F6,   KC_F7,      KC_F8,
                                         LGUI(KC_SPC), KC_TRNS,      QK_BOOT, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, KC_NO, KC_NO,   KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,        KC_NO,   OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI),
        KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,        KC_NO,   KC_NO,         KC_NO,         KC_NO,         KC_NO,
                               KC_NO,  KC_NO,        QK_BOOT, KC_NO
    )
};
// clang-format on

/* // --- Tri-Layer */
/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _NUM, _NAV, _SYM); */
/* } */

// --- Combos
#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_RET,
    COMBO_ESC,
    COMBO_TAB,
    COMBO_COLO,
    COMBO_SEMI,
    COMBO_QT,
    COMBO_SCREENSHOT,
    COMBO_PASS,
    COMBO_EMOJI,
};

const uint16_t PROGMEM combo_esc[]        = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ret[]        = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_tab[]        = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_colo[]       = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_semi[]       = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_qt[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_screenshot[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_pass[]       = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_emoji[]      = {KC_A, KC_D, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC), [COMBO_RET] = COMBO(combo_ret, KC_ENT), [COMBO_TAB] = COMBO(combo_tab, KC_TAB), [COMBO_COLO] = COMBO(combo_colo, KC_COLN), [COMBO_SEMI] = COMBO(combo_semi, KC_SCLN), [COMBO_QT] = COMBO(combo_qt, SS_QUOT), [COMBO_SCREENSHOT] = COMBO(combo_screenshot, LGUI(LSFT(KC_4))), [COMBO_PASS] = COMBO(combo_pass, LGUI(LSFT(KC_SPC))), [COMBO_EMOJI] = COMBO(combo_emoji, LGUI(LCTL(KC_SPC))),
};
#endif

// --- Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case SS_UE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'") "u");
            }
            return false;
        case SS_AE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'") "a");
            }
            return false;
        case SS_OE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'") "o");
            }
            return false;
        case SS_SZ:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("s"));
            }
            return false;
    }

    return true;
}
