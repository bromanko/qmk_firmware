#pragma once

#define XXX KC_NO

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX, XXX,      XXX, XXX, K25, K26, K27, K28, K29, XXX,\
               XXX, XXX, K32, K33, K34,      K35, K36, K37, XXX, XXX\
)

#define BILATERAL_COMBINATIONS

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_TWINKLE
  #define RGBLIGHT_EFFECT_BREATHING

  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_LIMIT_VAL 128

  #define RGBLIGHT_LAYERS
#endif
