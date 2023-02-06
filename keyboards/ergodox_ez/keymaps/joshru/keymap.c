#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  CUSTOM_KEY,
  
};

enum {
  TD_CUT_COPY = 0,
  TD_PASTE
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // copy on press, cut on double tap
  [ TD_CUT_COPY ] = ACTION_TAP_DANCE_DOUBLE( LCTL(KC_C), LCTL(KC_X) ),
  // paste on press, shift + paste for clipboard pasting on double tap
  [ TD_PASTE ] = ACTION_TAP_DANCE_DOUBLE( LCTL(KC_V), LSFT( LCTL( KC_V ) ) )
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE,   KC_1,    KC_2,            KC_3,    KC_4,     KC_5, KC_GRAVE,
    KC_TAB,      KC_Q,    KC_W,            KC_E,    KC_R,     KC_T, KC_DELETE,
    KC_SCRL,     KC_A,    KC_S,            KC_D,    KC_F,     KC_G,
    KC_LSPO,     KC_Z,    KC_X,            KC_C,    KC_V,     KC_B, KC_LBRC,
    KC_LCTL,     KC_LALT, TG(2),           KC_LEFT, KC_RIGHT,
    
                                                                           LCTL(KC_Z),   LCTL(LSFT(KC_Z)),
                                                                                         TD(TD_CUT_COPY),
                                                               KC_BSPC,  GUI_T(KC_NO), TD(TD_PASTE),
                                                    
    // right hand                                                
    KC_EQUAL,    KC_6,    KC_7,    KC_8,     KC_9,            KC_0,             KC_MINUS,
    TG(1),       KC_Y,    KC_U,    KC_I,     KC_O,            KC_P,             KC_BSLS,
                 KC_H,    KC_J,    KC_K,     KC_L,            LT(2,KC_SCLN),  GUI_T(KC_QUOTE),
    KC_RBRC, KC_N,    KC_M,    KC_COMMA, KC_DOT,          RCTL_T(KC_SLASH), KC_RSPC,
    KC_UP,       KC_DOWN, KC_LEFT, KC_RIGHT, MO(1),
    
    KC_HOME,   KC_END,
    KC_PGUP,
    KC_PGDN, KC_ENTER, KC_SPACE
  ),

  [1] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE,       KC_F1,           KC_F2,           KC_F3,           KC_F4,          KC_F5,    KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_EXLM,         KC_AT,           KC_LCBR,         KC_RCBR,        KC_PIPE,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_HASH,         KC_DLR,          KC_LPRN,         KC_RPRN,        KC_GRAVE,
    KC_LSFT,       KC_PERC,         KC_CIRC,         KC_LBRC,         KC_RBRC,        KC_TILD,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
                                                                                                  LCTL(KC_Z),  LCTL(LSFT(KC_Z)),
                                                                                                               LCTL(KC_C),
                                                                                      KC_BSPC,  KC_LGUI,     LCTL(KC_Z),

    // right hand                                                                              
    KC_TRANSPARENT,  KC_F6,    KC_F7,   KC_F8,     KC_F9,          KC_F10,          KC_F11,
    KC_TRANSPARENT,  KC_UP,    KC_7,    KC_8,      KC_9,           KC_ASTR,         KC_F12,
                     KC_DOWN,  KC_4,    KC_5,      KC_6,           KC_PLUS,         KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_AMPR,  KC_1,    KC_2,      KC_3,           KC_BSLS,       KC_RSFT,
    KC_0,            KC_0,     KC_DOT,  KC_EQUAL,  KC_TRANSPARENT,
    
    KC_HOME,    KC_END,
    KC_PGUP,
    KC_PGDN,  KC_ENTER,  KC_SPACE
  ),

  [2] = LAYOUT_ergodox(
    // left hand
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_MS_UP,        KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_MS_LEFT,      KC_MS_DOWN,      KC_MS_RIGHT,     KC_TRANSPARENT,  
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_MS_BTN1,      KC_MS_BTN2,
    
                                                                                                                    RGB_MOD,  KC_TRANSPARENT,
                                                                                                                              KC_TRANSPARENT,
                                                                                                          RGB_VAD,  RGB_VAI,  KC_TRANSPARENT,
    
    // right hand
    KC_TRANSPARENT,   KC_TRANSPARENT,     KC_TRANSPARENT,  KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_TRANSPARENT,     KC_TRANSPARENT,  KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,
                      KC_TRANSPARENT,     KC_TRANSPARENT,  KC_BTN1,              KC_TRANSPARENT,       KC_TRANSPARENT,       KC_NUM,
    KC_TRANSPARENT,   KC_TRANSPARENT,     KC_TRANSPARENT,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_MEDIA_PLAY_PAUSE,  KC_TRANSPARENT,
    KC_AUDIO_VOL_UP,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_MUTE,   KC_TRANSPARENT,       KC_TRANSPARENT,
    
    RGB_TOG,         RGB_SLD,
    KC_TRANSPARENT,
    KC_TRANSPARENT,  RGB_HUD,  RGB_HUI
  ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//       switch(id) {
//         case 0:
//         if (record->event.pressed) {
//           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//         }
//         break;
//       }
//     return MACRO_NONE;
// };

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t start_time;
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case CUSTOM_KEY:
      if (record->event.pressed) {
        // start timing the length of the key press
        start_time = timer_read();
        return false;
      } else { // once the key is released, check how long it was held for
        // if it was held for longer than 150ms send the HOLD string. Else send the TAP string
        if (timer_elapsed(start_time) > 150) {
          SEND_STRING("HOLD");
        } else {
          SEND_STRING("TAP");
        }
      }
      return false;
      break;
    
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

