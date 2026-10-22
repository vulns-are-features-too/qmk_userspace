#include QMK_KEYBOARD_H

#define STAB     S(KC_TAB)
// home mods row
#define MT_A     LALT_T(KC_A)
#define MT_S     LGUI_T(KC_S)
#define MT_D     LCTL_T(KC_D)
#define MT_F     LSFT_T(KC_F)
#define MT_J     LSFT_T(KC_J)
#define MT_K     LCTL_T(KC_K)
#define MT_L     LGUI_T(KC_L)
#define MT_SCLN  LALT_T(KC_SCLN)
// layer taps
#define LT_Z     LT(NUM, KC_Z)
#define LT_SLSH  LT(MED, KC_SLSH)
// thumb cluster
#define NUM_ENT  LT(NUM, KC_ENT)
#define UTIL_SPC LT(UTIL, KC_SPC)
#define SYM_TAB  LT(SYMBOL, KC_TAB)
#define MED_BSPC LT(MED, KC_BSPC)
// UTIL layer home row mods
#define MT_4     LALT_T(KC_4)
#define MT_3     LGUI_T(KC_3)
#define MT_2     LCTL_T(KC_2)
#define MT_1     LSFT_T(KC_1)
#define MT_0     LSFT_T(KC_0)
#define MT_9     LCTL_T(KC_9)
#define MT_8     LALT_T(KC_8)
#define MT_7     LGUI_T(KC_7)
// Layer access
#define LT_NUM   LT(NUM, KC_F12)
#define LT_MED   LT(MED, KC_F12)
// mouse layer
#define CT_ENT   LCTL_T(KC_ENT)
#define SH_SPC   LSFT_T(KC_SPC)
#define SH_TAB   LSFT_T(KC_TAB)
#define CT_BSPC  LCTL_T(KC_BSPC)
#define TD_SCR   TD(TD_SCROLL_SCREENSHOT)
#define TD_ENT   TD(TD_ENTER_ESC)
#define TD_BTN45 TD(TD_MOUSE_45)
// misc
#define VM_HOST KC_RIGHT_CTRL

