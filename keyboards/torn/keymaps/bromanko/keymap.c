#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"
#include "raw_hid.h"
#define RAW_EPSIZE 8

bool led_update_user(led_t led_state) {
    torn_set_led(0, led_state.caps_lock);
    return true;
}

