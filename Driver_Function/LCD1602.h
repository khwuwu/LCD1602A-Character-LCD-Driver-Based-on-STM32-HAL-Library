#ifndef __LCD1602_H__
#define __LCD1602_H__
#include "main.h"

#define LCD1602_RS_PIN   GPIO_PIN_7
#define LCD1602_RW_PIN   GPIO_PIN_1
#define LCD1602_EN_PIN   GPIO_PIN_0

#define LCD1602_RS_PORT  GPIOE
#define LCD1602_RW_PORT  GPIOB
#define LCD1602_EN_PORT  GPIOB

#define LCD1602_RS_C HAL_GPIO_WritePin(LCD1602_RS_PORT,LCD1602_RS_PIN,GPIO_PIN_RESET)
#define LCD1602_RS_D HAL_GPIO_WritePin(LCD1602_RS_PORT,LCD1602_RS_PIN,GPIO_PIN_SET)
#define LCD1602_RW_R HAL_GPIO_WritePin(LCD1602_RW_PORT,LCD1602_RW_PIN,GPIO_PIN_SET)
#define LCD1602_RW_W HAL_GPIO_WritePin(LCD1602_RW_PORT,LCD1602_RW_PIN,GPIO_PIN_RESET)
#define LCD1602_EN_H HAL_GPIO_WritePin(LCD1602_EN_PORT,LCD1602_EN_PIN,GPIO_PIN_SET)
#define LCD1602_EN_L HAL_GPIO_WritePin(LCD1602_EN_PORT,LCD1602_EN_PIN,GPIO_PIN_RESET)

#define LCD_D0_PORT GPIOA
#define LCD_D1_PORT GPIOA
#define LCD_D2_PORT GPIOA
#define LCD_D3_PORT GPIOA
#define LCD_D4_PORT GPIOA
#define LCD_D5_PORT GPIOA
#define LCD_D6_PORT GPIOA
#define LCD_D7_PORT GPIOA

#define LCD_D0_PIN GPIO_PIN_0
#define LCD_D1_PIN GPIO_PIN_1
#define LCD_D2_PIN GPIO_PIN_2
#define LCD_D3_PIN GPIO_PIN_3
#define LCD_D4_PIN GPIO_PIN_4
#define LCD_D5_PIN GPIO_PIN_5
#define LCD_D6_PIN GPIO_PIN_6
#define LCD_D7_PIN GPIO_PIN_7

void LCD_WritePin(uint8_t data);
void LCD_Init(void);
void LCD_WriteCmd(uint16_t DATA);
void LCD_WriteData(uint16_t DATA);
void LCD_WriteChar(unsigned char y,unsigned char x,char DATA);
void LCD_WriteString(unsigned char y,unsigned char x,char* DATA);
void LCD_Clear(void);
void USER_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t value);
#endif
