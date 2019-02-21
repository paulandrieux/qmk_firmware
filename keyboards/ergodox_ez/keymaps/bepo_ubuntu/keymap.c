
#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "action_layer.h"
#include "ergodox_ez.h"

// The layers that we are defining for this keyboards.
#define BASE 0
#define FN 1
#define MOUSE 2
#define NUMS 3
#define SWAP 4


// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

#define M_RSFT    MT(MOD_RSFT, BP_M)    // 'M' key and right SHIFT modifier.
#define W_RCTL    MT(KC_LGUI, BP_W)    // 'W' key and right control modifier.
#define SPC_RALT  MT(MOD_RALT, KC_SPC)  // SPACE key and right alt modifier.
#define ENT_CMD  MT(MOD_RCTL, KC_ENT)  // enter key and cmd modifier.
#define ENT_SWAP  MT(MO(SWAP), KC_ENT)  // enter key and cmd modifier.
#define SPC_CMD  MT(MOD_RCTL, KC_SPC)  // SPACE key and cmd modifier.

#define BSPC_CMD  MT(MOD_RCTL , KC_BSPC)  // BACKSPACE key and cmd modifier.
#define TAB_MEH  MT(MEH_T(KC_NO), KC_TAB)  // TAB key and MEH modifier.
#define LOCK (KC_Q | QK_LGUI | QK_LCTL) // Lock screen cmd+ctrl+q

#define MK_SAVE   MT(MO(NUMS), LCTL(BP_S))  // cmd + s
#define MK_COPY   MT(MO(MOUSE), LCTL(BP_C))  // cmd + c
#define MK_CUT   LCTL(BP_X)  // cmd + c
#define MK_PASTE  LCTL(BP_V)  // cmd + v
#define MK_UNDO   LCTL(BP_Z)  // cmd + z
#define MK_REFRESH   LCTL(BP_R)  // cmd + r

