EXTRAFLAGS += -flto

USER_NAME := manna-harbour_miryoku
MIRYOKU_NAV := VI
MIRYOKU_MAPPING := EXTENDED_THUMBS

CONSOLE_ENABLE = no
OLED_DRIVER_ENABLE = yes
RGBLIGHT_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	WPM_ENABLE = yes
	SRC += oled_utils.c
endif

