#include QMK_KEYBOARD_H

enum {
    d34_base, d34_lmod
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [d34_base] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R,  KC_T,       KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F,  KC_G,       KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V,  KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                          KC_P0, DB_TOGG,    KC_P2, KC_P3
    ),
    [d34_lmod] = LAYOUT(
    )
};
