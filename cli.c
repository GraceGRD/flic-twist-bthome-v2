/***************************************************************************//**
 * @file
 * @brief cli bare metal examples functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include <string.h>
#include "sl_bt_api.h"
#include "sl_cli.h"
#include "sl_cli_instances.h"
#include "sl_cli_arguments.h"
#include "sl_cli_handles.h"

#include "app_log.h"

#include "cli.h"
#include "flicled.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

/*******************************************************************************
 *********************   LOCAL FUNCTION PROTOTYPES   ***************************
 ******************************************************************************/
void reset(sl_cli_command_arg_t *arguments);
void dim(sl_cli_command_arg_t *arguments);
void led(sl_cli_command_arg_t *arguments);
void animation(sl_cli_command_arg_t *arguments);

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/
static const sl_cli_command_info_t cmd_reset = \
  SL_CLI_COMMAND(reset,
                 "RESET",
                 "instruction: Resets the microcontroller",
                 { SL_CLI_ARG_WILDCARD, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cmd_dim = \
  SL_CLI_COMMAND(dim,
                 "DIM",
                 "instruction: percentage as integer [0 to 100]",
                 { SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cmd_led = \
  SL_CLI_COMMAND(led,
                 "LED",
                 "instruction: Turn on LED(s) through a bit-mask. "
                 "[0b 0000 1111 1111 1111] (use uint16 or hex as input)",
                 { SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cmd_animation = \
  SL_CLI_COMMAND(animation,
                 "ANIMATION",
                 "instruction: Run animation (rotate). ",
                 { SL_CLI_ARG_STRING, SL_CLI_ARG_END, });

static sl_cli_command_entry_t a_table[] = {
  { "reset", &cmd_reset, false},
  { "dim", &cmd_dim, false},
  { "led", &cmd_led, false},
  { "animation", &cmd_animation, false},
  { NULL, NULL, false },
};

static sl_cli_command_group_t a_group = {
  { NULL },
  false,
  a_table
};

/*******************************************************************************
 *************************  EXPORTED VARIABLES   *******************************
 ******************************************************************************/
sl_cli_command_group_t *command_group = &a_group;

/*******************************************************************************
 ***************************   LOCAL FUNCTIONS   *******************************
 ******************************************************************************/
void reset(sl_cli_command_arg_t *arguments)
{
  (void)arguments;

  app_log("<ACK>\r\n");
  NVIC_SystemReset();
}

void dim(sl_cli_command_arg_t *arguments)
{
  uint8_t ledBrightness = sl_cli_get_argument_uint8(arguments, 0);
  app_log("<%s>\r\n", flicled_brightness(ledBrightness) ? "ACK" : "NACK");
}

void led(sl_cli_command_arg_t *arguments)
{
  uint16_t ledNumber = sl_cli_get_argument_uint16(arguments, 0);
  app_log("<%s>\r\n", flicled_led(ledNumber) ? "ACK" : "NACK");
}

void animation(sl_cli_command_arg_t *arguments)
{
  char *command;
  command = sl_cli_get_argument_string(arguments, 0);

  if (strcmp(command, "rotate") == 0)
  {
    flicled_animation_rotate();
    app_log("<ACK>\r\n");
  }
  else
  {
    app_log("<NACK>\r\n");
  }

}

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/*******************************************************************************
 * Initialise CLI example.
 ******************************************************************************/
void cli_app_init(void)
{
  bool status;

  status = sl_cli_command_add_command_group(sl_cli_cli_handle, command_group);
  EFM_ASSERT(status);

  app_log("\r\n--------------------------------------------------\r\n");
  app_log("------ Flic Twist smart button BTHome v2 CLI -----\r\n");
  app_log("--------------------------------------------------\r\n");
}
