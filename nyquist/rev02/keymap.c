#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _LMOUSE 3
#define _RMOUSE 4
#define _EMOJI 5

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  LMOUSE,
  RMOUSE,
  EMOJI
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
  100P, // 100
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
  [100P] = 0x1F4AF,
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

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = { //ACTION_LAYER_TAP_TOGGLE requires that number of taps be defined in *config.h* - default set to 5
    [0] = LT(_LMOUSE, KC_SPC),       //Hold for momentary LMouse layer, Tap for Space, 
    [1] = LT(_RMOUSE, KC_SPC),      //Hold for momentary RMouse layer, Tap for Space,
    [2] = MO(_LOWER),               //Hold for momentary Lower
    [3] = MO(_RAISE),               //Hold for momentary Raise
    [4] = MO(_EMOJI),               //Hold for momentary Emoji
 };

#define SP_LMS FUNC(0)
#define SP_RMS FUNC(1)
#define LOW FUNC(2)
#define RAI FUNC(3)
#define EMO FUNC(4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GEsc |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LOW  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | EMO  | Alt  | GUI  |SP_LMS|SP_LMS| |SP_RMS|SP_RMS| GUI  | Alt  | RAI  | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_BASE] = LAYOUT( \
  KC_GESC ,   KC_1  ,   KC_2    ,   KC_3    ,   KC_4    ,   KC_5    , /**/    KC_6    ,   KC_7    ,   KC_8    ,   KC_9    , KC_0    ,   KC_BSPC , \
  KC_TAB  ,   KC_Q  ,   KC_W    ,   KC_E    ,   KC_R    ,   KC_T    , /**/    KC_Y    ,   KC_U    ,   KC_I    ,   KC_O    , KC_P    ,   KC_ENT  , \
  LOW     ,   KC_A  ,   KC_S    ,   KC_D    ,   KC_F    ,   KC_G    , /**/    KC_H    ,   KC_J    ,   KC_K    ,   KC_L    , KC_SCLN ,   KC_QUOT , \
  KC_LSFT ,   KC_Z  ,   KC_X    ,   KC_C    ,   KC_V    ,   KC_B    , /**/    KC_N    ,   KC_M    ,   KC_COMM ,   KC_DOT  , KC_SLSH ,   KC_RSFT , \
  KC_LCTL ,   EMO   ,   KC_LALT ,   KC_LGUI ,   SP_LMS  ,   SP_LMS  , /**/    SP_RMS  ,   SP_RMS  ,   KC_RGUI ,   KC_RALT , RAI     ,   KC_RCTL  \
),


/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GESC |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  \   |  -   |  =   |  [   |  ]   | |  [   |  ]   |  -   |  =   |  \   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |      |      |      |      |      | | Play | Vol+ | Vol- | Mute | Next | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |      |      | |      |      | GUI  | Alt  |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_BASE] = LAYOUT( \
  _______ ,   KC_EXLM ,   KC_AT   ,   KC_HASH ,   KC_DLR  ,   KC_PERC , /**/    KC_CIRC ,   KC_AMPR ,   KC_ASTR ,   KC_LPRN , KC_RPRN ,   _______ , \
  _______ ,   KC_EXLM ,   KC_AT   ,   KC_HASH ,   KC_DLR  ,   KC_PERC , /**/    KC_CIRC ,   KC_AMPR ,   KC_ASTR ,   KC_LPRN , KC_RPRN ,   _______ , \
  xxxxxxx ,   KC_RCBR ,   KC_MINS ,   KC_EQL  ,   KC_LBRC ,   KC_RBRC , /**/    KC_LBRC ,   KC_RBRC ,   KC_MINS ,   KC_EQL  , KC_BSLS ,   KC_DEL  , \
  _______ ,   xxxxxxx ,   xxxxxxx ,   xxxxxxx ,   xxxxxxx ,   xxxxxxx , /**/    KC_MPLY ,   KC_VOLU ,   KC_VOLD ,   KC_MUTE , KC_MNXT ,   _______ , \
  _______ ,   xxxxxxx ,   _______ ,   _______ ,   xxxxxxx ,   xxxxxxx , /**/    xxxxxxx ,   xxxxxxx ,   _______ ,   _______ , xxxxxxx ,   _______  \
),

/* Raise
 * ,-----------------------------------------. .-----------------------------------------.
 * | GESC |      |      |      |      |      | |      |   =  |   /  |   *  |   -  | Bksp  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  F9  |  F10 | F11  | F12  |      | |      |   7  |   8  |   9  |   +  | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | |      |   4  |   5  |   6  |  ,   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  F1  |  F2  |  F3  |  F4  |      | |      |   1  |   2  |   3  |  .   | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |      |      | |      |  0   | GUI  | Alt  |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */

/* LMOUSE (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GESC |      | Home | End  | PGUP | PGDN | |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  | WH_L | BTN1 | MS_U | BTN2 | WH_U | |      |      |      |      |      | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | WH_R | MS_L | MS_D | MS_R | WH_D | |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft | LEFT | DOWN |  UP  |RIGHT |      | |      |      |      |      |      | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |      |      | |      |      | GUI  | Alt  |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */

/* RMOUSE (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GESC |      |      |      |      |      | | PGUP | PGDN | Home | End  |      | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      | | WH_U | BTN1 | MS_U | BTN2 | WH_L | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | | WH_D | MS_L | MS_D | MS_R | WH_R | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |      |      |      |      |      | |      | LEFT | DOWN |  UP  |RIGHT | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |      |      | |      |      | GUI  | Alt  |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */


/* Emojis
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GESC |      |      |      |      |      | | RSET |      |      |      |      | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  | CLAP | CUM  | BNIS | BUTT | CAR  | | FIRE |  B   | MONY | 100  | PRTE | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | CELE | PRAY | NAIL |  OK  | THNK | | UNAM | HEYE | COOL | EYES | SMIR | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft | TRIU | SRCM | VOMI | DTIV | EXPL | | HAIR | DANC | STRN | LEFT | RGHT | Shft |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |      |      | |      |      | GUI  | Alt  |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */



/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* LINVERT (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LINVERT] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _LINVERT);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _LINVERT);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _LINVERT);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _LINVERT);
      }
      return false;
      break;
    case LINVERT:
      if (record->event.pressed) {
        layer_on(_LINVERT);
      } else {
        layer_off(_LINVERT);
      }
      return false;
      break;
  }
  return true;
}
