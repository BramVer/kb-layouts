/* Copyright 2018 darm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _LY1 0
#define _LY2 1
#define _LY3 2
#define _LY4 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_LY1] = {
		{KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPRV, KC_MPLY, KC_MNXT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC}, 
		{KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS, KC_EQL, KC_BSLS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT}, 
		{KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_MUTE, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT}, 
		{KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, M(0), KC_END, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT}, 
		{KC_LCTL, TO(1), KC_LALT, KC_LGUI, KC_SPC, KC_SPC, TO(2), KC_DEL, TO(3), KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RGUI},
	},

	[_LY2] = {
		{KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12}, 
		{KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
	},

	[_LY3] = {
		{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC, BL_INC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_WH_R, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, BL_STEP, RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, RGB_HUI, RGB_HUD, RGB_SAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
	},

	[_LY4] = {
		{M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), RESET}, 
		{M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1)}, 
		{M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1)}, 
		{M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1)}, 
		{M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1), M(1)},
	},

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( D(LGUI), T(ENT), U(LGUI), T(P), D(A), D(C), U(A), U(C), T(A), T(U), T(R), T(SPC), T(MINS), D(LSFT), T(S), U(LSFT), T(Y), T(U), T(ENT), END );
			}
			break;
		case 1:
			if (record->event.pressed) {
				return MACRO( T(N), T(N), T(N), T(N), T(N), T(N), T(N), T(N), T(N), T(N), T(N), D(LSFT), T(B), T(E), T(N), T(I), T(S), U(LSFT), END );
			}
			break;
		default:
			return MACRO_NONE;
	}
	return MACRO_NONE;

}