#include "oled_utils.h"
#include <stdio.h>
#include <string.h>

char wpm_str[10];
char hue_str[12];
char sat_str[12];
char bri_str[12];

void render_wpm(void) {
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
    oled_write(wpm_str, false);
}

void progress_str(char *meter, uint8_t val, uint8_t max) {
    memset(meter, 0, strlen(meter));

    const uint8_t segments = 10;
//    ratio = val / max;
    strcat(meter, "[");
    for (uint8_t i = 1; i < segments; i++) {
        strcat(meter, " ");
    }
    strcat(meter, "]");
}

void render_status(void) {
    // Status
    oled_write_P(PSTR("Layer:    "), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case MOUR:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case NAVR:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case MEDR:
            oled_write_P(PSTR("Media"), false);
            break;
        case NSSL:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case NSL:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case FUNL:
            oled_write_P(PSTR("Functions"), false);
            break;
        default:
            oled_write_P(PSTR("???"), false);
    }
    oled_write_P(PSTR("\n"), false);

    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(PSTR("Lock:     "), false);
    oled_write_P(PSTR("abc"), IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK));
    oled_write_P(PSTR("   "), false);
    oled_write_P(PSTR("123"), IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK));
    oled_write_P(PSTR("\n"), false);

    uint16_t lsft = keyboard_report->mods & MOD_BIT(KC_LSHIFT);
    uint16_t rsft = keyboard_report->mods & MOD_BIT(KC_RSHIFT);
    oled_write_P(PSTR("Mods:     "), false);
    oled_write_P(PSTR("S"), (lsft || rsft));
    oled_write_P(PSTR("  "), false);

    uint16_t lctr = keyboard_report->mods & MOD_BIT(KC_LCTRL);
    uint16_t rctr = keyboard_report->mods & MOD_BIT(KC_RCTRL);
    oled_write_P(PSTR("C"), (lctr || rctr));
    oled_write_P(PSTR("  "), false);

    uint16_t lalt = keyboard_report->mods & MOD_BIT(KC_LALT);
    uint16_t ralt = keyboard_report->mods & MOD_BIT(KC_RALT);
    oled_write_P(PSTR("A"), (lalt || ralt));
    oled_write_P(PSTR("  "), false);

    uint16_t lgui = keyboard_report->mods & MOD_BIT(KC_LGUI);
    uint16_t rgui = keyboard_report->mods & MOD_BIT(KC_RGUI);
    oled_write_P(PSTR("G"), (lgui || rgui));
    oled_write_P(PSTR("\n\n"), false);

    // RGB information
    if (rgblight_is_enabled()) {
        oled_write_P(PSTR("Hue:      "), false);
        progress_str(hue_str, rgblight_get_hue(), 255);
        oled_write(hue_str, false);

        oled_write_P(PSTR("Sat:      "), false);
        progress_str(sat_str, rgblight_get_sat(), 255);
        oled_write(sat_str, false);

        oled_write_P(PSTR("Bri:      "), false);
        progress_str(bri_str, rgblight_get_val(), RGBLIGHT_LIMIT_VAL);
        oled_write(bri_str, false);
    } else {
        oled_write_P(PSTR("RGB:      Off\n\n\n"), false);
    }
}

