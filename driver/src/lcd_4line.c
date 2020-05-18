#ifndef __PRJ_STC51_LCD_4LINE_C__
#define __PRJ_STC51_LCD_4LINE_C__

#include <reg52.h>
#include "typedef.h"
#include "lcd_4line.h"
#include <intrins.h>

uint8_t table1[]={"date:  00/00/00  "};

//---------------------------------------------------------------------------------------------------------------------------------------------
//	函 数 名: lcd_delay_ms
//	功能说明: LCD延时使用函数
//	形    参: 无
//	返 回 值: 无
//	日    期: 
//  备    注: 
//	作    者: 千艺千寻
//---------------------------------------------------------------------------------------------------------------------------------------------
static void lcd_delay_ms(uint8_t time)
{
	uint8_t t;
	
	while(time--) 
	{
		for (t = 0; t < 120; t++);
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------
//	函 数 名: lcd_delay_ms
//	功能说明: LCD延时使用函数
//	形    参: 无
//	返 回 值: 无
//	日    期: 
//  备    注: 
//	作    者: 千艺千寻
//---------------------------------------------------------------------------------------------------------------------------------------------
static void lcd_busy_wait(void)
{
	uint8_t Hi,Lo;
	do
	{
		lcd_date |=0xf0;//4位模式下的数据端口置高电平
		
		lcdrs = 0;
		lcdrw = 1;	//选择指令寄存器 读
		lcden = 1;
		delay5us();
		
		Hi = lcd_date;
		delay5us();
		lcden = 0;
		delay5us();
		lcden = 1;
		delay5us();
		Lo = lcd_date;
		delay5us();
		lcden = 0;
		delay5us();
	}
	while(Hi&0x80);
}

//写指令
static void lcd_1602_write_com(uint8_t com)   
{
	lcd_busy_wait();	//液晶忙等待
	
	lcd_date = com&0xf0|0x04;	//写入高四位,或时已经将rs,rw,en的电平置位
	delay5us();
	lcden = 0;
	delay5us();
	lcd_date = com<<4|0x04;	//写入低四位
	delay5us();
	lcden = 0;
	delay5us();
}	

//写数据
static void lcd_1602_write_dat(uint8_t dat)
{
	lcd_busy_wait();//液晶忙等待
	
	lcd_date = dat&0xf0|0x05;//写入高四位
	delay5us();
	lcden = 0;
	delay5us();
	lcd_date=dat<<4|0x05;//写入低四位
	delay5us();
	lcden = 0;
	delay5us();
}	

//初始化液晶
void lcd_1602_init(void)
{
	lcd_date = 0xFF;//初始化液晶端口全部置高电平
	lcd_date = 0x24;//4位模式，置lcden,lcdrw,lcdrs=100(4),准备写指令寄存器
	lcden = 0;//完成控制命令的写入
	
	lcd_1602_write_com(0x28); //4位，2行，5x7点阵 	 
	lcd_delay_ms(15);    
	
	lcd_1602_write_com(0x0C); //开显示
	lcd_delay_ms(15); 
	
	lcd_1602_write_com(0x06);  //写入新数据，光标右移
	lcd_delay_ms(15); 
	
	lcd_1602_write_com(0x01);//清屏
	lcd_delay_ms(15); 
	
	lcd_1602_write_com(0x02);//光标定位于右上角
	lcd_delay_ms(15);
}	

//显示字符
void lcd_show_string(uint8_t r, uint8_t c, char *str)
{
	uint8_t i = 0;
	
	code uint8_t ddram[]={0x80, 0xC0};//液晶屏上下两行起始位置
	
	 lcd_1602_write_com(ddram[r]|c);//设置显示起始位置
	//输出字符串
	for (i = 0; (i < 16) && (str[i]!= '\0'); i++)
	{
		lcd_1602_write_dat(str[i]);
	}
}

#endif	//__PRJ_STC51_LCD_4LINE_C__
