#ifndef __LCD_4LINE_H__
#define __LCD_4LINE_H__

//lcd引脚定义
sbit lcdrs = P0^0;                                                  
sbit lcdrw = P0^1;                                                   
sbit lcden = P0^2;

//液晶端口定义
#define lcd_date P0
#define delay5us()	{_nop_();_nop_();_nop_();_nop_();_nop_();}


//extern void lcd_delay_ms(uint8_t time);
//extern void lcd_busy_wait(void);
extern void lcd_1602_init(void);
extern void lcd_show_string(uint8_t r, uint8_t c, char *str);

#endif	//__LCD_4LINE_H__
