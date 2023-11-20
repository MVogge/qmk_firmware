/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
  _WINDOWS,
  _LOWER,
  _RAISE,
  _ADJUST,
  _HELL,
  _HEAVEN,
  _EARTH
};

enum preonic_keycodes {
  WINDOWS = SAFE_RANGE,
  MACOS,
  LOWER,
  RAISE,
  HELL,
  HELL_ON,
  HELL_OFF,
  HEAVEN,
  BACKLIT,
  OS_A,
  OS_S,
  OS_D,
  OS_F,
  OS_R,
  OS_B,
  OS_V,
  OS_C,
  OS_X,
  OS_Y,
  OS_Z,
  OS_SFT_I,
  OS_SFT_M,
  OS_DEL,
  OS_BSPC,
  OS_ENT,
  OS_WRDL,
  OS_WRDR,
  OS_STRT,
  OS_END,
  OS_CMNT,
  OS_FRMT,
  OS_AT,
  OS_TLDE,
  OS_PRGN,
  OS_DLN
};

// Tap dance enums
enum tap_dance_keycodes {
  TD_BRCL = 0,
  TD_BRCR
};

// Custom Keycodes
#define LSFT_SPC LSFT_T(KC_SPC)
#define RSFT_SPC RSFT_T(KC_SPC)
#define MOVE_DN S(A(KC_DOWN))
#define MOVE_UP S(A(KC_UP))
#define CKC_DLLR S(KC_4)
#define CKC_EURO C(A(KC_E))
#define CKC_PIPE C(A(KC_NUBS))

