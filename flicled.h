/**
 * @file flicled.h
 * @brief This file controls the LED ring of the flic-twist.
 */

#ifndef FLICLED_H
#define FLICLED_H

#include <stdbool.h>
#include <stdint.h>

#define COM_LED1u_TO_LED6u_PORT       gpioPortB
#define COM_LED1u_TO_LED6u_PIN        1
#define COM_LED7u_TO_LED12u_PORT       gpioPortB
#define COM_LED7u_TO_LED12u_PIN        2

#define LED1u_LED7u_PORT              gpioPortC
#define LED1u_LED7u_PIN               0
#define LED2u_LED8u_PORT              gpioPortC
#define LED2u_LED8u_PIN               1
#define LED3u_LED9u_PORT              gpioPortC
#define LED3u_LED9u_PIN               2
#define LED4u_LED10u_PORT             gpioPortC
#define LED4u_LED10u_PIN              3
#define LED5u_LED11u_PORT             gpioPortC
#define LED5u_LED11u_PIN              4
#define LED12u_LED6u_PORT             gpioPortC
#define LED12u_LED6u_PIN              5


#define MASK_LED1_TO_LED6       0x003F //0b 0000 0000 0011 1111
#define MASK_LED7_TO_LED12      0x0FC0 //0b 0000 1111 1100 0000
#define MASK_OFFSET             6U
#define MASK_OUT_OF_BOUNDS      ~(MASK_LED1_TO_LED6 | MASK_LED7_TO_LED12)

#define MASK_LED1               (1U << 0)
#define MASK_LED2               (1U << 1)
#define MASK_LED3               (1U << 2)
#define MASK_LED4               (1U << 3)
#define MASK_LED5               (1U << 4)
#define MASK_LED6               (1U << 5)

#define MASK_LED7               (1U << 6)
#define MASK_LED8               (1U << 7)
#define MASK_LED9               (1U << 8)
#define MASK_LED10              (1U << 9)
#define MASK_LED11              (1U << 10)
#define MASK_LED12              (1U << 11)


void flicled_init(void);
bool flicled_brightness(uint8_t brightness);
bool flicled_led(uint32_t ledMask);

#endif // FLICLED_H
