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
    _BASE,
    _NUM,
    _NAV,
    _SYM
};

enum custom_keycodes {
    SS_QUOT = SAFE_RANGE,
    SS_UE,
    SS_AE,
    SS_OE,
    SS_SZ,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R,  KC_T,       KC_NO, KC_Y,    KC_U, KC_I,    KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F,  KC_G,              KC_H,    KC_J, KC_K,    KC_L,   SS_QUOT,
        KC_Z, KC_X, KC_C, KC_V,  KC_B,              KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,
                          MO(1), KC_SPC,            KC_LSFT, MO(2)
    ),
	[_NUM] = LAYOUT(
        KC_TRNS,       KC_TRNS,       KC_TAB,        KC_TRNS,       KC_TRNS,      KC_NO,   KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,
        OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_TRNS,               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_0,
        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,               KC_9,    KC_5,    KC_6,    KC_7,    KC_8,
                                                     KC_TRNS,       KC_TRNS,               KC_TRNS, KC_TRNS
    ),
	[_NAV] = LAYOUT(
        KC_LBRC,    KC_RBRC,    KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO,   KC_GRV,  KC_TILD, KC_PIPE,    KC_BSLS,
        KC_EQL,     KC_MINS,    KC_SCLN, KC_COLN, KC_NO,        KC_NO,   KC_BSPC, KC_DEL,  RALT(KC_S), LSFT(KC_QUOT),
        KC_PLUS,    KC_UNDS,    KC_LPRN, KC_RPRN, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,
                                         KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, KC_NO, KC_NO,   KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,        KC_NO,   OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI),
        KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,        KC_NO,   KC_NO,         KC_NO,         KC_NO,         KC_NO,
                               KC_NO,  KC_NO,        QK_BOOT, KC_NO
    )
};
// clang-format on

// --- Tri-Layer
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _NUM, _NAV, _SYM);
}

// --- Combos
#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_RET,
    COMBO_ESC,
    COMBO_WINDOW_NXT,
    COMBO_WINDOW_PRV,
    COMBO_UE,
    COMBO_AE,
    COMBO_OE,
    COMBO_SZ,
    COMBO_ALFRED,
    COMBO_PASS,
    COMBO_EMOJI,
};

const uint16_t PROGMEM combo_esc[]    = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ret[]    = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_window_nxt[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_window_prv[]    = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_ue[]    = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ae[]    = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_oe[]    = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM combo_sz[]    = {KC_S, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_alfred[]    = {KC_A, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_pass[]    = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_emoji[]    = {KC_A, KC_D, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_RET] = COMBO(combo_ret, KC_ENT),
    [COMBO_WINDOW_NXT] = COMBO(combo_window_nxt, LGUI(KC_TAB)),
    [COMBO_WINDOW_PRV] = COMBO(combo_window_prv, LGUI(LSFT(KC_TAB))),
    [COMBO_UE] = COMBO(combo_ue, SS_UE),
    [COMBO_AE] = COMBO(combo_ae, SS_AE),
    [COMBO_OE] = COMBO(combo_oe, SS_OE),
    [COMBO_SZ] = COMBO(combo_sz, SS_SZ),
    [COMBO_ALFRED] = COMBO(combo_alfred, LGUI(KC_SPC)),
    [COMBO_PASS] = COMBO(combo_pass, LGUI(LSFT(KC_SPC))),
    [COMBO_EMOJI] = COMBO(combo_emoji, LGUI(LCTL(KC_SPC))),
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
        case SS_UE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'")"u");
            }
            return false;
        case SS_AE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'")"a");
            }
            return false;
        case SS_OE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("'")"o");
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
