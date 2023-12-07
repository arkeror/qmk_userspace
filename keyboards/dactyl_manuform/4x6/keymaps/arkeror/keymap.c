#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUM 1
#define _MOD 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define KC_CTL KC_LEFT_CTRL
#define KC_WIN KC_LEFT_GUI
#define KC_ALT KC_LEFT_ALT
#define KC_BAK KC_BACKSPACE

#define NUM MO(_NUM)
#define MOD MO(_MOD)

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
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_RBRC,                                                KC_MINS, KC_EQL,
                                            MOD,     KC_SPC,             KC_ENT,  NUM,  
                                            KC_WIN,  KC_HOME,            KC_END,  KC_RSFT,
                                            KC_CTL,  KC_ALT,             KC_DEL,  KC_BAK
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
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______,  _______,
                                            _______, _______,             _______, _______,
                                            _______, QK_BOOT,             _______, _______,
                                            _______, _______,             _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
