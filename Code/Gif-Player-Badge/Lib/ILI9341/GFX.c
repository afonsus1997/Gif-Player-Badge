

//#include "commands.h"
#include "GFX.h"
#include "5x5_font.h"

SPI_HandleTypeDef hspi1;

void LCD_Draw_Char(char Character, uint8_t X, uint8_t Y, uint16_t Colour, uint16_t Size, uint16_t Background_Colour)
{
		uint8_t 	function_char;
    uint8_t 	i,j;

		function_char = Character;

    if (function_char < ' ') {
        Character = 0;
    } else {
        function_char -= 32;
		}

		char temp[CHAR_WIDTH];
		for(uint8_t k = 0; k<CHAR_WIDTH; k++)
		{
		temp[k] = font[function_char][k];
		}

    // Draw pixels
		LCD_Draw_Rectangle(X, Y, CHAR_WIDTH*Size, CHAR_HEIGHT*Size, Background_Colour);
    for (j=0; j<CHAR_WIDTH; j++) {
        for (i=0; i<CHAR_HEIGHT; i++) {
            if (temp[j] & (1<<i)) {
							if(Size == 1)
							{
              LCD_Draw_Pixel(X+j, Y+i, Colour);
							}
							else
							{
							LCD_Draw_Rectangle(X+(j*Size), Y+(i*Size), Size, Size, Colour);
							}
            }
        }
    }
}

/*Draws an array of characters (fonts imported from fonts.h) at X,Y location with specified font colour, size and Background colour*/
/*See fonts.h implementation of font on what is required for changing to a different font when switching fonts libraries*/
void LCD_Draw_Text(const char* Text, uint8_t X, uint8_t Y, uint16_t Colour, uint16_t Size, uint16_t Background_Colour)
{
    while (*Text) {
        LCD_Draw_Char(*Text++, X, Y, Colour, Size, Background_Colour);
        X += CHAR_WIDTH*Size;
    }
}


void LCD_Draw_Bitmap(const char* Image_Array, uint8_t Orientation)
{
	if(Orientation == SCREEN_HORIZONTAL_1)
	{
		LCD_Set_Rotation(SCREEN_HORIZONTAL_1);
		LCD_Set_Address(0,0,LCD_SCREEN_WIDTH,LCD_SCREEN_HEIGHT);

		HAL_GPIO_WritePin(TFT_CD_GPIO_Port, TFT_CD_Pin, SET);

		unsigned char Temp_small_buffer[BURST_MAX_SIZE];
		uint32_t counter = 0;
		for(uint32_t i = 0; i < LCD_SCREEN_WIDTH*LCD_SCREEN_HEIGHT*2/BURST_MAX_SIZE; i++)
		{
				for(uint32_t k = 0; k< BURST_MAX_SIZE; k++)
				{
					Temp_small_buffer[k]	= Image_Array[counter+k];
				}
				HAL_SPI_Transmit(&hspi1, (unsigned char*)Temp_small_buffer, BURST_MAX_SIZE, 10);
				counter += BURST_MAX_SIZE;
		}
	}
	else if(Orientation == SCREEN_HORIZONTAL_2)
	{
		LCD_Set_Rotation(SCREEN_HORIZONTAL_2);
		LCD_Set_Address(0,0,LCD_SCREEN_WIDTH,LCD_SCREEN_HEIGHT);

		HAL_GPIO_WritePin(TFT_CD_GPIO_Port, TFT_CD_Pin, SET);

		unsigned char Temp_small_buffer[BURST_MAX_SIZE];
		uint32_t counter = 0;
		for(uint32_t i = 0; i < LCD_SCREEN_WIDTH*LCD_SCREEN_HEIGHT*2/BURST_MAX_SIZE; i++)
		{
				for(uint32_t k = 0; k< BURST_MAX_SIZE; k++)
				{
					Temp_small_buffer[k]	= Image_Array[counter+k];
				}
				HAL_SPI_Transmit(&hspi1, (unsigned char*)Temp_small_buffer, BURST_MAX_SIZE, 10);
				counter += BURST_MAX_SIZE;
		}
	}
	else if(Orientation == SCREEN_VERTICAL_2)
	{
		LCD_Set_Rotation(SCREEN_VERTICAL_2);
		LCD_Set_Address(0,0,LCD_SCREEN_HEIGHT,LCD_SCREEN_WIDTH);

		HAL_GPIO_WritePin(TFT_CD_GPIO_Port, TFT_CD_Pin, SET);

		unsigned char Temp_small_buffer[BURST_MAX_SIZE];
		uint32_t counter = 0;
		for(uint32_t i = 0; i < LCD_SCREEN_WIDTH*LCD_SCREEN_HEIGHT*2/BURST_MAX_SIZE; i++)
		{
				for(uint32_t k = 0; k< BURST_MAX_SIZE; k++)
				{
					Temp_small_buffer[k]	= Image_Array[counter+k];
				}
				HAL_SPI_Transmit(&hspi1, (unsigned char*)Temp_small_buffer, BURST_MAX_SIZE, 10);
				counter += BURST_MAX_SIZE;
		}
	}
	else if(Orientation == SCREEN_VERTICAL_1)
	{
		LCD_Set_Rotation(SCREEN_VERTICAL_1);
		LCD_Set_Address(0,0,LCD_SCREEN_HEIGHT,LCD_SCREEN_WIDTH);

		HAL_GPIO_WritePin(TFT_CD_GPIO_Port, TFT_CD_Pin, SET);

		unsigned char Temp_small_buffer[BURST_MAX_SIZE];
		uint32_t counter = 0;
		for(uint32_t i = 0; i < LCD_SCREEN_WIDTH*LCD_SCREEN_HEIGHT*2/BURST_MAX_SIZE; i++)
		{
				for(uint32_t k = 0; k< BURST_MAX_SIZE; k++)
				{
					Temp_small_buffer[k]	= Image_Array[counter+k];
				}
				HAL_SPI_Transmit(&hspi1, (unsigned char*)Temp_small_buffer, BURST_MAX_SIZE, 10);
				counter += BURST_MAX_SIZE;
		}
	}
}




