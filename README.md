# LCD1602A-Character-LCD-Driver-Based-on-STM32-HAL-Library

This is a driver program for the LCD1602A character display, written for STM32 microcontrollers using the STM32 HAL library.

The `Driver_Function` folder contains the LCD1602A driver and the associated `main.c` file.

This driver is very straightforward — you only need to call three functions to print a string anywhere on the screen. The three functions are: 
- `LCD_Init` — initializes the display;
```cpp
  void LCD_Init(void)
{
    LCD_WriteCmd(0X38);
    LCD_WriteCmd(0X0C);
    LCD_WriteCmd(0X06);
    LCD_WriteCmd(0X01);
    LCD_WriteCmd(0X80);
}
```
- `LCD_Clear` — clears all pixels on the screen;
```cpp
void LCD_Clear(void){
    LCD_WriteCmd(0X01);
}
```
- `LCD_WriteString` — prints a string at the specified position.
```cpp
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
```

Below is the schematic diagram for the test setup. Wire the components as shown, flash the test program onto the chip, and the screen will display strings accordingly.

Note: If you want to use different GPIO pins to control the display, simply change the pin macros in LCD.h and initialize the corresponding pins in STM32CubeMX.

![alt text](Schematic_diagram.png)