// Key Overrides
const key_override_t kp_1_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_1, S(KC_1));
const key_override_t kp_2_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_2, S(KC_2));
const key_override_t kp_3_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_3, S(KC_3));
const key_override_t kp_4_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_4, S(KC_4));
const key_override_t kp_5_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_5, S(KC_5));
const key_override_t kp_6_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_6, S(KC_6));
const key_override_t kp_7_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_7, S(KC_7));
const key_override_t kp_8_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_8, S(KC_8));
const key_override_t kp_9_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_9, S(KC_9));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &kp_1_key_override,
    &kp_2_key_override,
    &kp_3_key_override,
    &kp_4_key_override,
    &kp_5_key_override,
    &kp_6_key_override,
    &kp_7_key_override,
    &kp_8_key_override,
    &kp_9_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Windows
 * ,-----------------------------------------------------------------------------------------------.
 * |Ply/Pse|   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Esc   |   Q   |   W   |   E   |   R   |   T   |   Z   |   U   |   I   |   O   |   P   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Tab   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   #   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Hell  |   Y   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   -   | Heaven|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   <   | GUI   | Alt   | Lower |Spc/Sft|Spc/Sft| Raise |  Left |  Down |   Up  | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_WINDOWS] = LAYOUT_preonic_grid(
  KC_MPLY, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_NUHS, KC_ENT,
    HELL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, HEAVEN,
  KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER,LSFT_SPC,RSFT_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |       |KC_BRID|KC_BRIU|KC_MPRV|KC_MNXT|       |       |       |       |       |       | OS_DEL|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |OS_SFTI| OS_R  |       |  OS_Z |  KP_7 |  KP_8 |  KP_9 |  Del  |OS_BSPC|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |OS_PRGN| OS_A  | OS_S  | OS_D  | OS_F  |OS_SFTM|       |  KP_4 |  KP_5 |  KP_6 | Bksp  | OS_ENT|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | OS_Y  | OS_X  | OS_C  | OS_V  | OS_B  |  KP_0 |  KP_1 |  KP_2 |  KP_3 | Enter |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |OS_WRDL|MOVE_DN|MOVE_UP|OS_WRDR|
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, KC_BRID, KC_BRIU, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______,  OS_DEL,
  _______, _______, _______,OS_SFT_I,    OS_R, _______,    OS_Z, KC_KP_7, KC_KP_8, KC_KP_9,  KC_DEL, OS_BSPC,
  OS_PRGN,    OS_A,    OS_S,    OS_D,    OS_F,OS_SFT_M, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_BSPC,  OS_ENT,
  _______,    OS_Y,    OS_X,    OS_C,    OS_V,    OS_B, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3,  KC_ENT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, OS_WRDL, MOVE_DN, MOVE_UP, OS_WRDR
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   @   |       |   €   |       |       |       |   Ü   |       |   Ö   |       | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   Ä   |   ẞ   |       |       |       |   ^   |  [{(  |  )}]  |   *   |   +   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   ´   |   $   |   =   |  /\   |   ~   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   |   |       |       |       |       |       |       |OS_STRT|KC_WH_D|KC_WH_U|OS_END |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,
  _______,   OS_AT, _______,CKC_EURO, _______, _______, _______, KC_LBRC, _______, KC_SCLN, _______,  OS_DLN,
  _______, KC_QUOT, KC_MINS, _______, _______, _______,  KC_GRV,TD(TD_BRCL),TD(TD_BRCR), KC_PAST, KC_PPLS,  KC_ENT,
  _______, _______, _______, _______, _______, _______,  KC_EQL,CKC_DLLR, S(KC_0), KC_PSLS, OS_TLDE, _______,
  _______,CKC_PIPE, _______, _______, _______, _______, _______, _______, OS_STRT, KC_PGDN ,KC_PGUP,  OS_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------.
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Reset | Debug |       |       |       |       |       |       |       |       |       |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |BL_TOGG|       | MacOS |Windows|       |       |       |       |OS_FRMT|       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |BL_STEP|       |       |       |       |       |       |       |OS_CMNT|       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,
  _______, RGB_TOG, _______,   MACOS, WINDOWS, _______, _______, _______, _______, OS_FRMT, _______, _______,
  _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, OS_CMNT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Hell
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |MS_BTN4| MS_U  |MS_BTN5|       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | MS_L  | MS_D  | MS_R  |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |LYR_OFF|MS_WH_L|MS_WH_D|MS_WH_U|MS_WH_R|       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |LYR_ON |MS_ACL0|MS_BTN1|MS_BTN2|       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_HELL] = LAYOUT_preonic_grid(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   KC_ESC, XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 HELL_OFF, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, HELL_ON, KC_ACL0, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Heaven
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_HEAVEN] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Earth
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_EARTH] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool is_windows = true;
uint8_t mod_state;
bool is_backslash_registered = false;
bool is_program_switch_registered = false;
bool keep_hell_on = false;

