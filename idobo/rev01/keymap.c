/* Copyright 2020 darm
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
#include QMK_KEYBOARD_H

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _BASE     0
#define _LOWER    1
#define _LINVERT  2
#define _RAISE    3
#define _EMOJIFY  4

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
};

enum emoji_map {
  UNAM, // unamused 😒
  HEYE, // smiling face with heart shaped eyes 😍
  OK, // ok hand sign 👌
  SMIR, // smirk 😏
  PRAY, // pray 🙏
  CELE, // celebration 🙌
  COOL, // smile with sunglasses 😎
  EYES, // eyes
  THNK, // BIG THONK
  NAIL, // Nailcare
  SOS, // Vuile sos
  REDB, // Red B
  HNDR, // 100
  MONY,
  FIRE,
  CAR,
  BUTT,
  BNIS,
  CUM,
  CLAP,
  TRIU, // Fart from nose
  SCRM,
  VOMI,
  DTIV, // Detective
  EXPL, // Brainsplosion
  HAIR, // Haircut
  DANC, // Salsa dancer
  STRN, // Stronk
  LEFT, // Point Left
  RGHT, // Point Right
};

const uint32_t PROGMEM unicode_map[] = {
  [UNAM] = 0x1F612,
  [HEYE] = 0x1f60d,
  [OK]   = 0x1F44C,
  [SMIR] = 0x1F60F,
  [PRAY] = 0x1F64F,
  [CELE] = 0x1F64C,
  [COOL] = 0x1F60E,
  [EYES] = 0x1F440,
  [THNK] = 0x1F914,
  [NAIL] = 0x1F485,
  [SOS] = 0x1F198,
  [REDB] = 0x1F171,
  [HNDR] = 0x1F4AF,
  [MONY] = 0x1F480,
  [FIRE] = 0x1F525,
  [CAR] = 0x1F697,
  [BUTT] = 0x1F351,
  [BNIS] = 0x1F346,
  [CUM] = 0x1F4A6,
  [CLAP] = 0x1F44F,
  [TRIU] = 0x1F624,
  [SCRM] = 0x1F631,
  [VOMI] = 0x1F92E,
  [DTIV] = 0x1F575,
  [EXPL] = 0x1F92F,
  [HAIR] = 0x2640,
  [DANC] = 0x1F483,
  [STRN] = 0x1F4AA,
  [LEFT] = 0x1F448,
  [RGHT] = 0x1F449,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_5x15( \
    KC_GESC , KC_1  , KC_2    , KC_3    , KC_4    , KC_5    , KC_MPRV , KC_MPLY , KC_MNXT , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC , \
    KC_TAB  , KC_Q  , KC_W    , KC_E    , KC_R    , KC_T    , KC_MINS , KC_BSLS , KC_EQL  , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_ENT  , \
    MO(3)   , KC_A  , KC_S    , KC_D    , KC_F    , KC_G    , KC_LBRC , KC_MUTE , KC_RBRC , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , \
    KC_LSFT , KC_Z  , KC_X    , KC_C    , KC_V    , KC_B    , KC_HOME , EMAIL   , KC_END  , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , \
    KC_LCTL , MO(4) , KC_LALT , KC_LGUI , KC_SPC  , KC_SPC  , MO(1)   , KC_DEL  , MO(2)   , KC_GRAVE, KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_RGUI \
  ),

  [_LOWER] = LAYOUT_ortho_5x15( \
    _______ , _______ , _______ , KC_BTN3 , _______ , _______ , BL_TOGG , BL_DEC  , BL_INC  , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , KC_WH_L , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U , BL_STEP , RGB_TOG , RGB_MOD , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , KC_WH_R , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , RGB_HUI , RGB_HUD , RGB_SAI , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , RGB_SAD , RGB_VAI , RGB_VAD , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ \
  ),

  [_LINVERT] = LAYOUT_ortho_5x15( \
    _______ , _______ , _______ , _______ , _______ , _______ , BL_TOGG , BL_DEC  , BL_INC  , _______ , _______ , KC_BTN3 , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , BL_STEP , RGB_TOG , RGB_MOD , KC_WH_U , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_L , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , RGB_SAI , RGB_HUI , RGB_HUD , KC_WH_D , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_R , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , RGB_SAD , RGB_VAI , RGB_VAD , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ \
  ),

  [_RAISE] = LAYOUT_ortho_5x15( \
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , _______ , _______ , _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ \
  ),

  [_EMOJIFY] = LAYOUT_ortho_5x15( \
    TO(0)   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , X(CLAP) , X(CUM)  , X(BNIS) , X(BUTT) , X(CAR)  , _______ , _______ , _______ , X(FIRE) , X(REDB) , X(MONY) , X(HNDR) , X(SOS)  , _______ , \
    _______ , X(CELE) , X(PRAY) , X(NAIL) , X(OK)   , X(THNK) , _______ , _______ , _______ , X(UNAM) , X(HEYE) , X(COOL) , X(EYES) , X(SMIR) , _______ , \
    _______ , X(TRIU) , X(SCRM) , X(VOMI) , X(DTIV) , X(EXPL) , _______ , _______ , _______ , X(HAIR) , X(DANC) , X(STRN) , X(LEFT) , X(RGHT) , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , RESET   , _______ , _______ , _______ , _______ , _______ , _______ , _______ \
  ),

};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EMAIL:
      if (record->event.pressed) {
        // when keycode EMAIL is pressed
        SEND_STRING("bramvereertbrugghen@live.be");
      }
      break;
  }
  return true;
}

/* Template for future layers
 [_LAYER_NAME] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
 }
};
*/
