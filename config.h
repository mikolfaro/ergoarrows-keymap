/* Copyright 2021 Salicylic_acid3
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

#pragma once

/*
 * Use I2C for communication
 * and detect master using USB activity
 * because I'm using a Sparkfun Pro Micro USB-C
 */

#define USE_I2C
#define SPLIT_USB_DETECT

/* Set left hand as master */

#define MASTER_LEFT

/* Select hand configuration */

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 180

/* Space cadet */
/* Use shift, ctrl and alt to send parenthesis */
/* https://github.com/qmk/qmk_firmware/blob/master/docs/feature_space_cadet.md */


/* Sync RGB led state betweeh halves */
// #define RGBLIGddHT_SPLIT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

/* Remove unused animations */
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_TWINKLE

/** Enable layers indicator even if RGB is off */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
