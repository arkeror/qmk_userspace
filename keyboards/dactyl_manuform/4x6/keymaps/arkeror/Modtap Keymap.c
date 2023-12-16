#include QMK_KEYBOARD_H

//Layer Name to Index
#define _BASE 0
#define _NUM 1
#define _MOD 2
#define _GAME 3

//Layer Swap Keys
#define NUM MO(_NUM)
#define MOD MO(_MOD)
#define GAME TG(_GAME)

//Mod Tap Keys
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J LSFT_T(KC_J)
#define MT_K LCTL_T(KC_K)
#define MT_L LALT_T(KC_L)
#define MT_SCLN LGUI_T(KC_SCLN)
#define MT_GAME MT(GAME, KC_HOME)

//Keycode Shortcuts
#define KC_BAK KC_BACKSPACE

//Macro declaration
enum custom_keycodes {
    LR_Spam = SAFE_RANGE,
    V_Spam,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_TAB,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,               KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_RBRC,                                                KC_MINS, KC_EQL,
                                            MOD,     KC_SPC,             KC_ENT,  NUM,  
                                            KC_LGUI, MT_GAME,            KC_END,  KC_RSFT,
                                            KC_LCTL, KC_LALT,            KC_DEL,  KC_BAK
    ),

    [_NUM] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_1,    KC_2,    KC_3,    KC_4 ,   KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP,
                          KC_NUM, KC_CAPS,                                                 KC_INS, KC_PSCR,
                                            _______, _______,             _______, _______,
                                            _______, _______,             QK_BOOT, _______,
                                            _______, _______,             _______, _______
    ),

    [_MOD] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, LR_Spam,  V_Spam, _______,             _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 DT_DOWN,  DT_UP,
                                            _______, _______,             _______, _______,
                                            _______, QK_BOOT,             _______, _______,
                                            _______, _______,             _______, DT_PRNT
    ),

    [_GAME] = LAYOUT(
        _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                _______, _______, _______, _______,  _______, _______,
        _______, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                _______, _______, _______, _______, _______, _______,
        _______, _______, KC_Z,    KC_X,    KC_C,    KC_V,                _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, KC_SPC,              _______, _______,
                                            _______, GAME,                _______, _______,
                                            _______, _______,             _______, _______
    )
};

//Macro Function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LR_Spam:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LEFT) SS_DELAY(15) SS_TAP(X_RIGHT) SS_DELAY(15) SS_TAP(X_LEFT) SS_DELAY(15) SS_TAP(X_RIGHT) SS_DELAY(15) SS_TAP(X_LEFT) SS_DELAY(15) SS_TAP(X_RIGHT));
        } else {
        }
        break;
    case V_Spam:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_V) SS_DELAY(15) SS_TAP(X_V) SS_DELAY(15) SS_TAP(X_V) SS_DELAY(15) SS_TAP(X_V) SS_DELAY(15) SS_TAP(X_V));
        } else {
        }
        break;
    }
    return true;
};


void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}