//check numlock and turn on when needed
static void check_numlock(void) {
    led_t led_state = host_keyboard_led_state();
    if (is_windows && !(led_state.num_lock)){
        tap_code(KC_NUM);
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
        case WINDOWS:
          if (record->event.pressed) {
            is_windows = true;
          }
          return false;
          break;
        case MACOS:
          if (record->event.pressed) {
            is_windows = false;
          }
          return false;
          break;
        case KC_PSLS:
          if (record->event.pressed) {
            if ((mod_state == MOD_BIT(KC_LSFT)) | (mod_state == MOD_BIT(KC_RSFT))) {
              if (is_windows) {
                clear_mods();
                register_mods(MOD_BIT(KC_ALGR));
                register_code(KC_MINS);
              } else {
                register_mods(MOD_MASK_SA);
                register_code(KC_7);
              }
              is_backslash_registered = true;
              return false;
            }
          } else {
            if (is_backslash_registered) {
              if (is_windows) {
                unregister_code(KC_MINS);
                unregister_mods(MOD_BIT(KC_ALGR));
              } else {
                unregister_code(KC_7);
                unregister_mods(MOD_MASK_SA);
              }
              is_backslash_registered = false;
              register_mods(MOD_BIT(KC_LSFT));
              return false;
            }
          }
          return true;
          break;
        case OS_A:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_A));
            } else {
              tap_code16(G(KC_A));
            }
          }
          return false;
          break;
        case OS_S:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_S));
            } else {
              tap_code16(G(KC_S));
            }
          }
          return false;
          break;
        case OS_D:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_D));
            } else {
              tap_code16(G(KC_D));
            }
          }
          return false;
          break;
        case OS_F:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_F));
            } else {
              tap_code16(G(KC_F));
            }
          }
          return false;
          break;
        case OS_R:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_R));
            } else {
              tap_code16(G(KC_R));
            }
          }
          return false;
          break;
        case OS_B:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_B));
            } else {
              tap_code16(G(KC_B));
            }
          }
          return false;
          break;
        case OS_V:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_V));
            } else {
              tap_code16(G(KC_V));
            }
          }
          return false;
          break;
        case OS_C:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_C));
            } else {
              tap_code16(G(KC_C));
            }
          }
          return false;
          break;
        case OS_X:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_X));
            } else {
              tap_code16(G(KC_X));
            }
          }
          return false;
          break;
        case OS_Y:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_Z));
            } else {
              tap_code16(G(KC_Z));
            }
          }
          return false;
          break;
        case OS_Z:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_Y));
            } else {
              tap_code16(G(KC_Y));
            }
          }
          return false;
          break;
        case OS_SFT_I:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(S(KC_I)));
            } else {
              tap_code16(G(S(KC_I)));
            }
          }
          return false;
          break;
        case OS_SFT_M:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(S(KC_M)));
            } else {
              tap_code16(G(S(KC_M)));
            }
          }
          return false;
          break;
        case OS_DEL:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_DEL));
            } else {
              tap_code16(A(KC_DEL));
            }
          }
          return false;
          break;
        case OS_BSPC:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_BSPC));
            } else {
              tap_code16(A(KC_BSPC));
            }
          }
          return false;
          break;
        case OS_ENT:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code(KC_END);
              tap_code(KC_ENT);
            } else {
              tap_code16(G(KC_RGHT));
              tap_code(KC_ENT);
            }
          }
          return false;
          break;
        case OS_WRDL:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_LEFT));
            } else {
              tap_code16(A(KC_LEFT));
            }
          }
          return false;
          break;
        case OS_WRDR:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_RGHT));
            } else {
              tap_code16(A(KC_RGHT));
            }
          }
          return false;
          break;
        case OS_AT:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(ALGR(KC_Q));
            } else {
              tap_code16(A(KC_L));
            }
          }
          return false;
          break;
        case OS_FRMT:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(A(KC_L)));
            } else {
              tap_code16(G(A(KC_L)));
            }
          }
          return false;
          break;
        case OS_CMNT:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(C(KC_PSLS));
            } else {
              tap_code16(G(KC_PSLS));
            }
          }
          return false;
          break;
        case OS_TLDE:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code16(ALGR(KC_RBRC));
            } else {
              tap_code16(A(KC_N));
            }
          }
          return false;
          break;
        case OS_STRT:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code(KC_HOME);
            } else {
              tap_code16(G(KC_LEFT));
            }
          }
          return false;
          break;
        case OS_END:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code(KC_END);
            } else {
              tap_code16(G(KC_RGHT));
            }
          }
          return false;
          break;
        case OS_PRGN:
          if (record->event.pressed) {
            if (is_windows) {
              register_code(KC_LALT);
              tap_code(KC_TAB);
            } else {
              register_code(KC_LGUI);
              tap_code(KC_TAB);
            }
            is_program_switch_registered = true;
          }
          return false;
          break;
        case OS_DLN:
          if (record->event.pressed) {
            if (is_windows) {
              tap_code(KC_END);
              register_code(KC_LSFT);
              tap_code(KC_UP);
              tap_code(KC_END);
              tap_code(KC_BSPC);
              unregister_code(KC_LSFT);
            } else {
              tap_code16(G(KC_RGHT));
              register_code(KC_LSFT);
              tap_code(KC_UP);
              tap_code16(G(KC_RGHT));
              tap_code(KC_BSPC);
              unregister_code(KC_LSFT);
            }
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            check_numlock();
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);

            if (is_program_switch_registered) {
              if (is_windows) {
                unregister_code(KC_LALT);
              } else {
                unregister_code(KC_LGUI);
              }
              is_program_switch_registered = false;
            }
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case HELL:
          if (record->event.pressed) {
            layer_on(_HELL);
            update_tri_layer(_HELL, _HEAVEN, _EARTH);
          } else {
            if (!keep_hell_on) {
              layer_off(_HELL);
              update_tri_layer(_HELL, _HEAVEN, _EARTH);
            }
          }
          return false;
          break;
        case HELL_ON:
          if (record->event.pressed) {
            layer_on(_HELL);
            update_tri_layer(_HELL, _HEAVEN, _EARTH);
            keep_hell_on = true;
          }
          return false;
          break;
        case HELL_OFF:
          if (record->event.pressed) {
            layer_off(_HELL);
            update_tri_layer(_HELL, _HEAVEN, _EARTH);
            keep_hell_on = false;
          }
          return false;
          break;
        case HEAVEN:
          if (record->event.pressed) {
            layer_on(_HEAVEN);
            update_tri_layer(_HELL, _HEAVEN, _EARTH);
          } else {
            layer_off(_HEAVEN);
            update_tri_layer(_HELL, _HEAVEN, _EARTH);
          }
          return false;
          break;
      }
    return true;
};

