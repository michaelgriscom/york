/*
 * Ergodox-EZ key layout roughly based on the Microsoft Natural Ergonomic Keyboard 4000 and optimized for Spacemacs.
 *
 * To build, launch bash and run 'make keymap=york' in keyboards/ergodox
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

//Tap Dance Declarations
enum {
    TD_LBRC_LCBR = 0,
    TD_RBRC_RCBR,
};

// emojis require running WinCompose
enum function_ids {
    EMOJI = 0,
};

/* opt can only be 0-15 */
enum emojis {
    SHRUG = 0,
    TABLE,
};

enum progmem_ids {
    EMOJI_SHRUG = 0,
    EMOJI_TABLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |   6    |           |   7  |   8  |   9  |   0  | - _  |  = + |  T(L2) |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  ` ~   |   Q  |   W  |   E  |   R  |   T  |  [{  |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |   \ |  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Tab  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : | Enter  |
 * |--------+------+------+------+------+------|,<    |           | .>   |------+------+------+------+------+--------|
 * | LShift(|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | Up   |  ' " |  / ? | )RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui | Pscn | T(L1) | RDP | Alt |                                       | Left | Down  | Right|  Del  |  T(L2) |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | PgUp | PgDn |       | Home | End    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | F10  |       | F5   |        |      |
 *                                 |Space |Ctrl  |------|       |------| Leader |Space |
 *                                 |      |      | F11  |       | Delt|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(
  // left hand
  KC_ESC,         KC_1,           KC_2,         KC_3,                 KC_4,         KC_5,       KC_6,
  KC_GRV,         KC_Q,           KC_W,         KC_E,                 KC_R,         KC_T,       KC_LBRACKET,
  KC_TAB,         KC_A,           KC_S,         KC_D,                 KC_F,         KC_G,
  KC_LSPO,        KC_Z,           KC_X,         KC_C,                 KC_V,         KC_B,       KC_COMM,
  MO(SYMB),       KC_LGUI,        KC_PSCR,      LCTL(LALT(KC_HOME)),  KC_LALT,

                                                KC_F10,   KC_F11,
                                                KC_F9,
                                        KC_SPC, KC_LCTRL, KC_F5,

  // right hand
  KC_7,           KC_8,           KC_9,         KC_0,     KC_MINS,      KC_EQL,   LCTL(LALT(KC_HOME)),
  KC_RBRACKET,    KC_Y,           KC_U,         KC_I,     KC_O,         KC_P,     KC_BSLASH,
                  KC_H,           KC_J,         KC_K,     KC_L,         KC_QUOT,  KC_ENT,
  KC_DOT,         KC_N,           KC_M,         KC_UP,    KC_SCOLON,    KC_SLSH,  KC_RSPC,
                                  KC_LEFT,      KC_DOWN,  KC_RIGHT,     KC_COMM,  KC_DOT,

        KC_MPLY,    KC_MNXT,
        KC_VOLU,
        KC_VOLD,    MO(MDIA),   KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F0  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |mouseu|      |      |      |      |           |      |      |   7  |   8  |   9  |   /  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |mousel|mousd|mouser|     |        |------|           |------|      |   4  |   5  |   6  |   *  |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |       |     |      |      |      |      |           |      |     |   1  |   2  |   3  |       |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |  ,   |     |     |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  lclick    |  rclick    |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
  // left hand
  KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
  KC_TRNS,    KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                  KC_TRNS,  KC_TRNS,
                                            KC_VOLU,
                        KC_BTN1,  KC_BTN2,  KC_VOLD,

  // right hand
  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_PSLS,  KC_PMNS,
            KC_TRNS,  KC_4,     KC_5,     KC_6,     KC_PAST,  KC_PPLS,
  KC_TRNS,  KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_TRNS,  KC_RBRC,
                      KC_0,     KC_DOT,   KC_COMM,  KC_TRNS,  KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_DELT
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MsUp |      | MWUP |      |      |      |           |      |      |      | MWUP |      | MsUp |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |MsLeft|MsDown|MsRght| MWDN |      |                                       |      | MWDN |MsLeft|MsDown|MsRght|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       | Prev | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |VolUp |       |VolUp |      |      |
 *                                 | Lclk | Rclk |------|       |------| Lclk | Rclk |
 *                                 |      |      |VolDn |       |VolDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
  // left hand
  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_TRNS,  F(EMOJI_TABLE), KC_TRNS,
  KC_TRNS,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,
  KC_LABK,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

  KC_TRNS,    KC_TRNS,
  KC_TRNS,
  KC_BTN1,    KC_BTN2,  KC_TRNS,

  // right hand
  KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_LCBR,      KC_RCBR,      KC_LBRACKET,  KC_RBRACKET,  KC_TRNS,
             KC_TRNS,   KC_LBRACKET,  KC_RBRACKET,  KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,   KC_PGUP,   KC_TRNS,      KC_WH_U,      KC_TRNS,      KC_TRNS,      KC_RABK,
                        KC_HOME,      KC_PGDN,      KC_END,       KC_TRNS,      KC_TRNS,

  KC_TRNS,   KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [EMOJI_SHRUG]   = ACTION_FUNCTION_OPT(EMOJI, SHRUG),
    [EMOJI_TABLE]   = ACTION_FUNCTION_OPT(EMOJI, TABLE),
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};

#define TAP_ONCE(code)                          \
    register_code (code);                       \
    unregister_code (code)

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
        case EMOJI:
            switch(opt) {
            case SHRUG:
                unicode_input_start(); register_hex(0xaf); unicode_input_finish();
                TAP_ONCE (KC_BSLS);
                register_code (KC_RSFT); TAP_ONCE (KC_MINS); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
                unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
                register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE (KC_MINS); unregister_code (KC_RSFT);
                TAP_ONCE (KC_SLSH);
                unicode_input_start (); register_hex(0xaf); unicode_input_finish();
                break;
            }
        }
    }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer)
  {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }
};
