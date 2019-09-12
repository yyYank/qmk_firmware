#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _META 1
#define _SYMB 2
#define _RAISE 3
#define _RGB  4

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  META,
  SYMB,
  RAISE,
  TAP_ANIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |  -   |   |  =   |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  | RAISE|   | RAISE|   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |      |      |      |      |      |      |      |   | Bspc |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl |   [  |   ]  | LAlt | LGUI | LGUI |Space |   |Enter | RGUI | RGUI |  RAISE|  RGB |  \  |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_BASE] = LAYOUT( \
    KC_ESC,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_MINS,                                                  KC_EQL,    KC_Y,             KC_U,    KC_I,     KC_O,     KC_P,     KC_JYEN, \
    KC_TAB,  KC_A,KC_S,KC_D,KC_F,KC_G,S(KC_9),                                                S(KC_0),    KC_H,             KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT, KC_Z,KC_X,KC_C,KC_V,KC_B,RAISE,                                             LT(_RAISE, KC_BSPC), KC_N,             KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  SFT_T(KC_RO), \
    KC_LCTRL, KC_LBRC,KC_RBRC,KC_LALT, KC_LGUI, KC_LGUI, LT(_META, KC_SPC),                      LT(_SYMB, KC_ENT),    KC_RGUI, KC_RGUI, KC_RGUI,  RAISE, TG(_RGB), KC_JYEN \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  |  [   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  ^   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |  `   |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  META|   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |Reset |=>RAISE|=>RGB |  \   |
   * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_META] = LAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    _______, _______, KC_7,    KC_8,    KC_9,  KC_0,    KC_MINS, KC_EQL, \
    KC_GRV, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, KC_BSLS, \
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  SFT_T(KC_RO), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |   ~  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>RAISE|=>RGB |  \   |
   * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_SYMB] = LAYOUT( \
    S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______, _______, S(KC_7), S(KC_8), S(KC_9),    S(KC_0),   S(KC_MINS), S(KC_EQL), \
    S(KC_GRV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   S(KC_SCLN), S(KC_BSLS), \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______ \
  ),

  /* RAISE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   <  |   >  |   ?  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>RAISE|=>RGB |  \   |
   * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,  KC_F6,     KC_RBRC,       KC_BSLS, KC_F7,   KC_F8,    KC_F9,     KC_F10,    KC_P,    KC_LBRC, \
    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,      S(KC_8),       S(KC_9), KC_7,   KC_8,    KC_9,     KC_0,    KC_SCLN, KC_QUOT, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,    _______,   _______,    _______ \
  ),

  /* RGB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | TOG  | HUI  | SAI  | VAI  |HUANIM|      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | MOD  | HUD  | SAD  | VAD  |RESET |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |=>RGB |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [_RGB] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, TAP_ANIM,XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAD, RGB_VAD, RGB_RST, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX \
  )

};

bool isTapAnim = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      if (record->event.pressed) {
        isTapAnim = false;
      }
      break;
    case META:
      if (record->event.pressed) {
        layer_on(_META);
        update_tri_layer(_META, _SYMB, _RAISE);
      } else {
        layer_off(_META);
        update_tri_layer(_META, _SYMB, _RAISE);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_META, _SYMB, _RAISE);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_META, _SYMB, _RAISE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
    case TG(_META):
      if (record->event.pressed) {
        isTapAnim = !isTapAnim;
      }
      break;
  }

  if (isTapAnim) {
    rgblight_mode_noeeprom(1);
    uint16_t hue = (rgblight_config.hue + 5) % 360;
    rgblight_sethsv_noeeprom(hue, rgblight_config.sat, rgblight_config.val);
  }

  return true;
}