enum layers {
  BASE = 0,
  UTIL,
  SYMBOL,
  NAV,
  FN,
  NUM,
  MED,
  MOUSE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    /*******/  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        MT_A,     MT_S,     MT_D,     MT_F,     KC_G,    /*******/  KC_H,     MT_J,     MT_K,     MT_L,     MT_SCLN,
        LT_Z,     KC_X,     KC_C,     KC_V,     KC_B,    /*******/  KC_N,     KC_M,     KC_COMM,  KC_DOT,   LT_SLSH,
                        OSL(NAV),  NUM_ENT, UTIL_SPC,               SYM_TAB,  MED_BSPC, OSL(FN)
    ),

    [UTIL] = LAYOUT_split_3x5_3(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   /*******/  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        MT_4,     MT_3,     MT_2,     MT_1,     KC_5,    /*******/  KC_6,     MT_0,     MT_9,     MT_8,     MT_7,
        LT_NUM,   KC_F11,   KC_ESC,   KC_ENT,   KC_COLN, /*******/  KC_SPC,   KC_BSPC,  KC_DEL,   KC_HOME,  KC_END,
                            XXXXXXX,  _______,  _______,            CW_TOGG,  _______,  XXXXXXX
    ),

    [SYMBOL] = LAYOUT_split_3x5_3(
        VM_HOST,  KC_CIRC,  KC_PLUS,  KC_EQL,   KC_AT,   /*******/  KC_PSCR,  KC_LBRC,  KC_RBRC,  KC_ASTR,  XXXXXXX,
        KC_TILD,  KC_GRV,   KC_QUOT,  KC_DQUO,  KC_BSLS, /*******/  KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_HASH,  KC_EXLM,
        KC_LT,    KC_GT,    KC_MINS,  KC_UNDS,  KC_PERC, /*******/  KC_AMPR,  KC_LCBR,  KC_RCBR,  KC_DLR,   LT_MED,
                            XXXXXXX,  _______,  QK_LEAD,            _______,  _______,  XXXXXXX
    ),

    [NAV] = LAYOUT_split_3x5_3(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, /*******/  XXXXXXX,  KC_ENT,   KC_SPC,   MS_BTN4,  MS_BTN5,
        KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXXXXXX, /*******/  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_ESC,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(NAV), /*******/  KC_TAB,   KC_HOME,  KC_END,   KC_PGDN,  KC_PGUP,
                          TO(MOUSE),  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  TO(MOUSE)
    ),

    [FN] = LAYOUT_split_3x5_3(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX, /*******/  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX, /*******/  XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,
        KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX, /*******/  TO(FN),   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                          TO(MOUSE),  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  TO(MOUSE)
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_UNDS,  KC_ENT,   KC_EQL,   KC_NUM,  /*******/  KC_COMM,  KC_7,     KC_8,     KC_9,     KC_MINS,
        KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  KC_SPC,  /*******/  KC_BSPC,  KC_4,     KC_5,     KC_6,     KC_ENT,
        KC_SLSH,  KC_ASTR,  KC_PLUS,  KC_MINS,  TO(NUM), /*******/  KC_DOT,   KC_1,     KC_2,     KC_3,     KC_EQL,
                           TO(BASE),  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  TO(BASE)
    ),

    [MED] = LAYOUT_split_3x5_3(
        QK_BOOT,  _______,  KC_BRID,  KC_BRIU,  XXXXXXX, /*******/  XXXXXXX,  KC_BRID,  KC_BRIU,  _______,  XXXXXXX,
        XXXXXXX,  KC_MPLY,  KC_MPRV,  KC_MNXT,  XXXXXXX, /*******/  XXXXXXX,  KC_MPRV,  KC_MNXT,  KC_MPLY,  XXXXXXX,
        XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TO(MED), /*******/  TO(MED),  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,
                           TO(BASE),  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  TO(BASE)
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
        _______,  C(KC_A),  C(KC_Y),  C(KC_Z),  STAB,    /*******/  STAB,     C(KC_Z),  C(KC_Y),  C(KC_A),  _______,
        KC_ESC,   MS_BTN2,  MS_BTN3,  MS_BTN1,  KC_TAB,  /*******/  KC_TAB,   MS_BTN1,  MS_BTN3,  MS_BTN2,  KC_ESC,
        MS_WHLU,  MS_WHLD,  C(KC_C),  C(KC_V),  KC_ENT,  /*******/  KC_ENT,   C(KC_V),  C(KC_C),  MS_WHLD,  MS_WHLU,
                           TO(BASE),  CT_BSPC,  SH_SPC,             SH_SPC,   CT_BSPC,  TO(BASE)
    ),

};
// clang-format off

/***** COMBOS *****/

