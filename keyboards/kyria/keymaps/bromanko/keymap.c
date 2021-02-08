#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

#ifdef OLED_DRIVER_ENABLE
#include "oled.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_wpm();
    }
}

#endif


#ifdef RGBLIGHT_ENABLE
#include "rgb.h"

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, MOUR));
    rgblight_set_layer_state(1, layer_state_cmp(state, NAVR));
    rgblight_set_layer_state(2, layer_state_cmp(state, MEDR));
    rgblight_set_layer_state(3, layer_state_cmp(state, NSSL));
    rgblight_set_layer_state(4, layer_state_cmp(state, NSL));
    rgblight_set_layer_state(5, layer_state_cmp(state, FUNL));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(6, led_state.caps_lock);
    return true;
}

#endif
