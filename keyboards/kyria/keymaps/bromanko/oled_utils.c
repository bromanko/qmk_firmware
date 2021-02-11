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

    oled_write_P(PSTR("Mods:    S C A G"), false);
    oled_write_P(PSTR("\n\n"), false);

    // RGB information
    oled_write_P(PSTR("Hue:     [----------]"), false);
    oled_write_P(PSTR("Sat:     [----------]"), false);
    oled_write_P(PSTR("Bri:     [----------]"), false);

    // Host Keyboard LED Status
}
