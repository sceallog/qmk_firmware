#include "sceallog.h"
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    QWRT, // qwerty layer
    FACT,  // factorio layer
    STNO, // steno layer   
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | Caps |           |StenoL|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   F  |   P  |   B  | SymL |           |QwertL|   J  |   L  |   U  |   Y  |   ;  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   R  |   S  |   T  |   G  |------|           |------|   K  |   N  |   E  |   I  |   O  |   '"   |
   * |--------+------+------+------+------+------|LANG 1|           |LANG 2|------+------+------+------+------+--------|
   * |(/LShift|   Z  |   X  |   C  |   D  |   V  |      |           |      |   M  |   H  |   ,  |   .  |  / ? |)/RShift|
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |CS/Esc|  ` ~ |CS/Sym| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~MedL |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Lead |Tog AS|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | PgUp |       | Home |        |      |
   *                                 | Space|Back  |------|       |------|  Tab   |Enter |
   *                                 |      |space | PgDn |       | End  |        |      |
   *                                 `--------------------'       `----------------------'
   */
[BASE] = LAYOUT_ergodox_pretty(
  KC_EQL,         KC_1,   KC_2,             KC_3,     KC_4,      KC_5,    KC_CAPS,              TG(5),    KC_6,   KC_7,     KC_8,       KC_9,       KC_0,       KC_MINS,
  KC_DEL,         KC_Q,   KC_W,             KC_F,     KC_P,      KC_B,    TT(1),                TG(3),    KC_J,   KC_L,     KC_U,       KC_Y,       KC_SCLN,    KC_BSLS,
  KC_BSPC,        KC_A,   KC_R,             KC_S,     KC_T,      KC_G,                                    KC_M,   KC_N,     KC_E,       KC_I,       KC_O,       KC_QUOT,
  KC_LSPO,        KC_Z,   KC_X,             KC_C,     KC_D,      KC_V,    KC_LANG1,             KC_LANG2, KC_K,   KC_H,     KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,
  SGUI_T(KC_ESC), KC_GRV, ALT_T(KC_INT2),   KC_LEFT,  KC_RGHT,                                                    KC_UP,    KC_DOWN,    KC_LBRC,    KC_RBRC,    TT(2),
                                                           OSM(MOD_LCTL), KC_LGUI,              KC_LEAD,  KC_ASTG,
                                                                          KC_PGUP,              KC_HOME,
                                                         KC_SPC, KC_BSPC, KC_PGDN,              KC_END,   KC_TAB, KC_ENT
),
  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   {  |   }  |   |  |   &  |   /  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   (  |   )  |   '  |   _  |   "  |------|           |------| Down |   4  |   5  |   6  |   +  |   -    |
   * |--------+------+------+------+------+------|      |           |  L4  |------+------+------+------+------+--------|
   * |        |   [  |   ]  |   !  |   @  |   #  |      |           |      |      |   1  |   2  |   3  |   \  |  Enter |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |   %  |   <  |   >  |   =  |                                       |   0  |    . |      |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_LCBR, KC_RCBR,   KC_PIPE, KC_AMPR, KC_SLSH, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_LPRN, KC_RPRN,  KC_QUOT, KC_UNDS, KC_DQUO,                        KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS,
  KC_TRNS, KC_LBRC, KC_RBRC, KC_EXLM, KC_AT, KC_HASH, KC_TRNS,     TG(4), KC_TRNS, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_ENT,
  KC_TRNS, KC_PERC, KC_LABK, KC_RABK, KC_EQL,                                         KC_0, KC_PDOT,  KC_COMM,    KC_EQL,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
  /* Keymap 2: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        | PREV |WM NW | WM N |WM NE |RESTOR|      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------| Play |           |      |------+------+------+------+------+--------|
   * |  BrUp  | FULL | WM W |CENTRE| WM E |LARGE |------|           |------|      |      | Lclk | MsUp | Rclk |        |
   * |--------+------+------+------+------+------| Mute |           |      |------+------+------+------+------+--------|
   * |  BrDn  | NEXT |WM SW | WM S |WM SE |SMALL |      |           |      |      |      |MsLeft|MsDown|MsRght|        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      | WhLe |MdlClk| WhRe |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |BrBack|BrFwd |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 | Prev | Next |VolUp |       |      |      |      |
   *                                 |      |      |------|       |------| WhDn | WhUp |
   *                                 |Track |Track |VolDwn|       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
[MDIA] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS, WM_PREV, WM_NW,   WM_N,    WM_NE,   WM_RSTR, KC_MPLY,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_BRIU, WM_FULL, WM_W,    WM_CNTR, WM_E,    WM_LRG,                        KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2, KC_TRNS,
  KC_BRID, WM_NEXT, WM_SW,   WM_S,    WM_SE,   WM_SMLL, KC_MUTE,     KC_TRNS, KC_TRNS, KC_TRNS,	KC_MS_LEFT, KC_MS_DOWN, KC_MS_R,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_WH_L,    KC_MS_BTN3, KC_WH_R,    KC_TRNS,

                                               KC_WBAK, KC_WFWD,     KC_TRNS, KC_TRNS,
                                                        KC_VOLU,     KC_TRNS,
                                      KC_MPRV, KC_MNXT, KC_VOLD,     KC_TRNS, KC_WH_D, KC_WH_U
),

  /* Keymap 3: QWERTY layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
   * |--------+------+------+------+------+------|LANG 1|           |LANG 2|------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | PgUp |       | Home |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | PgDn |       | End  |        |      |
   *                                 `--------------------'       `----------------------'
   */
