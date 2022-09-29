#ifndef _LCD_INT_H
#define _LCD_INT_H

void LCD_sendcommand(char cmd);
void LCD_send_number(int num);
void LCD_INIT(void);
void LCD_sendChar(u8 character);
void LCD_sendstring(u8* str, u32 delay);
void LCD_send_number(int num);
void LCD_display_shap(char charid);
void LCD_save_shap(u8 charid, const u8 arr[]);
void LCD_set_cursor(u8 linepos, u8 line);















#endif
