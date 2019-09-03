#include "../../config.h"

#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef TAPPING_TOGGLE

// Utilisé pour un fonctionnement plus fluide de cmd+tab 
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#permissive-hold
#define PERMISSIVE_HOLD

// #define MOUSEKEY_INTERVAL       10
// #define MOUSEKEY_DELAY          100
// #define MOUSEKEY_TIME_TO_MAX    1
// #define MOUSEKEY_MAX_SPEED      7

// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #undef MOUSEKEY_WHEEL_TIME_TO_MAX
// #undef MOUSEKEY_WHEEL_DELAY

// #define MOUSEKEY_WHEEL_MAX_SPEED    5
// #define MOUSEKEY_WHEEL_TIME_TO_MAX  60
// #define MOUSEKEY_WHEEL_DELAY        100


#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_TIME_TO_MAX    6
#define MOUSEKEY_MAX_SPEED      7

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_WHEEL_MAX_SPEED    5
#define MOUSEKEY_WHEEL_TIME_TO_MAX  60
#define MOUSEKEY_WHEEL_DELAY        100
#define TAPPING_TOGGLE 2




// #define RGBLIGHT_COLOR_LAYER_0 0x3B, 0xB0, 0x90
#define RGBLIGHT_COLOR_LAYER_0 46, 37, 62
#define RGBLIGHT_COLOR_LAYER_1 0xE0, 0x66, 0x6A
#define RGBLIGHT_COLOR_LAYER_2 0xFF, 0x00, 0x00 
#define RGBLIGHT_COLOR_LAYER_3 0xF0, 0xA1, 0x66 
#define RGBLIGHT_COLOR_LAYER_4 0x63, 0xB0, 0xE0 