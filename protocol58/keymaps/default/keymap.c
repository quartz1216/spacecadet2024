#include QMK_KEYBOARD_H

enum {
	RUN,
	LANG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_12x5(
		KC_0,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,							\
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,\
		KC_ESC,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_MINS,	KC_ENT,	\
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SCLN,	KC_QUOT,\
		KC_LCTL,	GUI_T(RUN), KC_LALT,	MO(1),		KC_SPC,		LT(0,LANG),	KC_LBRC,	KC_RBRC,	KC_EQL,		KC_GRV,		KC_BSLS,	KC_SLSH	\
	),
	[1] = LAYOUT_12x5(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,						\
		KC_PAUS,	KC_HOME,	KC_UP,		KC_END,		KC_PGUP,	_______,	_______,	_______,	_______,	_______,	_______,	_______,\
		KC_CAPS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_PGDN,	_______,	_______,	_______,	KC_F1,		KC_F2,		KC_F3,		KC_F4,	\
		_______,	KC_DEL,		KC_BSPC,	KC_ENT,		A(KC_F4),	_______,	_______,	_______,	KC_F5,		KC_F6,		KC_F7,		KC_F8,	\
		_______,	_______,	_______,	_______,	KC_MPLY,	_______,	_______,	_______,	KC_F9,		KC_F10,		KC_F11,		KC_F12	\
	),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LGUI_T(RUN):
			if (record->tap.count && record->event.pressed) {
				tap_code16(A(KC_SPC));
				return false;
			}
			break;
		case LT(0,LANG):
			if(record->tap.count && record -> event.pressed){
				tap_code16(C(KC_SPC));
			}else if(record->event.pressed){
				tap_code16(G(KC_SPC));
			}
			return false;
	}
	return true;
}
