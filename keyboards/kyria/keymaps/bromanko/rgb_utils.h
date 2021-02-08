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
