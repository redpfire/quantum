#include QMK_KEYBOARD_H

enum combo_events {
    NUM_LAYER,
    NUM_LAYER_SYM,
    VIM_LAYER,
    VIM_LAYER_SYM,
    KEYLOCK_CAPS,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM numbers_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM numbers_combo_sym[] = {KC_AMPR, KC_CIRC, COMBO_END};
const uint16_t PROGMEM vim_combo[] = {KC_H, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM vim_combo_sym[] = {KC_AMPR, KC_CIRC, KC_TILD, COMBO_END};
const uint16_t PROGMEM keylock_combo[] = {KC_X, KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    [NUM_LAYER] = COMBO(numbers_combo, TO(3)),
    [NUM_LAYER_SYM] = COMBO(numbers_combo_sym, TO(3)),
    [VIM_LAYER] = COMBO(vim_combo_sym, TO(4)),
    [VIM_LAYER_SYM] = COMBO(vim_combo, TO(4)),
    [KEYLOCK_CAPS] = COMBO(keylock_combo, KC_CAPS),
};

enum custom_keycodes {
    VIM_CW = SAFE_RANGE,
    VIM_FMT,
    VIM_QAE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_MINS,
                 LALT_T(KC_A), RALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,
                 KC_M, LCTL_T(KC_N), LSFT_T(KC_E), RALT_T(KC_I), LALT_T(KC_O),
                 KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT,
                 KC_SLSH, LGUI_T(KC_ESC), LT(2, KC_SPC), KC_TAB, KC_BSPC,
                 KC_ENT, TO(1)),
    [1] = LAYOUT(KC_AT, KC_LT, KC_DLR, KC_GT, KC_GRV, KC_PERC, KC_LBRC, KC_UNDS,
                 KC_RBRC, KC_SCLN, KC_BSLS, KC_LPRN, KC_DQUO, KC_RPRN, KC_HASH,
                 KC_EXLM, KC_LCBR, KC_EQL, KC_RCBR, KC_PIPE, KC_NO, KC_COLN,
                 KC_QUOT, KC_ASTR, KC_PLUS, KC_QUES, KC_AMPR, KC_CIRC, KC_TILD,
                 KC_SLSH, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
    [2] = LAYOUT(KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_PGDN, KC_UP,
                 KC_PGUP, KC_DEL, LALT_T(KC_MPRV), KC_MPLY, LSFT_T(KC_MSTP),
                 LCTL_T(KC_MNXT), KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,
                 KC_END, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT(KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_PPLS, KC_7, KC_8,
                 KC_9, KC_PSLS, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_0, KC_4,
                 KC_5, KC_6, KC_DOT, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_PMNS,
                 KC_1, KC_2, KC_3, KC_PAST, TO(0), TO(1), KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_NO),
    [4] = LAYOUT(KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 VIM_QAE, KC_LALT, KC_4, LSFT_T(KC_5), LCTL_T(KC_6), KC_0, KC_H,
                 KC_J, KC_K, KC_L, VIM_CW, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, VIM_FMT, TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_NO)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)  return true;

    switch (keycode) {
        case VIM_CW:
            SEND_STRING(":w\n");
            break;

        case VIM_QAE:
            SEND_STRING(":qa!\n");
            break;

        case VIM_FMT:
            SEND_STRING(":silent lua vim.lsp.buf.formatting()\n");
            break;
    }

    return true;
};
