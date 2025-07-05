/*
Copyright 2022 x123 <@x123>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _APTv3,
    _QWERTZ,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ONESHOT,
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    WINDOWS,
    MACOS,
    OS_A,
    OS_S,
    OS_D,
    OS_F,
    OS_R,
    OS_SFT_R,
    OS_B,
    OS_V,
    OS_C,
    OS_X,
    OS_Y,
    OS_Z,
    OS_1,
    OS_2,
    OS_3,
    OS_4,
    OS_5,
    OS_6,
    OS_7,
    OS_8,
    OS_9,
    OS_0,
    OS_DEL,
    OS_BSPC,
    OS_ENT,
    OS_DEV,
    OS_WRDL,
    OS_WRDR,
    OS_STRT,
    OS_END,
    OS_CMNT,
    OS_FRMT,
    OS_AT,
    OS_TLDE,
    OS_PRGN,
    OS_DLN,
    OS_PIPE
};

// Tap dance enums
enum tap_dance_keycodes {
  BRCL = 0,
  BRCR
};

// Custom Keycodes
#define LCTL_KS LCTL_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LALT_KF LALT_T(KC_F)
#define RALT_KJ RALT_T(KC_J)
#define RGUI_KK RGUI_T(KC_K)
#define RCTL_KL RCTL_T(KC_L)

#define LCTL_KS LCTL_T(KC_S)
#define LGUI_KT LGUI_T(KC_T)
#define LALT_KH LALT_T(KC_H)
#define RALT_KN RALT_T(KC_N)
#define RGUI_KE RGUI_T(KC_E)
#define RCTL_KA RCTL_T(KC_A)

#define CKC_EURO C(A(KC_E))
#define CKC_DLLR S(KC_4)
#define ONESHOT OSL(_ONESHOT)
#define QWERTZ DF(_QWERTZ)
#define APTv3 DF(_APTv3)
#define MOVE_DN S(A(KC_DOWN))
#define MOVE_UP S(A(KC_UP))

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
const key_override_t *key_overrides[] = {
    &kp_1_key_override,
    &kp_2_key_override,
    &kp_3_key_override,
    &kp_4_key_override,
    &kp_5_key_override,
    &kp_6_key_override,
    &kp_7_key_override,
    &kp_8_key_override,
    &kp_9_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTZ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A, LCTL_KS, LGUI_KD, LALT_KF,    KC_G,                         KC_H, RALT_KJ, RGUI_KK, RCTL_KL,    KC_N, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MPLY,   LOWER,  KC_SPC,     KC_ENT,   RAISE, ONESHOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_APTv3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_W,    KC_G,    KC_D,    KC_F,    KC_B,                         KC_Q,    KC_L,    KC_U,    KC_O,    KC_Y,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_R, LCTL_KS, LGUI_KT, LALT_KH,    KC_K,                         KC_J, RALT_KN, RGUI_KE, RCTL_KA,    KC_I, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_X,    KC_C,    KC_M,    KC_P,    KC_V,                         KC_Z, KC_COMM, KC_DOT,  KC_NUHS, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MPLY,   LOWER,  KC_SPC,     KC_ENT,   RAISE, ONESHOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______,  OS_DEV,    OS_R,    OS_Z,                      _______,    OS_7,    OS_8,    OS_9, _______,  OS_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_PRGN,    OS_A,    OS_S,    OS_D,    OS_F,OS_SFT_R,                      _______,    OS_4,    OS_5,    OS_6, _______, OS_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    OS_Y,    OS_X,    OS_C,    OS_V,    OS_B,                         OS_0,    OS_1,    OS_2,    OS_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     OS_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   OS_AT, _______,CKC_EURO, _______, _______,                      OS_PIPE,TD(BRCL),TD(BRCR), KC_PAST, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_QUOT, KC_MINS, KC_LBRC, KC_SCLN, _______,                       KC_GRV, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  OS_DLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_EQL,CKC_DLLR, S(KC_0), KC_PSLS, OS_TLDE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,   MACOS, WINDOWS, _______,                      _______, OS_WRDL, MOVE_DN, MOVE_UP, OS_WRDR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,   APTv3,  QWERTZ, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ONESHOT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BRID, KC_BRIU, KC_MPRV, KC_MNXT, _______,                      _______, _______, _______, OS_FRMT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, OS_CMNT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

bool is_windows = false;
uint8_t mod_state;
bool is_backslash_registered = false;
bool is_program_switch_registered = false;

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
                clear_mods();
                if (is_windows) {
                  register_mods(MOD_BIT(KC_ALGR));
                  register_code(KC_MINS);
                } else {
                  register_mods(MOD_BIT(KC_LSFT));
                  register_mods(MOD_BIT(KC_LALT));
                  register_code(KC_7);
                }
                is_backslash_registered = true;
                return false;
              }
            } else {
              if (is_backslash_registered) {
                if (is_windows) {
                  unregister_code(KC_MINS);
                } else {
                  unregister_code(KC_7);
                }
                clear_mods();
                is_backslash_registered = false;
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
          case OS_SFT_R:
            if (record->event.pressed) {
              if (is_windows) {
                tap_code16(C(S(KC_R)));
              } else {
                tap_code16(G(S(KC_R)));
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
                register_code16(C(KC_Z));
              } else {
                register_code16(G(KC_Z));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_Z));
               } else {
                 unregister_code16(G(KC_Z));
               }
             }
            return false;
            break;
          case OS_Z:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(C(KC_Y));
              } else {
                register_code16(G(KC_Y));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_Y));
               } else {
                 unregister_code16(G(KC_Y));
               }
             }
            return false;
            break;
          case OS_1:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_1);
              } else {
                register_code(KC_1);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_1);
               } else {
                 unregister_code(KC_1);
               }
             }
            return false;
            break;
          case OS_2:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_2);
              } else {
                register_code(KC_2);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_2);
               } else {
                 unregister_code(KC_2);
               }
             }
            return false;
            break;
          case OS_3:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_3);
              } else {
                register_code(KC_3);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_3);
               } else {
                 unregister_code(KC_3);
               }
             }
            return false;
            break;
          case OS_4:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_4);
              } else {
                register_code(KC_4);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_4);
               } else {
                 unregister_code(KC_4);
               }
             }
            return false;
            break;
          case OS_5:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_5);
              } else {
                register_code(KC_5);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_5);
               } else {
                 unregister_code(KC_5);
               }
             }
            return false;
            break;
          case OS_6:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_6);
              } else {
                register_code(KC_6);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_6);
               } else {
                 unregister_code(KC_6);
               }
             }
            return false;
            break;
          case OS_7:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_7);
              } else {
                register_code(KC_7);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_7);
               } else {
                 unregister_code(KC_7);
               }
             }
            return false;
            break;
          case OS_8:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_8);
              } else {
                register_code(KC_8);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_8);
               } else {
                 unregister_code(KC_8);
               }
             }
            return false;
            break;
          case OS_9:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_9);
              } else {
                register_code(KC_9);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_9);
               } else {
                 unregister_code(KC_9);
               }
             }
            return false;
            break;
          case OS_0:
            if (record->event.pressed) {
              if (is_windows) {
                register_code(KC_KP_0);
              } else {
                register_code(KC_0);
              }
            } else {
               if (is_windows) {
                 unregister_code(KC_KP_0);
               } else {
                 unregister_code(KC_0);
               }
             }
            return false;
            break;
          case OS_DEV:
            if (record->event.pressed) {
              if (is_windows) {
                tap_code16(C(S(KC_I)));
              } else {
                tap_code16(G(A(KC_I)));
              }
            }
            return false;
            break;
          case OS_DEL:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(C(KC_DEL));
              } else {
                register_code16(A(KC_DEL));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_DEL));
               } else {
                 unregister_code16(A(KC_DEL));
               }
             }
            return false;
            break;
          case OS_BSPC:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(C(KC_BSPC));
              } else {
                register_code16(A(KC_BSPC));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_BSPC));
               } else {
                 unregister_code16(A(KC_BSPC));
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
                register_code16(C(KC_LEFT));
              } else {
                register_code16(A(KC_LEFT));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_LEFT));
               } else {
                 unregister_code16(A(KC_LEFT));
               }
             }
            return false;
            break;
          case OS_WRDR:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(C(KC_RGHT));
              } else {
                register_code16(A(KC_RGHT));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(KC_RGHT));
               } else {
                 unregister_code16(A(KC_RGHT));
               }
             }
            return false;
            break;
          case OS_AT:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(ALGR(KC_Q));
              } else {
                register_code16(A(KC_L));
              }
            } else {
               if (is_windows) {
                 unregister_code16(ALGR(KC_Q));
               } else {
                 unregister_code16(A(KC_L));
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
                tap_code(KC_HOME);
                tap_code(KC_HOME);
                register_code(KC_LSFT);
                tap_code(KC_END);
                tap_code(KC_RGHT);
                tap_code(KC_BSPC);
                unregister_code(KC_LSFT);
              } else {
                tap_code16(G(KC_RGHT));
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
                register_code(KC_LSFT);
                tap_code16(G(KC_RGHT));
                tap_code(KC_RGHT);
                tap_code(KC_BSPC);
                unregister_code(KC_LSFT);
              }
            }
            return false;
            break;
          case OS_PIPE:
            if (record->event.pressed) {
              if (is_windows) {
                register_code16(C(A(KC_NUBS)));
              } else {
                register_code16(A(KC_7));
              }
            } else {
               if (is_windows) {
                 unregister_code16(C(A(KC_NUBS)));
               } else {
                 unregister_code16(A(KC_7));
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
        }
      return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

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
    } else if (state->count == 3) {
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
    } else if (state->count >= 4) {
        tap_code(KC_NUBS);
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
    } else if (state->count == 3) {
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
    } else if (state->count >= 4) {
        tap_code16(S(KC_NUBS));
        reset_tap_dance(state);
    } else {
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [BRCL] = ACTION_TAP_DANCE_FN(brace_left),
    [BRCR] = ACTION_TAP_DANCE_FN(brace_right)
};

/* End tap dance */

/* Start combos */

const uint16_t PROGMEM double_space[] = {KC_SPC, KC_ENT, COMBO_END};
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
