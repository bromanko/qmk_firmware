#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"
#include "oled.h"

#ifdef OLED_DRIVER_ENABLE

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

const rgblight_segment_t PROGMEM mour_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM navr_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_CORAL}
);
const rgblight_segment_t PROGMEM medr_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_GOLD}
);
const rgblight_segment_t PROGMEM nssl_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_TEAL}
);
const rgblight_segment_t PROGMEM nsl_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM funl_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM caps_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mour_rgb_layer, // 0
    navr_rgb_layer, // 1
    medr_rgb_layer, // 2
    nssl_rgb_layer, // 3
    nsl_rgb_layer,  // 4
    funl_rgb_layer, // 5
    caps_rgb_layer  // 6
);

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