[QWRT] = LAYOUT_ergodox_pretty(
  KC_EQL,         KC_1,   KC_2,             KC_3,     KC_4,      KC_5,    KC_TRNS,              KC_TRNS,  KC_6,   KC_7,     KC_8,       KC_9,       KC_0,       KC_MINS,
  KC_DEL,         KC_Q,   KC_W,             KC_E,     KC_R,      KC_T,    TT(1),                KC_TRNS,  KC_Y,   KC_U,     KC_I,       KC_O,       KC_P,       KC_BSLS,
  KC_BSPC,        KC_A,   KC_S,             KC_D,     KC_F,      KC_G,                                    KC_H,   KC_J,     KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
  KC_LSPO,        KC_Z,   KC_X,             KC_C,     KC_V,      KC_B,    KC_LANG1,             KC_LANG2, KC_N,   KC_M,     KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,
  SGUI_T(KC_ESC), KC_GRV, ALT_T(KC_INT2),   KC_LEFT,  KC_RGHT,                                                    KC_UP,    KC_DOWN,    KC_LBRC,    KC_RBRC,    TT(2),
                                                           OSM(MOD_LCTL), KC_LGUI,              KC_LEAD,  KC_ASTG,
                                                                          KC_PGUP,              KC_HOME,
                                                         KC_SPC, KC_BSPC, KC_PGDN,              KC_END,   KC_TAB, KC_ENT
),

  /* Keymap 4: Factorio
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   Esc  |Ctrl-Z|Ctrl-X|Ctrl-C|Ctrl-V|   X  |  `   |           |      |      |      |      |      |      | Tog AS |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   Tab  | Space|   T  |  W   |  M   |   B  |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Num +  |  E   |   A  |  S   |  D   |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Num -  |Enter |      |      | LCtrl| Space|   O  |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | LAlt |  U   | Mclk |   C  |LShift|                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |   L  |   G  |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |   Z  |       |      |      |      |
   *                                 |   Q  |   R  |------|       |------|      |      |
   *                                 |      |      |   F  |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // FOR PLAYING FACTORIO
  [FACT] = LAYOUT_ergodox_pretty(
    KC_ESC,   C(KC_Z),  C(KC_X),    C(KC_C),  C(KC_V),        KC_X,         KC_GRV,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTG,
    KC_TAB,   KC_SPC,   KC_T,       KC_W,     KC_M,           KC_B,         KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_PPLS,  KC_E,     KC_A,       KC_S,     KC_D,           KC_TRNS,                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_PMNS,  KC_ENTER, KC_TRNS,    KC_TRNS,  KC_LCTL,        KC_SPC,       KC_O,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LALT,  KC_U,     KC_MS_BTN3, KC_C,     KC_LSFT,                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                                              KC_L,         KC_G,               KC_TRNS, KC_TRNS,
                                                                            KC_Z,               KC_TRNS,
                                              KC_Q,           KC_R,         KC_F,               KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* Keymap 5: Gemini (Serial) Alternative
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |   #  |   #  |   #  |   #  |  *   |           |  *   |   #  |   #  |   #  |   #  |   #  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |   S  |   T  |   P  |   H  |------|           |------|   F  |   P  |   L  |   T  |   D  |        |
   * |--------+------+------+------+------+------|  *   |           |  *   |------+------+------+------+------+--------|
   * |        |      |   S  |   K  |   W  |   R  |      |           |      |   R  |   B  |   G  |   S  |   Z  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |   A  |   O  |------|       |------|   E  |   U  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Gemini over Serial
  [STNO] = LAYOUT_ergodox_pretty(
         KC_NO,   KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_NO,   KC_NO,  STN_N2,   STN_N3,  STN_N4,  STN_N5,  STN_ST1,         STN_ST3,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  KC_NO,
         KC_NO,   KC_NO,  STN_S1,   STN_TL,  STN_PL,  STN_HL,                             STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  KC_NO,
         KC_NO,   KC_NO,  STN_S2,   STN_KL,  STN_WL,  STN_RL,  STN_ST2,         STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  KC_NO,
         KC_NO,   KC_NO,  KC_NO,    KC_NO,   KC_NO,                                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_NO,   KC_NO,                    KC_NO,    KC_NO,
                                                      KC_NO,                    KC_NO,
                                    STN_A,   STN_O,   KC_NO,                    KC_NO,    STN_E,   STN_U
  ),
};

// Runs just one time when the keyboard initialises.
//void matrix_init_user(void) {
//    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
//};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};