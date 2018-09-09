
#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

// The layers that we are defining for this keyboards.
#define BASE 0
#define FN 1
#define MOUSE 2
#define NUMS 3


// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT


#define CMD MOD_LGUI // rename mac cmd key

#define M_RSFT    MT(MOD_RSFT, BP_M)    // 'M' key and right SHIFT modifier.
#define W_RCTL    MT(MOD_RCTL, BP_W)    // 'W' key and right control modifier.
#define SPC_RALT  MT(MOD_RALT, KC_SPC)  // SPACE key and right alt modifier.
#define ENT_CMD  MT(CMD, KC_ENT)  // enter key and cmd modifier.
#define SPC_CMD  MT(CMD, KC_SPC)  // SPACE key and cmd modifier.

#define BSPC_CMD  MT(CMD , KC_BSPC)  // BACKSPACE key and cmd modifier.
#define TAB_MEH  MT(MEH_T(KC_NO), KC_TAB)  // TAB key and MEH modifier.
#define LOCK (KC_Q | QK_LGUI | QK_LCTL) // Lock screen cmd+ctrl+q

#define MK_SAVE   LGUI(BP_S)  // cmd + s
#define MK_COPY   LGUI(BP_C)  // cmd + c
#define MK_PASTE  LGUI(BP_V)  // cmd + v
#define MK_UNDO   LGUI(BP_Z)  // cmd + z
#define MK_REFRESH   LGUI(BP_R)  // cmd + r

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: basic keys.
  [BASE] = KEYMAP(
    /* left hand */
    KC_ESC,   BP_AMPERSAND, BP_DQOT, BP_SLASH, BP_BACKSLASH, KC_UNDERSCORE, KC_LEFT,
    KC_TAB,   BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, KC_ESC,
    KC_LSFT,  BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM,
    KC_LCTRL, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    ALL_T(KC_NO),
    MK_UNDO,   MK_REFRESH, MK_SAVE, MK_PASTE, MK_COPY,
                                                                KC_LALT, KC_MNXT,
                                                                         KC_MPRV,
                                                  SPC_CMD, ENT_CMD, KC_MPLY,
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
    ___,     ___,    ___,        ___,     ___,      ___, ___,
    ___,     ___,    ___,        ___,     ___,      ___,
    ___,     ___,    ___,     ___, ___, ___, ___,
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

};