#include QMK_KEYBOARD_H

enum d34_keycodes {
    SFT_TG = SAFE_RANGE,
};

#define LT_SPC LT(1, KC_SPC)
#define LT_BSP LT(2, KC_BSPC)
#define CTL_W LCTL(KC_W)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case SFT_TG:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(OSM(X_LALT)));
                SEND_STRING(SS_TAP(OSL(5)));
            }
            return false;
            break;
        default:
            return true;
    }
}

const uint16_t PROGMEM cmb_esc[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_wspc[] = {KC_N, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_wspc, SFT_TG)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    [tmp] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    )
    */
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   TT(5),   LT_SPC,     LT_BSP,  TT(5)
    ),
    [1] = LAYOUT(
        TG(3),   CTL_W,   XXXXXXX, XXXXXXX, XXXXXXX,    KC_QUOT, KC_HASH, XXXXXXX, KC_AT,   XXXXXXX,
        KC_RGUI, KC_LSFT, KC_LCTL, KC_LALT, XXXXXXX,    KC_GRV,  KC_UNDS, KC_LPRN, KC_RPRN, XXXXXXX,
        CTL_Z,   CTL_X,   CTL_C,   CTL_V,   XXXXXXX,    KC_EQL,  KC_AMPR, KC_LBRC, KC_RBRC, XXXXXXX,
                                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [2] = LAYOUT(
        KC_TILD, KC_PLUS, KC_ASTR, KC_PERC, KC_DQUO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(4),
        KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,    XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,
        XXXXXXX, KC_LT,   KC_GT,   KC_EXLM, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT,
                                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [3] = LAYOUT(
        TG(3),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(4),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [5] = LAYOUT(
        XXXXXXX, OSL(6),  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, OSL(6),  XXXXXXX,
        KC_6,    KC_4,    KC_0,    KC_2,    XXXXXXX,    XXXXXXX, KC_3,    KC_1,    KC_5,    KC_7,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    XXXXXXX,    XXXXXXX, KC_9,    XXXXXXX, XXXXXXX, XXXXXXX,
                                   TG(5),   KC_MEH,     KC_MEH, TG(5)
    )
};
