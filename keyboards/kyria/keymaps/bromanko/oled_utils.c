#include "oled_utils.h"
#include <stdio.h>

char wpm_str[10];

void render_wpm(void) {
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
    oled_write(wpm_str, false);
}

void render_status(void) {
    // Status
    oled_write_P(PSTR("Layer:   "), false);
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
    oled_write_P(PSTR("Lock:    "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("abc") : PSTR("   "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("123") : PSTR("   "), false);
    oled_write_P(PSTR("\n"), false);

    uint16_t lsft = keyboard_report->mods & MOD_BIT(KC_LSHIFT);
    uint16_t rsft = keyboard_report->mods & MOD_BIT(KC_RSHIFT);
    oled_write_P(PSTR("Mods:    "), false);
    oled_write_P((lsft || rsft) ? PSTR("S") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);

    uint16_t lctr = keyboard_report->mods & MOD_BIT(KC_LCTRL);
    uint16_t rctr = keyboard_report->mods & MOD_BIT(KC_RCTRL);
    oled_write_P((lctr || rctr) ? PSTR("C") : PSTR(" "), false);

    uint16_t lalt = keyboard_report->mods & MOD_BIT(KC_LALT);
    uint16_t ralt = keyboard_report->mods & MOD_BIT(KC_RALT);
    oled_write_P((lalt || ralt) ? PSTR("A") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);

    uint16_t lgui = keyboard_report->mods & MOD_BIT(KC_LGUI);
    uint16_t rgui = keyboard_report->mods & MOD_BIT(KC_RGUI);
    oled_write_P((lgui || rgui) ? PSTR("G") : PSTR(" "), false);
    oled_write_P(PSTR("\n\n"), false);

    // RGB information
    if (rgblight_is_enabled()) {
        oled_write_P(PSTR("Hue:     [----------]"), false);
        oled_write_P(PSTR("Sat:     [----------]"), false);
        oled_write_P(PSTR("Bri:     [----------]"), false);
    } else {
        oled_write_P(PSTR("RGB:     Off\n\n\n"), false);
    }
}
