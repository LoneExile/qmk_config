#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#endif

#ifdef MOUSEKEY_ENABLE
     // The default is 100
#    define MOUSEKEY_WHEEL_INTERVAL 50
     // The default is 40
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

// set the default tap toggle to 1
#define ONESHOT_TAP_TOGGLE 1
#define ONESHOT_TIMEOUT 1000

// Turns off the OLED screen after 60000ms
#define OLED_TIMEOUT 0

#define TAPPING_TERM 200

#define SPLIT_WPM_ENABLE