#define COMBO_COUNT 16
enum combo_events {
  // home row
  ESC_COMBO,
  COPY_COMBO,
  PASTE_COMBO,
  TERM_COPY_COMBO,
  TERM_PASTE_COMBO,
  // mouse top row
  HOME_COMBO,
  END_COMBO,
  TAB_NEXT_COMBO,
  TAB_PREV_COMBO,
  CTRL_F_COMBO,
  // mouse home row
  BTN4_COMBO,
  BTN5_COMBO,
  SCROLL_TOGGLE_COMBO,
  // mouse bottom row
  CUT_COMBO,
  TAB_NEW_COMBO,
  TAB_CLOSE_COMBO,
  //
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// base layer
const uint16_t PROGMEM esc_combo[]           = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM copy_combo[]          = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[]         = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM term_copy_combo[]     = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM term_paste_combo[]    = {KC_V, KC_X, COMBO_END};
// mouse top row
const uint16_t PROGMEM home_combo[]          = {C(KC_A), C(KC_Y), COMBO_END};
const uint16_t PROGMEM end_combo[]           = {C(KC_A), C(KC_Z), COMBO_END};
const uint16_t PROGMEM tab_next_combo[]      = {KC_ESC, C(KC_Z), COMBO_END};
const uint16_t PROGMEM tab_prev_combo[]      = {KC_ESC, C(KC_Y), COMBO_END};
const uint16_t PROGMEM ctrl_f_combo[]        = {KC_ESC, C(KC_A), COMBO_END};
// mouse home row
const uint16_t PROGMEM btn4_combo[]          = {KC_ESC, MS_BTN1, COMBO_END};
const uint16_t PROGMEM btn5_combo[]          = {KC_ESC, MS_BTN2, COMBO_END};
const uint16_t PROGMEM scroll_toggle_combo[] = {KC_ESC, MS_BTN3, COMBO_END};
// mouse bottom row
const uint16_t PROGMEM tab_new_combo[]       = {KC_ESC, C(KC_V), COMBO_END};
const uint16_t PROGMEM tab_close_combo[]     = {KC_ESC, C(KC_C), COMBO_END};
const uint16_t PROGMEM cut_combo[]           = {C(KC_C), C(KC_V), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // base layer
    [ESC_COMBO]           = COMBO(esc_combo, KC_ESC),
    [COPY_COMBO]          = COMBO(copy_combo, C(KC_C)),
    [PASTE_COMBO]         = COMBO(paste_combo, C(KC_V)),
    [TERM_COPY_COMBO]     = COMBO(term_copy_combo, C(S(KC_C))),
    [TERM_PASTE_COMBO]    = COMBO(term_paste_combo, C(S(KC_V))),
    // mouse top row
    [HOME_COMBO]          = COMBO(home_combo, KC_HOME),
    [END_COMBO]           = COMBO(end_combo, KC_END),
    [TAB_NEXT_COMBO]      = COMBO(tab_next_combo, C(KC_TAB)),
    [TAB_PREV_COMBO]      = COMBO(tab_prev_combo, C(STAB)),
    [CTRL_F_COMBO]        = COMBO(ctrl_f_combo, C(KC_F)),
    // mouse home row
    [BTN4_COMBO]          = COMBO(btn4_combo, MS_BTN4),
    [BTN5_COMBO]          = COMBO(btn5_combo, MS_BTN5),
    [SCROLL_TOGGLE_COMBO] = COMBO_ACTION(scroll_toggle_combo),
    // mouse bottom row
    [CUT_COMBO]           = COMBO(cut_combo, C(KC_X)),
    [TAB_NEW_COMBO]       = COMBO(tab_new_combo, C(KC_T)),
    [TAB_CLOSE_COMBO]     = COMBO(tab_close_combo, C(KC_W)),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case SCROLL_TOGGLE_COMBO:
    if (pressed) {
      tap_code(KC_NUM);
      wait_ms(10);
      tap_code(KC_NUM);
    }
    break;
  }
}

/***** LEADER MACROS *****/

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_B)) {
    SEND_STRING("#!/bin/bash\n\n");
  } else if (leader_sequence_one_key(KC_H)) {
    SEND_STRING("python3 -m http.server\n");
  } else if (leader_sequence_one_key(KC_L)) {
    SEND_STRING("nc -lnvp ");
  } else if (leader_sequence_one_key(KC_P)) {
    SEND_STRING("#!/usr/bin/python3\n\n");
  } else if (leader_sequence_two_keys(KC_D, KC_T)) {
    SEND_STRING("../../../../../../etc/passwd");
  } else if (leader_sequence_two_keys(KC_H, KC_P)) {
    SEND_STRING("python3 -m http.server ");
  } else if (leader_sequence_two_keys(KC_L, KC_H)) {
    SEND_STRING("127.0.0.1");
  } else if (leader_sequence_two_keys(KC_P, KC_S)) {
    SEND_STRING("ps aux --forest\n");
  } else if (leader_sequence_two_keys(KC_S, KC_S)) {
    SEND_STRING("ss -lntp\n");
  } else if (leader_sequence_two_keys(KC_X, KC_T)) {
    SEND_STRING("export TERM=xterm\n");
  } else if (leader_sequence_two_keys(KC_P, KC_B)) {
    SEND_STRING("php://filter/convert.base64-encode/resource=");
  } else if (leader_sequence_two_keys(KC_P, KC_T)) {
    SEND_STRING("python3 -c \"import pty; pty.spawn('/bin/bash')\"\n");
  } else if (leader_sequence_two_keys(KC_Z, KC_T)) {
    SEND_STRING(SS_LCTL("z"));
    SEND_STRING(SS_DELAY(100));
    SEND_STRING("stty raw -echo; fg\n\n");
    SEND_STRING(SS_DELAY(100));
    SEND_STRING("export TERM=xterm\n");
  } else if (leader_sequence_three_keys(KC_X, KC_S, KC_S)) {
    SEND_STRING("<script>alert(window.origin)</script>");
  } else if (leader_sequence_four_keys(KC_S, KC_U, KC_I, KC_D)) {
    SEND_STRING("find / -perm -4000 2>/dev/null\n");
  }
}

