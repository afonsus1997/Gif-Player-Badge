#ifndef TEST2_CONTROL_H
#define TEST2_CONTROL_H

#include "config.h"
#include "commands.h"
#include <stdint.h>
//#include <stm32f1xx_hal_gpio.h>
#include "main.h"

// <editor-fold desc="Functions">
//#define TFT_DC_SET      GPIO_SetBits(GPIOA, TFT_DC_PIN);
//#define TFT_DC_RESET    GPIO_ResetBits(GPIOA, TFT_DC_PIN);

#define TFT_RST_SET     HAL_GPIO_WritePin(TFT_RESET_PIN_GPIO_Port, TFT_RESET_PIN_Pin, SET);//GPIO_SetBits(GPIOA, TFT_RESET_PIN);
#define TFT_RST_RESET   HAL_GPIO_WritePin(TFT_RESET_PIN_GPIO_Port, TFT_RESET_PIN_Pin, RESET);//GPIO_ResetBits(GPIOA, TFT_RESET_PIN);

#define TFT_CS_SET      HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, SET);
#define TFT_CS_RESET    HAL_GPIO_WritePin(TFT_CS_GPIO_Port, TFT_CS_Pin, RESET);

#define TFT_LED_SET      //FUTURE IMPLEMENTATION
#define TFT_LED_RESET    //FUTURE IMPLEMENTATION
// </editor-fold>



#endif //TEST2_CONTROL_H
