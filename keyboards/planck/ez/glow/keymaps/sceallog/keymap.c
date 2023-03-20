#include "sceallog.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  QWERTY = SAFE_RANGE,
  QWRTOFF,
  COLEMAK,
  ENT_PLV,
  EXT_PLV,
  ENT_FCT,
  EXT_FCT,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GUI,
  _QWERTY,
  _PLOVER,
  _FACTORIO,
};

#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)
#define GUI   TT(_GUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCOLON,  KC_BSPACE,
    KC_DELETE,      KC_A,       KC_R,       KC_S,       KC_T,       KC_G,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOTE,
    KC_LSPO,        KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_K,       KC_H,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSPC,
    CTL_T(KC_ESC),  KC_LCBR,    ALT_T(KC_LBRC),   LGUI_T(KC_ENT),    LOWER,      ALL_T(KC_SPACE),   KC_NO,      RAISE,      SGUI_T(KC_ENT),    RCAG_T(KC_RBRC),      KC_RCBR,    GUI
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_F1,       KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_7,        KC_8,        KC_9,         KC_BSPC,       KC_NUM,
    KC_PGUP,     KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      KC_4,        KC_5,        KC_6,         KC_KP_PLUS,    KC_KP_ASTERISK,
    KC_PGDOWN,   KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_1,        KC_2,        KC_3,         KC_KP_MINUS,   KC_KP_SLASH,
    KC_HOME,     KC_END,      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_NO,       KC_0,        KC_KP_DOT,   KC_COMMA,     KC_TAB,        KC_ENTER
  ),

  [_RAISE] = LAYOUT_planck_grid(
    WM_PREV,    WM_NW,    WM_N,      WM_NE,    WM_RSTR,     KC_PERC,    KC_CIRC,    KC_PERC,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DLR,
    WM_FULL,  WM_W,      WM_CNTR,      WM_E,      WM_LRG,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_MINS,    KC_EQL,    KC_LBRC,    KC_RBRC,    KC_BSLS,
    WM_NEXT,  WM_SW,      WM_S,      WM_SE,      WM_SMLL,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_UNDS,    KC_HASH,    KC_AT,    KC_AMPR,     KC_GRV,
    KC_LANG1,       KC_LANG2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTG,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOG,         KC_TRANSPARENT, TOGGLE_LAYER_COLOR,RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GUI] = LAYOUT_planck_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_BRIU,  KC_NO,    KC_PGUP,  KC_UP,    KC_PGDN,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_BRID,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV,  KC_MPLY,  KC_NO,    KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRANSPARENT
  ),
  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,
    KC_TRNS,KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_TRNS,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_PLOVER] = LAYOUT_planck_grid(
    STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         EXT_PLV,
    STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        STN_FN,         STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,
    STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,        KC_NO,          STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,
    KC_NO,          KC_NO,          KC_NO,          STN_A,          STN_O,          STN_E,          KC_NO,          STN_U,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_FACTORIO] = LAYOUT_planck_grid(
    KC_ESC,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         EXT_FCT,
    KC_TAB,         KC_LALT,         KC_T,         KC_W,         KC_M,        KC_B,         KC_O,        LALT(KC_R),         LALT(KC_E),         LALT(KC_L),         KC_NO,         KC_ASTG,
    KC_SPACE,         KC_ENTER,         KC_A,         KC_S,         KC_D,        KC_X,          KC_Z,        LALT(KC_B),         LALT(KC_D),         LALT(KC_U),         KC_GRV,         KC_PPLS,
    KC_C,          KC_R,          KC_G,          KC_F,          LCTL_T(KC_Q),          LSFT_T(KC_E),          KC_NO,          LCTL(KC_C),          LCTL(KC_V),        LCTL(KC_Z),        LCTL(KC_X),          KC_PMNS
  ),

};

