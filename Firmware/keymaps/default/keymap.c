#include QMK_KEYBOARD_H
#define ENCODER_HOLD_TIME 700

static uint16_t encoder_timer = 0;
static bool encoder_layer_active = false;

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
    
};

enum layers {
    _BASE,
    _VOL
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_1:
            if (record->event.pressed) {
                tap_code16(C(S(KC_F12)));          
            }
            return false;
        break;
        case MACRO_2:
            if (record->event.pressed){
                tap_code16(C(S(KC_F11)));   
            }
            return false;
        break;
        case MACRO_3:
            if (record->event.pressed){
                tap_code16(C(S(KC_F10)));      
            }
            return false;
        break;
        case MACRO_4:
            if (record->event.pressed){
                tap_code16(C(S(KC_F9)));      
            }
            return false;
        break;
        case MACRO_5:
            if (record->event.pressed){
                tap_code16(C(S(KC_F8)));      
            }
            return false;
        break;
        case MACRO_6:
            if (record->event.pressed){
                tap_code16(C(S(KC_F7)));      
            }
            return false;
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_2x3(
        MACRO_1, MACRO_2, MACRO_3,
        MACRO_4, MACRO_5, MACRO_6
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(_VOL)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }else{
        if(clockwise) {
            tap_code(KC_EQL);
        } else {
            tap_code(KC_MINS);
        }
    }
    return true;
}
#endif

bool encoder_button_user(uint8_t index, bool pressed) {
    if (pressed) {
        encoder_timer = timer_read();
        encoder_layer_active = false;
    } else {
        if (!encoder_layer_active) {
            tap_code(KC_MUTE);   
        }
        layer_off(_VOL);
    }
    return true;
}

void matrix_scan_user(void) {
    if (encoder_timer && !encoder_layer_active) {
        if (timer_elapsed(encoder_timer) > ENCODER_HOLD_TIME) {
            layer_on(_VOL);
            encoder_layer_active = true;
        }
    }
}

/*
#ifdef ENCODER_ENABLE
encoder_map_t PROGMEM encoders[] = {
    [0] = { .pin_a = GP28, .pin_b = GP29, .cfg = ENCODER_CCW_CW }
};
#endif
*/
