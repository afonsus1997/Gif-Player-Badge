#ifndef TEST1_ILI9341_CORE_H
#define TEST1_ILI9341_CORE_H

//#include <stm32f10x.h>
//#include <stm32f10x_spi.h>
#include "delay.h"
#include "commands.h"
#include "commands2.h"
#include "dma.h"
#include "control.h"
#include <stdint.h>

uint16_t LCD_getWidth();
uint16_t LCD_getHeight();

void LCD_init();

void SPI_SendCmd8(uint8_t cmd, uint8_t n);

void LCD_setSpi8(void);
void LCD_setSpi16(void);

void LCD_setOrientation(uint8_t o);
void LCD_setAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

#endif //TEST1_ILI9341_CORE_H
