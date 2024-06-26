#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

#define TAPPING_TERM 220
#define PERMISSIVE_HOLD # Tap preffered
#define PERMISSIVE_HOLD_PER_KEY

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

// COMBO
#define COMBO_COUNT 10

// RGB
#undef RGB_DI_PIN
#define RGB_DI_PIN GP12
#define WS2812_DI_PIN GP12
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 2
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}

// Mouse Keys
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64
