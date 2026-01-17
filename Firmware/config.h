#pragma once

#define ENCODER_SWITCH_PIN GP7
#define ENCODER_SWITCH_ACTIVE_LOW

#define VENDOR_ID  0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001

#define MANUFACTURER "Gonzalo"
#define PRODUCT      "Macropad6"

#pragma once

#define MATRIX_ROWS 2
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { GP4, GP3 }
#define MATRIX_COL_PINS { GP0, GP26, GP2 }

#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW
