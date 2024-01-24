/**
 * @file flicled.h
 * @brief This file controls the LED ring of the flic-twist.
 */

#include "flicled.h"
#include "app_log.h"

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_timer.h"

#define PWM_PEROID 0xFFFF       // (38.4MHz/0xFFFF) = 585.9464408Hz
#define PWM_DUTY_CYCLE 0x3FFF   // 25% of PWM_PEROID
#define PWM_SYNC_TIMER 0x7FFF   // 50% of PWM_PEROID

static uint32_t activeLEDMask;

/**
 * @brief Initializes the flicled module.
 *
 * This function initializes the GPIO, TIMER1, and TIMER2 peripherals
 * required for controlling the flicled module. It configures TIMER1 and
 * TIMER2 in PWM mode and sets the desired PWM period and duty cycle.
 * It also routes the CC0 output of TIMER1 and TIMER2 to the corresponding
 * GPIO pins.
 */
void flicled_init(void)
{
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;

  // Enable clock for GPIO, TIMER1 and TIMER2
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_TIMER1, true);
  CMU_ClockEnable(cmuClock_TIMER2, true);

  timerInit.enable = false;             // Don't start counter on initialisation
  timerCCInit.mode = timerCCModePWM;    // PWM mode

  // TIMER1 configuration
  TIMER_Init(TIMER1, &timerInit);
  TIMER_InitCC(TIMER1, 0, &timerCCInit);

  TIMER_TopSet(TIMER1, PWM_PEROID);
  TIMER_CompareSet(TIMER1, 0, PWM_DUTY_CYCLE);

  // Configure and route CC0 output to PB01
  GPIO_PinModeSet(COM_LED1u_TO_LED6u_PORT, COM_LED1u_TO_LED6u_PIN, gpioModePushPull, 0);
  GPIO->TIMERROUTE[1].ROUTEEN = GPIO_TIMER_ROUTEEN_CC0PEN;
  GPIO->TIMERROUTE[1].CC0ROUTE = (COM_LED1u_TO_LED6u_PORT
      << _GPIO_TIMER_CC0ROUTE_PORT_SHIFT)
      | (COM_LED1u_TO_LED6u_PIN << _GPIO_TIMER_CC0ROUTE_PIN_SHIFT);

  TIMER_Enable(TIMER1, true);

  // TIMER1 compare event interrupts
  TIMER_IntEnable(TIMER1, TIMER_IF_OF | TIMER_IF_CC0);
  NVIC_EnableIRQ(TIMER1_IRQn);

  // TIMER2 configuration
  TIMER_Init(TIMER2, &timerInit);
  TIMER_InitCC(TIMER2, 0, &timerCCInit);

  TIMER_TopSet(TIMER2, PWM_PEROID);
  TIMER_CompareSet(TIMER2, 0, PWM_DUTY_CYCLE);

  // Configure and route CC0 output to PB01
  GPIO_PinModeSet(COM_LED7u_TO_LED12u_PORT, COM_LED7u_TO_LED12u_PIN, gpioModePushPull, 0);
  GPIO->TIMERROUTE[2].ROUTEEN = GPIO_TIMER_ROUTEEN_CC0PEN;
  GPIO->TIMERROUTE[2].CC0ROUTE = (COM_LED7u_TO_LED12u_PORT
      << _GPIO_TIMER_CC0ROUTE_PORT_SHIFT)
      | (COM_LED7u_TO_LED12u_PIN << _GPIO_TIMER_CC0ROUTE_PIN_SHIFT);

  TIMER_Enable(TIMER2, true);

  // TIMER2 compare event interrupts
  TIMER_IntEnable(TIMER2, TIMER_IF_OF | TIMER_IF_CC0);
  NVIC_EnableIRQ(TIMER2_IRQn);

  // Dirty-sync TIMER2 at 50% duty-cycle of TIMER1
  TIMER_CounterSet(TIMER1, 0x0);
  TIMER_CounterSet(TIMER2, (PWM_SYNC_TIMER + 19)); // Manually tuned

  // Pull LEDs high to turn them off (default)
  bool off = true;
  GPIO_PinModeSet(LED12u_LED6u_PORT, LED12u_LED6u_PIN, gpioModePushPull, off);
  GPIO_PinModeSet(LED1u_LED7u_PORT, LED1u_LED7u_PIN, gpioModePushPull, off);
  GPIO_PinModeSet(LED2u_LED8u_PORT, LED2u_LED8u_PIN, gpioModePushPull, off);
  GPIO_PinModeSet(LED3u_LED9u_PORT, LED3u_LED9u_PIN, gpioModePushPull, off);
  GPIO_PinModeSet(LED4u_LED10u_PORT, LED4u_LED10u_PIN, gpioModePushPull, off);
  GPIO_PinModeSet(LED5u_LED11u_PORT, LED5u_LED11u_PIN, gpioModePushPull, off);

}

/**
 * @brief Sets the brightness of the flicled.
 *
 * This function sets the brightness of the flicled by adjusting the compare values of TIMER1 and TIMER2.
 * The brightness value should be between 0 and 100, where 0 represents the lowest brightness and 100 represents the highest brightness.
 *
 * @param brightness The brightness value to set.
 * @return true if the brightness value is valid and successfully set, false otherwise.
 */
bool flicled_brightness(uint8_t brightness)
{
    if (brightness <= 100)
    {
        TIMER_CompareSet(TIMER1, 0, (TIMER_TopGet(TIMER1) * brightness) / 100);
        TIMER_CompareSet(TIMER2, 0, (TIMER_TopGet(TIMER2) * brightness) / 100);
        return true;
    }
    else
    {
        return false;
    }
}

bool flicled_led(uint32_t ledNumber)
{
  if ((ledNumber & MASK_OUT_OF_BOUNDS))
  {
    return false;
  }
  else
  {
    activeLEDMask = ledNumber;
    return true;
  }
}

void TIMER1_IRQHandler(void)
{
  // Acknowledge the interrupt
  uint32_t flags = TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);

  // Turn LEDs on when timer overflows and off on CC0
  if (flags & TIMER_IF_OF)
  {
    GPIO->P_CLR[gpioPortC].DOUT = (activeLEDMask & MASK_LED1_TO_LED6);
  }
  else
  {
    GPIO->P_SET[gpioPortC].DOUT = MASK_LED1_TO_LED6;
  }

}

void TIMER2_IRQHandler(void)
{
  // Acknowledge the interrupt
  uint32_t flags = TIMER_IntGet(TIMER2);
  TIMER_IntClear(TIMER2, flags);

  // Turn LEDs on when timer overflows and off on CC0
  if (flags & TIMER_IF_OF)
  {
    GPIO->P_CLR[gpioPortC].DOUT = ((activeLEDMask & MASK_LED7_TO_LED12) >> MASK_OFFSET);
  }
  else
  {
    GPIO->P_SET[gpioPortC].DOUT = (MASK_LED7_TO_LED12 >> MASK_OFFSET);
  }
}
