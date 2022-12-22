#include QMK_KEYBOARD_H

enum d34_keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_ALT,
    CT_BSPC
};

#define LT_SPC LT(1, KC_SPC)
#define LT_BSP LT(2, KC_BSPC)
#define CTL_W LCTL(KC_W)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define SFT_TG OSL(6)

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case OS_SFT:
            if (record->event.pressed) {
                set_oneshot_mods(MOD_LSFT);
            }
            return false;
        case OS_CTL:
            if (record->event.pressed) {
                set_oneshot_mods(MOD_LCTL);
            }
            return false;
        case OS_ALT:
            if (record->event.pressed) {
                set_oneshot_mods(MOD_LALT);
            }
            return false;
        default:
            return true;
    }
}

bool
get_auto_shifted_key(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode) {
        case KC_SCLN:
        case KC_SLSH:
        case KC_DOT:
        case KC_COMM:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_BSP:
        case LT_SPC:
            if (record->event.pressed) {
                return TAPPING_TERM;
            } else {
                return TAPPING_TERM + 100;
            }
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM cmb_esc[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {LT_BSP, LT_SPC, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_wspc[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM cmb_atab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_ossh[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_scap[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_oscl[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_osat[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cmb_nav[] = {KC_J, KC_K, KC_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_wspc, SFT_TG),
    COMBO(cmb_atab, A(KC_TAB)),
    COMBO(cmb_ossh, OS_SFT),
    COMBO(cmb_scap, CW_TOGG),
    COMBO(cmb_oscl, OS_CTL),
    COMBO(cmb_osat, OS_ALT),
    COMBO(cmb_nav, TG(8))
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
                                   XXXXXXX, KC_SPC,     KC_BSPC, XXXXXXX
    ),
    [2] = LAYOUT(
        KC_TILD, KC_PLUS, KC_ASTR, KC_PERC, KC_DQUO,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(4),
        KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,    XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,
        XXXXXXX, KC_LT,   KC_GT,   KC_EXLM, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT,
                                   XXXXXXX, KC_SPC,     KC_BSPC, XXXXXXX
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
        XXXXXXX, OSL(7),  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, OSL(7),  XXXXXXX,
        KC_6,    KC_4,    KC_0,    KC_2,    XXXXXXX,    XXXXXXX, KC_3,    KC_1,    KC_5,    KC_7,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    XXXXXXX,    XXXXXXX, KC_9,    XXXXXXX, XXXXXXX, XXXXXXX,
                                   TG(5),   KC_MEH,     KC_MEH, TG(5)
    ),
    [6] = LAYOUT( // like 5 except LALT is added
        XXXXXXX, OSL(6),  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, OSL(6),  XXXXXXX,
        A(KC_6), A(KC_4), A(KC_0), A(KC_2), XXXXXXX,    XXXXXXX, A(KC_3), A(KC_1), A(KC_5), A(KC_7),
        XXXXXXX, XXXXXXX, XXXXXXX, A(KC_8), XXXXXXX,    XXXXXXX, A(KC_9), XXXXXXX, XXXXXXX, XXXXXXX,
                                   TG(5),   KC_MEH,     KC_MEH, TG(5)
    ),
    [7] = LAYOUT(
        XXXXXXX, OSL(7),  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, OSL(7),  XXXXXXX,
        KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,     KC_F11, KC_F3,   KC_F1,   KC_F5,   KC_F7,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_F8,   XXXXXXX,    XXXXXXX, KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX,
                                   TG(7),   KC_MEH,     KC_MEH, TG(7)
    ),
    [8] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   TG(8),   KC_SPC,     KC_BSPC, TG(8)
    )
};
