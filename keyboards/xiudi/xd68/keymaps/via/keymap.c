#include QMK_KEYBOARD_H

#define M_LOCK LGUI(LCTL(KC_Q)) // Lock Mac
#define W_LOCK LGUI(KC_L)       // Lock Win

// Tap dance declarations (These must go above the keymaps)
enum {
  HOMETILD = 0,
  ESCGRV,
  LBCB,
  RBCB,
};

#define TD_HT TD(HOMETILD)
#define TD_GRV TD(ESCGRV)
#define TD_LBCB TD(LBCB)
#define TD_RBCB TD(RBCB)

enum layer_number {
    _WIN = 0,
    _MAC,
    _BLANK,
    _FL,
};

enum custom_keycodes {
  APPLE = SAFE_RANGE,
  WIN,
  LOCK,
  ARROWFN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
     * |----------------------------------------------------------------|
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |App|Ctrl|FN |Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [_WIN] = LAYOUT_65_ansi(
        TD_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TD_HT,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD_LBCB, TD_RBCB, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_APP,  KC_RCTL, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _MAC: Mac Layer
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |   |       |   |
     * |---------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |Ctrl|Alt |Gui |                        |Gui|Alt|   |   |   |   |
     * `---------------------------------------------------------------'
     */
    [_MAC] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LALT, KC_LGUI,                         _______,                      KC_RGUI, KC_RALT, _______, _______, _______, _______
    ),

    /* Blank Template
     * ,----------------------------------------------------------------.
     * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |    |
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
     * |----------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |   |       |    |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |    |    |   |   |   |   |
     * `----------------------------------------------------------------'
     */
    [_BLANK] = LAYOUT_65_ansi(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
      ),

    /* Keymap _FL: Function Layer
     * ,---------------------------------------------------------------.
     * |~ `| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins|
     * |---------------------------------------------------------------|
     * |     |   |WIN|   |   |   |   |   |   |   |PWR|   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |MAC|   |   |   |   |   |   |   |LOCK|   |   |       |   |
     * |---------------------------------------------------------------|
     * |         |   |   |   |BL-|BL |BL+|   |   |   |   |Play |V+ |Mut|
     * |---------------------------------------------------------------|
     * |    |    |    |                        |   |   |   | <M|V- |M> |
     * `---------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        _______, _______, WIN,     _______, _______, _______, _______, _______, _______,  _______, KC_PWR,  _______, _______, _______, _______,
        _______, APPLE,   _______, _______, _______, _______, _______, _______, _______,  LOCK,    _______, _______,          _______, _______,
        _______,          _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______,  _______, ARROWFN, _______, KC_MPLY, KC_VOLU, KC_MUTE,
        _______, _______, _______,                            _______,                    _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};

// Tapdance definitions.
qk_tap_dance_action_t tap_dance_actions[] = {
  [HOMETILD] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_TILD),
  [ESCGRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
  [LBCB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),  // Left bracket on a single-tap, left brace on a double-tap
  [RBCB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),  // Right bracket on a single-tap, right brace on a double-tap
};

void led_blink(uint8_t count) {
    uint8_t n = 0;

    while (n < count) {
        backlight_toggle();
        wait_ms(500);
        backlight_toggle();
        wait_ms(500);
        n++;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int current_layer = biton32(default_layer_state);

    switch (keycode) {
        case APPLE:
            if ( record->event.pressed ) {
                SEND_STRING(" = () => ");
                if (current_layer == _MAC) {
                    return false;
                }
                set_single_persistent_default_layer(_MAC);
                led_blink(2);
            }
            return false;
            break;
        case WIN:
            if (current_layer == _WIN) {
                return false;
            }
            if ( record->event.pressed ) {
                set_single_persistent_default_layer(_WIN);
                led_blink(1);
            }
            return false;
            break;
        case LOCK:
            if (record->event.pressed) {
                if (current_layer == _WIN) {
                    tap_code16(W_LOCK);
                }
                if (current_layer == _MAC) {
                    tap_code16(M_LOCK);
                }
            }
            return false;
            break;
        case ARROWFN:
            if (record->event.pressed) {
                SEND_STRING(" = () => ");
            }
            return false;
            break;
        default:
            break;
    }
    return true;
};