enum combos {
  TABDEL_STENO,
 // QWL_LAYER_ON,
  QWERTY_LAYER_TOGGLE,
  LEAD,
  FACTORIO_LAYER,
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM tabdel_steno[] = { KC_TAB, KC_DELETE, COMBO_END};
const uint16_t PROGMEM qwerty_layer_toggle[] = { KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM qwl_layer_off[] = { KC_Q, KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM lead[] = { KC_BSPACE, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM factorio_layer[] = { KC_SCOLON, KC_BSPACE, COMBO_END};

combo_t key_combos[] = {
    [TABDEL_STENO] = COMBO(tabdel_steno, ENT_PLV),
    [QWERTY_LAYER_TOGGLE] = COMBO(qwerty_layer_toggle, QWERTY),
//    [QWL_LAYER_OFF] = COMBO(qwl_layer_off, QWRTOFF),
    [LEAD] = COMBO(lead, KC_LEAD),
    [FACTORIO_LAYER] = COMBO(factorio_layer, ENT_FCT),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
      {0,255,255}, {21,255,255}, {36,255,255}, {55,255,255}, {86,255,255}, {129,255,128}, {11,178,255}, {11,178,255}, {172,255,255}, {192,255,255}, {207,218,204}, {215,255,255},
      {0,255,255}, {21,255,255}, {36,255,255}, {55,255,255}, {0,0,255}, {129,255,128}, {129,255,255}, {0,0,255}, {172,255,255}, {192,255,255}, {207,218,204}, {207,218,204},
      {0,255,255}, {21,255,255}, {36,255,255}, {55,255,255}, {86,255,255}, {129,255,128}, {11,178,255}, {11,178,255}, {172,255,255}, {192,255,255}, {207,218,204}, {207,218,204},
      {0,255,255}, {21,255,255}, {36,255,255}, {55,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {172,255,255}, {192,255,255}, {207,218,204}, {207,218,204}
      },

    [1] = {
      {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {81,218,204},
      {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {29,218,204}, {29,218,204},
      {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {29,218,204}, {29,218,204},
      {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,245,245}, {29,218,204}, {29,218,204}, {0,0,255}, {0,0,255}
      },

    [2] = {
      {21,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {21,255,255}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255},
      {21,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {21,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255},
      {21,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {21,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255}, {64,255,255},
      {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
      },

    [3] = {
      {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {141,111,255}, {141,111,255}, {141,111,255}, {0,0,0}, {29,218,204}, {29,218,204}, {29,218,204}, {29,218,204}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {29,255,255}, {29,255,255}, {29,255,255}, {0,0,0}, {0,0,0}, {29,218,204}, {29,218,204}, {29,218,204}, {0,0,0}, {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
      },

    [4] = {
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},        {0,0,0},        {0,0,0},        {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},      {0,0,0},      {0,0,255},    {0,0,0},      {21,255,255},   {0,245,245},    {21,255,255},   {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},      {0,0,0},      {0,0,255},    {0,0,0},      {0,245,245},    {0,245,245},    {0,245,245},    {0,0,0},
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255},               {86,255,255}, {129,255,255},  {129,255,255},  {129,255,255},  {207,218,204}
      },

    [5] = {
      {0,0,255}, {41,255,255}, {0,245,245}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,255},
      {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {41,255,255}, {41,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,255},
      {0,0,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,255},
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}
      },

    [6] = {
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255},
      {90,218,204}, {90,218,204}, {90,218,204}, {90,218,204}, {0,0,255}, {141,111,255}, {0,0,255}, {90,218,204}, {90,218,204}, {90,218,204}, {90,218,204}, {90,218,204},
      {127,255,255}, {127,255,255}, {127,255,255}, {127,255,255}, {0,0,255}, {0,0,0}, {0,0,255}, {127,255,255}, {127,255,255}, {127,255,255}, {127,255,255}, {127,255,255},
      {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}
      },

    [7] = {
      {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255},
      {85,255,255}, {85,255,255}, {170,255,255}, {0,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {0,0,0}, {0,0,255},
      {85,255,255}, {85,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {170,255,255}, {170,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {170,255,255}, {170,255,255},
      {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {170,255,255}
      },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {

//     case RGB_SLD:
//       if (record->event.pressed) {
//         rgblight_mode(1);
//       }
//       return false;
//   }
//   return true;
// }

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
};


bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_TAP,
//     DOUBLE_HOLD,
//     DOUBLE_SINGLE_TAP,
//     MORE_TAPS
// };
// 
// static tap dance_state[2];
// 
// uint8_t dance_step(qk_tap_dance_state_t *state);
// 
// uint8_t dance_step(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return SINGLE_TAP;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }
// 
// 
// void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);
// 
// void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_LSPO);
//         tap_code16(KC_LSPO);
//         tap_code16(KC_LSPO);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_LSPO);
//     }
// }
// 
// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[0].step = dance_step(state);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: register_code16(KC_LSPO); break;
//         case DOUBLE_TAP: register_code16(KC_RPRN); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_LSPO); register_code16(KC_LSPO);
//     }
// }
// 
// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: unregister_code16(KC_LSPO); break;
//         case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSPO); break;
//     }
//     dance_state[0].step = 0;
// }
// void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

// void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_LSPO);
//         tap_code16(KC_LSPO);
//         tap_code16(KC_LSPO);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_LSPO);
//     }
// }

// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[1].step = dance_step(state);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: register_code16(KC_LSPO); break;
//         case DOUBLE_TAP: register_code16(KC_RPRN); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_LSPO); register_code16(KC_LSPO);
//     }
// }

// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: unregister_code16(KC_LSPO); break;
//         case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSPO); break;
//     }
//     dance_state[1].step = 0;
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//         [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
//         // [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case RGB_SLD:
    //   if (record->event.pressed) {
    //     rgblight_mode(1);
    //   }
    //   return false;
    //   break;
    case QWERTY:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_invert(_QWERTY);
      }
      return false;
      break;
    case QWRTOFF:
      if (record ->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        default_layer_set(_BASE);
      }
      return false;
      break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //   }
    //   return false;
    //   break;
    case ENT_PLV:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVER);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case ENT_FCT:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_FACTORIO);
      }
      return false;
      break;
    case EXT_FCT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_FACTORIO);
      }
      return false;
      break;
  }
  return true;
}
