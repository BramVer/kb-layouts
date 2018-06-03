# Build options
BACKLIGHT_ENABLE = yes		# Switch LEDs
MOUSEKEY_ENABLE = yes		# Emulates mouse key using keypresses
RGBLIGHT_ENABLE = no 		# LED strips
TAP_DANCE_ENABLE = no 		# Use multi-tap features
AUDIO_ENABLE = no  			# Audio stuff
RGBLIGHT_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
