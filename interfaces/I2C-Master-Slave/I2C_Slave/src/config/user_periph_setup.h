/**
 ****************************************************************************************
 *
 * @file user_periph_setup.h
 *
 * @brief Peripherals setup header file.
 *
 * Copyright (C) 2015-2020 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 ****************************************************************************************
 */

#ifndef _USER_PERIPH_SETUP_H_
#define _USER_PERIPH_SETUP_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "uart.h"
#include "gpio.h"

/*
 * DEFINES
 ****************************************************************************************
 */
#define I2C_SLAVE_ADDRESS 			(0x30 >> 1)
#define I2C_TARGET_ADDRESS			I2C_SLAVE_ADDRESS
	
#define BUSY_WAIT_AMOUNT    0x100000

/****************************************************************************************/
/* UART2 configuration to print messages                                                */
/****************************************************************************************/
#define UART                        UART2
// Define UART2 Tx Pad
#if defined (__DA14531__)
#define UART2_TX_PORT           GPIO_PORT_0
#define UART2_TX_PIN            GPIO_PIN_3
#else
#define UART2_TX_PORT           GPIO_PORT_0
#define UART2_TX_PIN            GPIO_PIN_4
#endif

/****************************************************************************************/
/* LED configuration                                                                    */
/****************************************************************************************/
#if defined (__DA14531__)
#define LED_PORT                GPIO_PORT_0
#define LED_PIN                 GPIO_PIN_9

#define KEY_PORT                GPIO_PORT_0
#define KEY_PIN                 GPIO_PIN_11
#else

#define LED_PORT                GPIO_PORT_1
#define LED_PIN                 GPIO_PIN_0

#define KEY_PORT                GPIO_PORT_3
#define KEY_PIN                 GPIO_PIN_1
#endif

// Define UART2 Settings
#define UART2_BAUDRATE              UART_BAUDRATE_115200
#define UART2_DATABITS              UART_DATABITS_8
#define UART2_PARITY                UART_PARITY_NONE
#define UART2_STOPBITS              UART_STOPBITS_1
#define UART2_AFCE                  UART_AFCE_DIS
#define UART2_FIFO                  UART_FIFO_EN
#define UART2_TX_FIFO_LEVEL         UART_TX_FIFO_LEVEL_0
#define UART2_RX_FIFO_LEVEL         UART_RX_FIFO_LEVEL_0


/****************************************************************************************/
/* I2C configuration                                                                    */
/****************************************************************************************/
#if defined (__DA14531__)
// Define I2C Pins
#define I2C_SCL_PORT            GPIO_PORT_0
#define I2C_SCL_PIN             GPIO_PIN_6
#define I2C_SDA_PORT            GPIO_PORT_0
#define I2C_SDA_PIN             GPIO_PIN_7
#else
// Define I2C Pins
#define I2C_SCL_PORT            GPIO_PORT_0
#define I2C_SCL_PIN             GPIO_PIN_2
#define I2C_SDA_PORT            GPIO_PORT_0
#define I2C_SDA_PIN             GPIO_PIN_1
#endif

#define I2C_SLAVE_ADDRESS 			(0x30 >> 1)
#define I2C_TARGET_ADDRESS			I2C_SLAVE_ADDRESS

#define I2C_SPEED_MODE          I2C_SPEED_STANDARD    // Speed mode: I2C_SPEED_STANDARD (100 kbits/s), I2C_SPEED_FAST (400 kbits/s)
#define I2C_ADDRESS_MODE        I2C_ADDRESSING_7B     // Addressing mode: {I2C_ADDRESSING_7B, I2C_ADDRESSING_10B}

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief   Initializes application's peripherals and pins
 ****************************************************************************************
 */
void periph_init(void);

/**
 ****************************************************************************************
 * @brief Set gpio port function mode
 ****************************************************************************************
 */
void set_pad_functions(void);

#endif // _USER_PERIPH_SETUP_H_