enum {
  TD_COPY_CUT = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_COPY_CUT]  = ACTION_TAP_DANCE_DOUBLE(MK_COPY, MK_CUT)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: basic keys.
  [BASE] = KEYMAP(
    /* left hand */
    KC_ESC,   BP_AMPERSAND, BP_DQOT, BP_SLASH, BP_BACKSLASH, KC_UNDERSCORE, KC_LEFT,
    KC_TAB,   BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, KC_ESC,
    KC_LSFT,  BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM,
    KC_LGUI, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    ALL_T(KC_NO),
    MK_UNDO,   MK_REFRESH, MK_SAVE, MK_PASTE, MT(MO(FN), TD(TD_COPY_CUT)),
                                                                KC_LALT, KC_MNXT,
                                                                         KC_MPRV,
                                                  SPC_CMD, ENT_SWAP, KC_MPLY,
    /* right hand */
        KC_RIGHT,     BP_UNDS,     BP_ASTR,  BP_MINS,  BP_DQOT, BP_EURO, LOCK,
        KC_ESC,       BP_DCRC, BP_V,     BP_D,     BP_L,          BP_J,    BP_Z,
                      BP_C,    BP_T,     BP_S,     BP_R,          BP_N,    M_RSFT,
        MEH_T(KC_NO), BP_APOS, BP_Q,     BP_G,     BP_H,          BP_F,    W_RCTL,
                               MO(FN) ,  MO(MOUSE), MO(NUMS),     BP_CCED, KC_LALT,
    KC_LEFT, KC_RIGHT,
    KC_UP,
    KC_DOWN, TAB_MEH, BSPC_CMD),

  // Layer 1: function and media keys.
  [FN] = KEYMAP(
    /* left hand */
    ___, BP_GRAVE, BP_PIPE,            BP_LESS, BP_GREATER, BP_PLUS,    ___,
    ___, BP_EXCLAIM,    BP_AT,              BP_LCBR, BP_RCBR,    BP_EQUAL,      ___,
    ___, BP_HASH,       BP_DOLLAR,          BP_LPRN, BP_RPRN,    BP_MINS,
    ___, BP_PERCENT,    BP_DEAD_CIRCUMFLEX, BP_LBRC, BP_RBRC,    BP_DEAD_TILDE, ___,
    ___,     ___,   ___,    ___,     ___,
                                                     ___, KC_VOLU,
                                                          KC_VOLD,
                                             ___, KC_DEL, KC_MUTE,
    /* right hand */
        ___, ___, ___,   ___,   ___,    ___,  ___,
        ___, ___,   KC_HOME, KC_UP,   KC_END,   KC_PGUP, ___,
             ___,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, ___,
        ___, ___,   ___,     ___,     ___,      ___,     ___,
                    ___,     ___,     ___,      ___,     ___,
    KC_HOME, KC_END,
    KC_PGUP,
    KC_PGDN, ___,    ___),
    // Note that any change to the FN layer above must be added to
    // the MOUSE layer below (except for the arrow keys).

  // Layer 2: Mouse control.
  [MOUSE] = KEYMAP(
    /* left hand */
    ___,     ___, ___,       ___,     ___,    ___,    ___,
    ___,     ___,   ___,     KC_MS_U, ___,  ___,      ___,
    KC_ACL1, ___,   KC_MS_L, KC_MS_D, KC_MS_R,  ___,
    ___,     ___,   ___,     ___,     ___, ___, ___,
    ___,     ___,   ___,     ___,     ___,
                                                  ___, ___,
                                                       ___,
                                             ___, ___, ___,
    /* right hand */
         ___, ___, ___,   ___,   ___,   ___, ___,
         ___, ___,   KC_BTN1, KC_WH_U, KC_BTN2, ___,    ___,
              ___,   KC_WH_L, KC_WH_D, KC_WH_R, ___,    KC_ACL2,
         ___, ___,   ___, ___, ___, ___,    ___,
                     ___, ___, ___, ___,    ___,
    ___, ___,
    ___,
    ___, ___, ___),

  // Layer 3: Numeric keypad and system keys.
  [NUMS] = KEYMAP(
    /* left hand */
    ___, ___, ___,    ___,     ___,      ___, ___,
    ___,     KC_F1,    KC_F2,        KC_F3,     KC_F4,      KC_F5, ___,
    ___,     KC_F6,    KC_F7,        KC_F8,     KC_F9,      KC_F10,
    ___,     KC_F11,    KC_F12,     ___, ___, ___, ___,
    ___,     ___,    ___,        ___,     ___,
                                              ___, ___,
                                                   ___,
                                         ___, ___, ___,
    /* right hand */
         ___,     ___,     ___,   ___,   ___,     ___,     ___,
         ___,     KC_PEQL, KC_P7, KC_P8, KC_P9,   ___, ___,
                  KC_PCMM, KC_P4, KC_P5, KC_P6,   ___, ___,
         KC_PENT, KC_P0,   KC_P1, KC_P2, KC_P3,   ___, ___,
                           ___,   ___,   ___,     ___, ___,
    ___, ___,
    ___,
    ___, ___, ___),

  // Layer 5: hand swap, all keys are mirrored to the other side of the keyboard
  // except for the layer toggle itself (so there is no right arrow when this
  // layer is activated).
  [SWAP] = KEYMAP(  
    /* left hand */
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___,
                             ___, ___,
                                       ___,
                             ___, TT(SWAP), ___,
    /* right hand */
         ___, ___, ___, ___, ___, ___, ___,
         ___, ___, ___, ___, ___, ___, ___,
              ___, ___, ___, ___, ___, ___,
         ___, ___, ___, ___, ___, ___, ___,
                   ___, ___, ___, ___, ___,
    ___, ___,
    ___,
    ___, TT(SWAP),      ___),

};

// static uint32_t current_layer_state = 0;
// uint32_t layer_state_set_user(uint32_t state);
// // Whether the given layer (one of the constant defined at the top) is active.
// #define LAYER_ON(layer) (current_layer_state & (1<<layer))

// Runs whenever there is a layer state change.

// void matrix_scan_user(void) {

//   // swap_hands = LAYER_ON(SWAP);

//   ergodox_board_led_off();
//   ergodox_right_led_1_off();
//   ergodox_right_led_2_off();
//   ergodox_right_led_3_off();

//   uint8_t layer = biton32(layer_state);
//   switch (layer) {
//       case 0:
//         #ifdef RGBLIGHT_COLOR_LAYER_0
//           rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
//         #else
//           rgblight_init();
//         #endif
//         break;
//       case 1:
//         ergodox_right_led_1_on();
//         #ifdef RGBLIGHT_COLOR_LAYER_1
//           rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
//         #endif
//         break;
//       case 2:
//         ergodox_right_led_2_on();
//         #ifdef RGBLIGHT_COLOR_LAYER_2
//           rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
//         #endif
//         break;
//       case 3:
//         ergodox_right_led_3_on();
//         #ifdef RGBLIGHT_COLOR_LAYER_3
//           rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
//         #endif
//         break;
//       case 4:
//         ergodox_right_led_1_on();
//         ergodox_right_led_2_on();
//         #ifdef RGBLIGHT_COLOR_LAYER_4
//           rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
//         #endif
//         break;
//       default:
//         break;
//     }

// };

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
