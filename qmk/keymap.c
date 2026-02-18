// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "config.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _DVORAK 0
#define _SYMBOL_1 1
#define _SYMBOL_2 2
#define _FUNC_1 3
#define _FUNC_2 4

enum ferris_tap_dances {
  TD_Q_ESC
};

enum combo_events {
  RIGHT_THUMB,
  LEFT_THUMB,
};

// 两个拇指键 combo
const uint16_t PROGMEM right_thumb_combo[] = {KC_SPC, MO(_SYMBOL_1), COMBO_END};
const uint16_t PROGMEM left_thumb_combo[] = {MO(_FUNC_1), KC_LSFT, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [RIGHT_THUMB] = COMBO_ACTION(right_thumb_combo),
  [LEFT_THUMB] = COMBO_ACTION(left_thumb_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*

 | ;  | ,  | .  | P | Y |       | F | G | C | R | L |
 | A  | O  | E  | U | I |       | D | H | T | N | S |
 | '  | Q  | J  | K | X |       | B | M | W | V | Z |
           | FUN | SHIFT | | SPACE | SYMBOL |
  */
  [_DVORAK] = LAYOUT( /* Programmer Dvorak */
    KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,            KC_F,    KC_G,  KC_C,    KC_R,   KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,            KC_D,    KC_H,  KC_T,    KC_N,   KC_S,
    KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,            KC_B,    KC_M,  KC_W,    KC_V,   KC_Z,
                                  MO(_FUNC_1), KC_LSFT, KC_SPC, MO(_SYMBOL_1)
  ),

  /*

 | & | [ | { | } | ( |       | = | ) | * | ] | + |
 | 9 | 7 | 5 | 3 | 1 |       | 0 | 2 | 4 | 6 | 8 |
 | $ | _ | ! | ~ | ` |       | ? | / | @ | - | \ |
             |   | CMD |    |   |   |
  */
  [_SYMBOL_1] = LAYOUT(
    KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN,        KC_EQL,  KC_RPRN, KC_ASTR, KC_RBRC, KC_PLUS,
    KC_9,    KC_7,    KC_5,    KC_3,    KC_1,            KC_0,    KC_2,    KC_4,    KC_6,    KC_8,
    KC_DLR,  KC_UNDS, KC_EXLM, KC_TILD, KC_GRV,         KC_QUES, KC_SLSH, KC_AT,   KC_MINS, KC_BSLS,
                                    _______, KC_LCMD, _______, _______
  ),
  
  /*

 | % | ^ | | | # |   |       |   |   |   |   |   |
 |   |   |   |   |   |       |   |   |   |   |   |
 |   |   |   |   |   |       |   |   |   |   |   |
             |   |   |       |   |   |
  */
  [_SYMBOL_2] = LAYOUT(
    KC_PERC, KC_CIRC, KC_PIPE, KC_HASH, _______,         _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                    _______, _______, _______, _______
  ),

  /*
  
 | ESC |   |   |   |   |           |   |   |   |   |   |
 | TAB |   |   |   |   |           | h | j | k | l |   |
 | CAP |   |   |   |   |       |   |   |   |   |   |
      |   |   |           | BSPC | ENTER |
  */
  [_FUNC_1] = LAYOUT(
    KC_ESC,  _______, LCMD(S(KC_3)), LCMD(S(KC_4)), LCMD(S(KC_5)),         LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), _______,
    KC_TAB,  LCMD(KC_S), _______, _______, _______,         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    KC_CAPS, LCMD(KC_X), LCMD(KC_C), LCMD(KC_V), LCMD(KC_Z),         LCMD(KC_SPC), _______, _______, _______, _______,
                                    _______, _______, KC_BSPC, KC_ENT
  ),

  /*
  
 | F1 | F2 | F3 | F4 | F5 |           | F6 | F7 | F8 | F9 | F10 |
 |   |   |   |   |   |           |   |   |   |   |   |
 | F11 | F12 |   |   |   |           |   |   |   |   |   |
             |   |   |           |   |   |
  */
  [_FUNC_2] = LAYOUT( /* [> RAISE <] */
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,
    LOPT(S(KC_A)), LOPT(S(KC_S)), LOPT(S(KC_D)), LOPT(S(KC_F)), LOPT(S(KC_I)),         LOPT(S(KC_H)), LOPT(S(KC_J)), LOPT(S(KC_K)), LOPT(S(KC_L)), _______,
    KC_F11 , KC_F12 , _______, _______, _______,         LOPT(S(LCTL(KC_H))), LOPT(S(LCTL(KC_J))), LOPT(S(LCTL(KC_K))), LOPT(S(LCTL(KC_L))), _______,
                                    _______, _______, LCMD(KC_BSPC), _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case RIGHT_THUMB:
      if (pressed) {
        layer_invert(_SYMBOL_2);
      }
      break;
    case LEFT_THUMB:
      if (pressed) {
        layer_invert(_FUNC_2);
      }
      break;
  }
}