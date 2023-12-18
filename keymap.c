/*
Copyright 2021 Salicylic_Acid

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,--------------------------------------------------------------|   |--------------------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,        KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,        KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,        KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_LGUI,  KC_UP, KC_LALT, KC_BSPC,  KC_SPC, KC_DEL,      KC_ENT,  KC_ESC,  KC_SPC, KC_RALT,   KC_UP, _______, MO(_FN),
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LEFT, KC_DOWN, KC_RGHT,                                                           KC_LEFT, KC_DOWN, KC_RGHT
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------+--------|   |--------------------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_PSCR, KC_SCRL, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_HOME, KC_PGUP, KC_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG, RGB_MOD, _______, RGB_SAD, RGB_SAI, _______,     _______, _______, _______, KC_END, KC_PGDN, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, RGB_VAD, KC_VOLU, RGB_VAI, RGB_HUD, RGB_HUI, _______,     LSFT(KC_8), LSFT(KC_9), RALT(KC_LBRC), RALT(KC_RBRC), _______, _______, MO(_FN),
  //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_MPRV, KC_VOLD, KC_MNXT,                                                           _______, _______, _______
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'
  )
};

enum rgb_layer_names {
    RGBLAYER_CAPSLOCK = 0,
    RGBLAYER_FN,
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0,  3, HSV_GREEN},     // Light LEDs GRV, 1, 2
    {11,  6, HSV_GREEN},     // Light LEDs TAB, Q, W, CAPS, A, S
    {25,  3, HSV_GREEN},     // Light LEDs LSFT, Z, X
    {28,  2, HSV_GREEN}      // Light LEDs LCLT, LGUI
);

const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1,  6, HSV_CYAN},      // Light LEDs F1, F2, F3, F4, F5, F6
    {22,  2, HSV_PURPLE},    // Light LEDs RGB_SAI, RGB_SAD
    {25,  2, HSV_PURPLE},    // Light LEDs RGB_MOD, RGB_TOG
    {29,  4, HSV_PURPLE},    // Light LEDs RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI
    {34,  4, HSV_CYAN},      // Light LEDs KC_VOLU, KC_MPRV, KC_VOLD, KC_MNXT

    {42,  6, HSV_CYAN},      // Light LEDs PrintScreen, F12, F11, F10, F9, F8, F7
    {53,  4, HSV_CYAN},      // Light LEDs KC_PSCR, KC_SCRL, KB_LBRC, KB_RBRC
    {58,  3, HSV_CYAN},      // Light LEDs KC_QUOT, KC_PGUP, KC_HOME
    {67,  2, HSV_CYAN},      // Light LEDs KC_END, KC_PGDN
    {71,  1, HSV_YELLOW},    // Light LEDs FN
    {73,  4, HSV_CYAN}       // Light LEDs (, ), {, }
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    fn_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(RGBLAYER_CAPSLOCK, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGBLAYER_FN, layer_state_cmp(state, _FN));
    return state;
}

