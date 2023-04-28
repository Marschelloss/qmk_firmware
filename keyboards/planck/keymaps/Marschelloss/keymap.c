/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
    _BASED,
    _NUMBER,
    _NAVIGON,
    _FUNCTION
};

enum planck_keycodes {
    NUM = SAFE_RANGE,
    NAV,
    FUN,
    INT_TLD
};

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SHT_F MT(MOD_LSFT, KC_F)

// RIGHT HAND HOME ROW MODS QWERTY ├─────────────────┐

#define SHT_J MT(MOD_RSFT, KC_J)
#define CTL_K MT(MOD_RCTL, KC_K)
#define ALT_L MT(MOD_RALT, KC_L)
#define GUI_S MT(MOD_RGUI, KC_QUOT)

#define NUM LT(_NUMBER, KC_TAB)
#define NAV LT(_NAVIGON, KC_BSPC)
#define FUN MO(_FUNCTION)

#define XXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASED] = LAYOUT_planck_grid(
                KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,   XXX,   XXX,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
                GUI_A,    ALT_S,    CTL_D,    SHT_F,    KC_G,   XXX,   XXX,      KC_H,     SHT_J,    CTL_K,    ALT_L,    GUI_S,
                KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   XXX,   XXX,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                XXX,      XXX,      XXX,      KC_ESC,   KC_SPC, NUM,   NAV,      KC_LSFT,  KC_ENT,   XXX,      XXX,      XXX
),

[_NUMBER] = LAYOUT_planck_grid(
              KC_5,    KC_6,    KC_7,    KC_8,    KC_EQL,  XXX, XXX, _______,  _______,   _______,  _______, _______,
              KC_1,    KC_2,    KC_3,    KC_4,    KC_MINS, XXX, XXX, _______,  KC_RSFT,   KC_RCTL,  KC_RALT, KC_RGUI,
              KC_BSLS, INT_TLD, KC_9,    KC_0,    XXXXXXX, XXX, XXX, _______,  _______,   _______,  _______, _______,
              XXX,     XXX,     XXX,     XXX,     XXX,     XXX, FUN, KC_LSFT,  _______,   _______,  _______, _______
 ),

[_NAVIGON] = LAYOUT_planck_grid(
             _______,  _______,   _______,  _______, DM_REC1, XXX, XXX, KC_MUTE,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,
             KC_LGUI,  KC_LALT,   KC_LCTL,  KC_LSFT, DM_PLY1, XXX, XXX, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, CW_TOGG,
             _______,  _______,   _______,  _______, DM_RSTP, XXX, XXX, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_PSCR,
             _______,  _______,   _______,  _______, _______, FUN, XXX, KC_LSFT,  _______,  _______,  _______,  _______
 ),

[_FUNCTION] = LAYOUT_planck_grid(
              KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX, XXX, XXX, XXXXXXX,  RGB_TOG,  RGB_M_T,  XXXXXXX,  QK_BOOT,
              KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX, XXX, XXX, XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,
              KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX, XXX, XXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
              XXX,      XXX,      XXX,      XXX,      XXX,     XXX, XXX, XXX,      XXX,      XXX,      XXX,      XXX
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case INT_TLD:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
            }
            break;
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMBER, KC_TAB):
            return true;
        case LT(_NAVIGON, KC_BSPC):
            return true;
        default:
            return false;
    }
}
