#include "LCD1602.h"
#if 0
void LCD_WritePin(uint8_t data)
{

    LCD_D0_PORT->BRR = LCD_D0_PIN;
    LCD_D1_PORT->BRR = LCD_D1_PIN;
    LCD_D2_PORT->BRR = LCD_D2_PIN;
    LCD_D3_PORT->BRR = LCD_D3_PIN;
    LCD_D4_PORT->BRR = LCD_D4_PIN;
    LCD_D5_PORT->BRR = LCD_D5_PIN;
    LCD_D6_PORT->BRR = LCD_D6_PIN;
    LCD_D7_PORT->BRR = LCD_D7_PIN;

    if (data & 0x01) LCD_D0_PORT->BSRR = LCD_D0_PIN;
    if (data & 0x02) LCD_D1_PORT->BSRR = LCD_D1_PIN;
    if (data & 0x04) LCD_D2_PORT->BSRR = LCD_D2_PIN;
    if (data & 0x08) LCD_D3_PORT->BSRR = LCD_D3_PIN;
    if (data & 0x10) LCD_D4_PORT->BSRR = LCD_D4_PIN;
    if (data & 0x20) LCD_D5_PORT->BSRR = LCD_D5_PIN;
    if (data & 0x40) LCD_D6_PORT->BSRR = LCD_D6_PIN;
    if (data & 0x80) LCD_D7_PORT->BSRR = LCD_D7_PIN;
}
#endif
void LCD_WritePin(uint8_t data)
{
    // 使用宏定义的引脚，支持任意端口组合
    USER_GPIO_WritePin(LCD_D0_PORT, LCD_D0_PIN, (data >> 0) & 0x01);
    USER_GPIO_WritePin(LCD_D1_PORT, LCD_D1_PIN, (data >> 1) & 0x01);
    USER_GPIO_WritePin(LCD_D2_PORT, LCD_D2_PIN, (data >> 2) & 0x01);
    USER_GPIO_WritePin(LCD_D3_PORT, LCD_D3_PIN, (data >> 3) & 0x01);
    USER_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (data >> 4) & 0x01);
    USER_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (data >> 5) & 0x01);
    USER_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (data >> 6) & 0x01);
    USER_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (data >> 7) & 0x01);
}

void LCD_WriteCmd(uint16_t DATA)
{
    LCD1602_RS_C;
    LCD1602_EN_L;
    LCD1602_RW_W;
    LCD_WritePin(DATA);

    LCD1602_EN_H;
    HAL_Delay(1);
    LCD1602_EN_L;
}

void LCD_WriteData(uint16_t DATA)
{
    LCD1602_RS_D;
    LCD1602_EN_L;
    LCD1602_RW_W;
    LCD_WritePin(DATA);

    LCD1602_EN_H;
    HAL_Delay(1);
    LCD1602_EN_L;
}

void LCD_WriteChar(unsigned char y,unsigned char x,char DATA){
    if (y==0)
    {
        LCD_WriteCmd(0X80+x);
    }
    else if (y==1)
    {
        LCD_WriteCmd(0XC0+x);
    }
    LCD_WriteData(DATA);

}

void LCD_WriteString(unsigned char y,unsigned char x,char* DATA){
    unsigned char i = 0;
    while (DATA[i] != '\0')
    {
        LCD_WriteChar(y,x+i,DATA[i]);
        i++;

    }
    
}

void LCD_Clear(void){
    LCD_WriteCmd(0X01);
}
void LCD_Init(void)
{
    LCD_WriteCmd(0X38);
    LCD_WriteCmd(0X0C);
    LCD_WriteCmd(0X06);
    LCD_WriteCmd(0X01);
    LCD_WriteCmd(0X80);
}

void USER_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t value)
{
   if (value)
      GPIOx->ODR |= GPIO_Pin;
    else
        GPIOx->ODR &= ~GPIO_Pin;
}