/* Start tap dance */

void brace_left(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
        tap_code(KC_8);
        unregister_code(KC_LSFT);
        reset_tap_dance(state);
    } else if (state->count == 2) {
        if (is_windows) {
            register_code(KC_LCTL);
            register_code(KC_RALT);
            tap_code(KC_7);
            unregister_code(KC_LCTL);
            unregister_code(KC_RALT);
        } else {
            register_code(KC_LALT);
            tap_code(KC_8);
            unregister_code(KC_LALT);
        }
        reset_tap_dance(state);
    } else if (state->count >= 3) {
        if (is_windows) {
            register_code(KC_LCTL);
            register_code(KC_RALT);
            tap_code(KC_8);
            unregister_code(KC_LCTL);
            unregister_code(KC_RALT);
        } else {
            register_code(KC_LALT);
            tap_code(KC_5);
            unregister_code(KC_LALT);
        }
        reset_tap_dance(state);
    } else {
        reset_tap_dance(state);
    }
}

void brace_right(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
        tap_code(KC_9);
        unregister_code(KC_LSFT);
        reset_tap_dance(state);
    } else if (state->count == 2) {
        if (is_windows) {
            register_code(KC_LCTL);
            register_code(KC_RALT);
            tap_code(KC_0);
            unregister_code(KC_LCTL);
            unregister_code(KC_RALT);
        } else {
            register_code(KC_LALT);
            tap_code(KC_9);
            unregister_code(KC_LALT);
        }
        reset_tap_dance(state);
    } else if (state->count >= 3) {
        if (is_windows) {
            register_code(KC_LCTL);
            register_code(KC_RALT);
            tap_code(KC_9);
            unregister_code(KC_LCTL);
            unregister_code(KC_RALT);
        } else {
            register_code(KC_LALT);
            tap_code(KC_6);
            unregister_code(KC_LALT);
        }
        reset_tap_dance(state);
    } else {
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCL] = ACTION_TAP_DANCE_FN(brace_left),
    [TD_BRCR] = ACTION_TAP_DANCE_FN(brace_right)
};

/* End tap dance */

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code_delay(KC_VOLD, 10);
    } else {
        tap_code_delay(KC_VOLU, 10);
    }
    return false;
}

/* Start combos */

const uint16_t PROGMEM double_space[] = {LSFT_SPC, RSFT_SPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(double_space, CW_TOGG),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SLSH:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

/* End combos */

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_SPC:
        case RSFT_SPC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

void matrix_scan_user(void) {

}
