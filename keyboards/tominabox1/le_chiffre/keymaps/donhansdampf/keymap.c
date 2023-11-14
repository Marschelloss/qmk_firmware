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
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R,  KC_T, KC_NO, KC_Y,    KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F,  KC_G,        KC_H,    KC_J, KC_K, KC_L, SS_QUOT,
        KC_Z, KC_X, KC_C, KC_V,  KC_B,        KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,
                          MO(1), KC_SPC,      KC_LSFT, MO(2)
    ),
	[_NUM] = LAYOUT(
        KC_TRNS,       KC_TRNS,       KC_TAB,        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),          KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
                                      KC_TRNS,       KC_TRNS,                KC_TRNS, KC_TRNS
    ),
	[_NAV] = LAYOUT(
        KC_5,       KC_6,   KC_7,   KC_8,    KC_NO, KC_NO, KC_NO,   KC_LBRC, KC_RBRC, KC_LCBR,    KC_RCBR,
        KC_1,       KC_2,   KC_3,   KC_4,    KC_NO,        KC_NO,   KC_MINS, KC_UNDS, RALT(KC_S), LSFT(KC_QUOT),
        KC_SCLN,    KC_EQL, KC_9,   KC_0,    KC_NO,        KC_NO,   KC_GRV,  KC_COMM, KC_DOT,     KC_BSLS,
                                    KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, KC_NO, KC_NO,   KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,        KC_NO,   OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI),
        KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,        RGB_TOG, RGB_MOD,       RGB_HUI,       RGB_SAI,       RGB_VAI,
                               KC_NO,  QK_BOOT,      KC_LSFT, KC_NO
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
};

const uint16_t PROGMEM combo_esc[]    = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ret[]    = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_RET] = COMBO(combo_ret, KC_ENT)
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
    }

    return true;
}
