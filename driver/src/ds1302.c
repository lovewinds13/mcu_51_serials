#include<STC12C5A60S2.H> 
#include "typedef.h"
#include "intrins.h"
#include <math.h>


uint8_t a,miao,shi,fen,ri,yue,nian,week,temp,keynum,flag,alarmflag;


////液晶端口定义
//#define lcd_date P0 
//#define delay5us(){_nop_();_nop_();_nop_();_nop_();_nop_();}
//#define h1 0x80 //LCD第一行的初始化位置
//#define h2 0x80+0x40 //LCD第二行初始化位置

////定义1602相关管脚
//sbit lcdrs=P0^0;
//sbit lcden=P0^2;
//sbit lcdrw=P0^1;

////温湿度传感器
//#define HTU21DADDR 0x80		//SHT21的IIC地址
//sbit SDA = P3^1;
//sbit SCL = P3^0;

//#define ACK		0   //应答
//#define NACK	1 	//非应答

////按键
//sbit key1=P1^0;//设置按键
//sbit key2=P1^1;//加一键
//sbit key3=P1^4;//减一键
//sbit key4=P1^5;//切换显示时间
//sbit key5=P1^6;//切换显示温湿度

//sbit beep=P1^7;//蜂鸣器
//sbit key8=P3^5;//红外控制


////DS1302芯片的管脚定义
//sbit RST=P3^4;
//sbit IO=P3^3;
//sbit SCLK=P3^2;
//sbit ACC0=ACC^0;//设置累加器
//sbit ACC7=ACC^7;

//void delay(uint z)//延时函数
//{
//	uint x,y;
//	for(x=z;x>0;x--)
//	for(y=110;y>0;y--);
//}

//void delayms(uchar x)
//{
//	uchar t;
//	while(x--)
//    for(t=0;t<120;t++);
//}

////液晶屏忙等待
//void lcd_busy_wait()
//{
//uchar Hi,Lo;
//	do
//	{
//		lcd_date |=0xf0;//4位模式下的数据端口置高电平
//		lcdrs=0;
//		lcdrw=1;//选择指令寄存器 读
//		lcden=1;
//		delay5us();
//		Hi=lcd_date;
//		delay5us();
//		lcden=0;
//		delay5us();
//		lcden=1;
//		delay5us();
//		Lo=lcd_date;
//		delay5us();
//		lcden=0;
//		delay5us();
//	}
//	while(Hi&0x80);
//}

////写指令
//void lcd_1602_write_com(uchar com)   
//{
//	lcd_busy_wait();
//	lcd_date=com&0xf0|0x04;//写入高四位,或时已经将rs,rw,en的电平置位
//	delay5us();
//	lcden=0;
//	delay5us();
//	lcd_date=com<<4|0x04;//写入低四位
//	delay5us();
//	lcden=0;
//	delay5us();
//}	
// 
////写数据
// void lcd_1602_write_dat(uchar dat)
//{
//	lcd_busy_wait();
//	lcd_date=dat&0xf0|0x05;//写入高四位
//	delay5us();
//	lcden=0;
//	delay5us();
//	lcd_date=dat<<4|0x05;//写入低四位
//	delay5us();
//	lcden=0;
//	delay5us();
//}

//void Lcd_1602_init()
//{
//	lcd_date=0xff;//初始化液晶端口全部置高电平
//	lcd_date=0x24;//4位模式，置lcden,lcdrw,lcdrs=100(4),准备写指令寄存器
//	lcden=0;//完成控制命令的写入

//	lcd_1602_write_com(0x28); //4位，2行，5x7点阵 	 
//  	delayms(15);                          
//  	lcd_1602_write_com(0x0c); //开显示
//	delayms(15); 
// 	lcd_1602_write_com(0x06);  //写入新数据，光标右移
//	delayms(15); 	 
//  	lcd_1602_write_com(0x01);//清屏
//	delayms(15); 
//	lcd_1602_write_com(0x02);//光标定位于右上角
//	delayms(15);
//}	

////显示字符
//void lcd_string(uchar r,uchar c,char j,char *str)
//{
//	uchar i=0;
//	code uchar ddram[]={0x80,0xc0};//液晶屏上下两行起始位置
//	 lcd_1602_write_com(ddram[r]|c);//设置显示起始位置
//	//输出字符串
//	for(i=0;i<j;i++)
//		{
//			lcd_1602_write_dat(str[i]);
//		}
//}



////************************************************************//
///*DS1302DS1302有关子函数*/
////************************************************************//
//void write_byte(uchar dat)//写一个字节
//{
//ACC=dat;
//RST=1;
//for(a=8;a>0;a--)
//{
//  IO=ACC0; 
//  SCLK=1;
//	SCLK=0;
//  ACC=ACC>>1;
//}
//return;
//}


//uchar read_byte()//读一个字节函数
//{
//RST=1;
//for(a=8;a>0;a--)
//{
//	ACC=ACC>>1;
//  ACC7=IO;
//  SCLK=1; 
//  SCLK=0;
//}
//return (ACC);
//}

//void write_1302(uchar add,uchar dat)//向时钟芯片写入函数，指定地址，数据
//{
//	RST=0;
//	SCLK=0;
//	RST=1;
//	write_byte(add);
//	write_byte(dat);
//	SCLK=1;
//	RST=0;
//}


//uchar read_1302(uchar add)//从芯片读出数据，指定地址
//{
//	uchar temp;
//	RST=0;
//	SCLK=0;
//	RST=1;
//	write_byte(add|0x01);
//	temp=read_byte();
//	SCLK=1;
//	RST=0;
//	IO=0;
//	return(temp);
//}

//uchar BCD_Decimal(uchar bcd) //BCD码转十进制函数，输入BCD，返回十进制
//{
//uchar Decimal;
//Decimal=bcd>>4;
//return(Decimal=Decimal*10+(bcd&=0x0F));
//}


//void ds1302_init() 
//{
//  RST=0;
//	SCLK=0;
//	write_1302(0x8e,0x00); //允许写，禁止写保护  
//	write_1302(0x80,0x00);//向DS1302内写秒寄存器80H写入初始秒数据00 
//	write_1302(0x82,0x00);//向DS1302内写分寄存器82H写入初始分数据00
//	write_1302(0x84,0x00);//向DS1302内写小时寄存器84H写入初始小时数据00
//	write_1302(0x8a,0x02); //向DS1302内写周寄存器8aH写入初始周数据2
//	write_1302(0x86,0x01);//向DS1302内写日期寄存器86H写入初始日期数据11
//	write_1302(0x88,0x12); //向DS1302内写月份寄存器88H写入初始月份数据06
//	write_1302(0x8c,0x15);//向DS1302内写年份寄存器8cH写入初始年份数据13
//	write_1302(0x8e,0x80);  //打开写保护
//	

//}

////时分秒显示子函数
//void write_sfm(uchar add,uchar dat)//向LCD写时分秒,有显示位置、显示数据，两个参数
//{
//	uchar gw,sw;
//	gw=dat%10;//取得个位数字
//	sw=dat/10;//取得十位数字
//	lcd_1602_write_com(h2+add);//h2是头文件规定的值0x80+0x40
//	lcd_1602_write_dat(0x30+sw); //数字+30得到十位的LCD1602显示码   
//	lcd_1602_write_dat(0x30+gw); //数字+30得到个位的LCD1602显示码
//}

////年月日显示子函数
//void write_nyr(uchar add,uchar dat)//向LCD写年月日，有显示位置、显示数据，两个参数
//{
//	uchar gw,sw;
//	gw=dat%10;//取得个位数字
//	sw=dat/10;//取得十位数字
//	lcd_1602_write_com(h1+add);//设定显示位置为第一行第一个位置+add
//	lcd_1602_write_dat(0x30+sw);//数字+30得到该数字的LCD1602显示码 
//	lcd_1602_write_dat(0x30+gw); //数字+30得到该数字的LCD1602显示码
//}

////写星期函数
//void write_week(uchar week)
//{
//	lcd_1602_write_com(h1+0x0d);/*注意：第一行是从0位开始的*/
//	switch(week)
//	{
//		case 1:lcd_1602_write_dat('1');
//		break;
//		case 2:lcd_1602_write_dat('2');
//		break;
//		case 3:lcd_1602_write_dat('3');
//		break;
//		case 4:lcd_1602_write_dat('4');
//		break;
//		case 5:lcd_1602_write_dat('5');
//		break;
//		case 6:lcd_1602_write_dat('6');
//		break;
//		case 7:lcd_1602_write_dat('7');
//		break;
//	}
//}	


////*************************************************************//
///*温湿度传感器*/
////*************************************************************//
///*================================================================
//【名 称】void I2CDelay (unsigned char t)
//【功 能】模拟IIC用的短延时
//================================================================*/
//void I2CDelay (unsigned char t)
//{
//	while(t--);
//}
///*================================================================
//【名 称】void I2CInit(void)
//【功 能】I2C初始化，空闲状态
//================================================================*/
//void I2CInit(void)
//{
//	SDA = 1; 
//	I2CDelay(10);
//	SCL = 1;
//	I2CDelay(10);
//}
///*================================================================
//【名 称】void I2CStart(void)
//【功 能】I2C启动信号
//【备 注】SCL、SDA同为高，SDA跳变成低之后，SCL跳变成低
//================================================================*/
//void I2CStart(void)
//{
//  	SDA = 1;
//  	SCL = 1;
//  	I2CDelay(10);
//  	SDA = 0;
//  	I2CDelay(10);
//  	SCL = 0;
//  	I2CDelay(10);
//}
///*================================================================
//【名 称】void I2CStop(void)
//【功 能】I2C停止信号
//【备 注】SCL、SDA同为低，SCL跳变成高之后，SDA跳变成高
//================================================================*/
//void I2CStop(void)
//{
//		SDA = 0;
//  	SCL = 0;
//		I2CDelay(10);
//  	SCL = 1;
//  	I2CDelay(10);
//  	SDA = 1;
//  	I2CDelay(10);
//}
///*================================================================
//【名 称】unsigned char I2CWRByte(unsigned char WriteData)
//【功 能】I2C写一个字节数据，返回ACK或者NACK
//【备 注】从高到低，依次发送
//================================================================*/
//uchar I2CWriteByte(uchar WriteData)
//{
//	uchar i;
//	SCL = 0;
//	for(i = 0;i < 8;i++)
//	{
//		if(WriteData & 0x80)
//			{
//			SDA = 1;	
//			}
//		else
//			SDA = 0;
//		I2CDelay(100);
//		SCL = 1;	    //输出SDA稳定后，拉高SCL给出上升沿，从机检测到后进行数据采样
//		I2CDelay(500);
//		SCL = 0;
//		I2CDelay(100);
//		WriteData <<= 1;
//	} 
//	I2CDelay(20);
//	SDA = 1;
//	SCL = 1;
//	I2CDelay(30);
//	if(SDA == 1)			//SDA为高，收到NACK
//	{
//		return NACK;	
//	}
//	else 				    //SDA为低，收到ACK
//	{
//		SCL = 0;
//		I2CDelay(50);
//		return ACK;
//	}
//}
///*================================================================
//【名 称】unsigned char I2CRDByte(unsigned char AckValue)
//【功 能】I2C读一个字节数据，入口参数用于控制应答状态，ACK或者NACK
//【备 注】从高到低，依次接收
//================================================================*/
//uchar I2CReadByte(uchar AckValue)
//{
//	uchar i,ReadData = 0;
//	SCL = 0;
//	SDA = 1;			//释放总线	
//	for(i = 0;i < 8;i++) 
//	{
//		SCL = 1;		//给出上升沿
//		I2CDelay(30);	//延时等待信号稳定
//		ReadData <<= 1;	
//		if(SDA == 1) 		//采样获取数据
//		{
//			ReadData |= 0x01;
//		}
//		else
//		{
//			ReadData &= 0xfe;
//		}
//		I2CDelay(10);
//		SCL = 0;   		//下降沿，从机给出下一位值
//		I2CDelay(20);
//	}   
//	SDA = AckValue;	//应答状态
//	I2CDelay(10);
//	SCL = 1;                         
//  	I2CDelay(50);          
//  	SCL = 0;
//	  I2CDelay(50);
//	return ReadData;
//}

///*================================================================
//【名 称】void Delay(unsigned int t)
//【功 能】延时长
//================================================================*/
//void HTUDelay(uint t)
//{
//	uchar i;
//	while(t--)
//	{
//		for(i = 0;i < 200;i++);
//	}					   
//}

///*================================================================
//【名 称】void SHT21Init(void)
//【功 能】SHT21初始化函数
//================================================================*/
//void HTU21DInit(void)
//{
//	I2CInit();		//I2C初始化
//	I2CStart();		//启动I2C
//	I2CWriteByte(HTU21DADDR&0xfe);		//写SHT21的I2C地址
//	I2CWriteByte(0xfe);
//	I2CStop();		//停止I2C
//	HTUDelay(600);		//短延时
//}


///*================================================================
//【名 称】long Sht21Work(unsigned char order)
//【功 能】Sht21测量温湿度
//================================================================*/
//int HTU21DWork(uchar order)
//{
//	float temp = 0,TH = 0;
//	uchar MSB,LSB;
//	uint shidu,wendu;
//	
//	I2CStart();
//	if(I2CWriteByte(HTU21DADDR & 0xfe) == ACK)
//	{
//		if(I2CWriteByte(order) == ACK)
//		{
//			do
//			{
//				HTUDelay(30);
//				I2CStart();	
//			}
//			while(I2CWriteByte(HTU21DADDR | 0x01) == NACK);
//			MSB = I2CReadByte(ACK);
//			HTUDelay(30);
//			LSB = I2CReadByte(ACK);
//			I2CReadByte(NACK);
//			I2CStop();
//			LSB &= 0xfc;
//			temp = MSB*256+LSB;
//				if (order == 0xf3)//触发开启温度检测
//			{
//				TH=(175.72)*temp/65536-46.85;//温度:T= -46.85 + 175.72 * ST/2^16
//				wendu =(uint)(fabs(TH)*100);
//				if(TH >= 0)
//					flag = 0;
//				else
//					flag = 1;
//				return wendu;	
//			}
//			else
//			{
//				TH = (temp*125)/65536-6;
//				shidu = (uint)(fabs(TH)*100);//湿度: RH%= -6 + 125 * SRH/2^16
//				return shidu;
//			}
//		}
//	}
//	return 0;
//}

///*********  定义显示函数 ******/
//void LCD_Display(	uint TEMP, 	uint HUMI)
//{
//					uchar wendu1[7],shidu[8];
//					wendu1[0]=TEMP/10000+'0';     //百位		
//      		wendu1[1]=(TEMP%10000)/1000+'0';  //十位   		
//					wendu1[2]=(TEMP%1000)/100+'0';		//个位
//      		wendu1[3]=0x2E;						//小数点
//					wendu1[4]=(TEMP%100)/10+'0';//小数后一位
//					wendu1[5]='%';
//					wendu1[6]='C';	
//					lcd_string(0,5,7,wendu1);//显示温度
//	
//					shidu[0]=HUMI/10000+'0';     		
//      		shidu[1]=(HUMI%10000)/1000+'0';     	
//					shidu[2]=(HUMI%1000)/100+'0';			
//      		shidu[3]=0x2E;						
//					shidu[4]=(HUMI%100)/10+'0';	
//					shidu[5]='%';
//					shidu[6]='R';
//					shidu[7]='H';		
//					lcd_string(1,5,8,shidu);
//				
//}


//void init() //定时器、计数器设置函数
//{
//	TMOD=0x01; //指定定时/计数器T0,T1的工作方式为1
//	TH0=(65536-50000)/256; //对T0定时器装值
//  TL0=(65536-50000)%256;
//	ET0=1;//允许T0中断
//	TR0=1;//开启中断，启动定时器
//	EA=1;  //允许总中断
//}



////**************************************************************//
///*按键*/
////**************************************************************//
//void keyscan()
//{
//	/**屏显切换**/		
//		if(key4==0)//设置键按下
//	{
//		delay(5);//延时
//		if(key4==0)
//		{
//			while(!key4);
//			init(); //调用定时计数器的设置子函数
//			ds1302_init(); //调用DS1302时钟的初始化子函数
//				
//			delay(10);
//		}
//	}
//	if(key5==0)//设置键按下
//	{
//		  uint tem=0,htu=0;
//		delay(5);//延时
//		if(key5==0)
//		{
//			while(!key5);
//				TR0=0;
//				lcd_1602_write_com(0x01);//清屏
//				delayms(15);
//			lcd_string(0,0,5,"TEMP:");
//			lcd_string(1,0,5,"HUMI:");
//			
//	while(key4!=0)
//	 {
//		tem=HTU21DWork(0xf3);//触发开启温度检测
//		htu=HTU21DWork(0xf5);//触发开启湿度检测
//		LCD_Display(tem,htu);//显示温湿度
//		delayms(5000);//刷新慢一些
//		}
//		}
//	}
//	
//	if(key1==0)//设置键按下
//	{
//		delay(5);//延时
//		if(key1==0)
//		{
//			beep=0;//蜂鸣器短响一声
//			delay(200);
//			beep=1;
//			alarmflag=0;/*按下标志，用于防止调节时间时鸣叫*/
//			while(!key1);
//			keynum++;
//			if(keynum==9)
//			keynum=1;
//			switch(keynum)
//			{
//			case 1:TR0=0;//关闭定时器
//				   lcd_1602_write_com(h2+0x07);//秒的位置
//					 lcd_1602_write_com(0x0f);//设置为光标闪烁
//				   temp=(miao)/10*16+(miao)%10;//秒化为bcd码
//				   write_1302(0x8e,0x00);
//				   write_1302(0x80,0x80|temp);//秒数据写入
//				   write_1302(0x8e,0x80);
//				   break;
//			case 2:lcd_1602_write_com(h2+4);//分的位置
//				   break;
//			case 3:lcd_1602_write_com(h2+1);//时的位置
//				   break;
//			case 4:lcd_1602_write_com(h1+0x0d);//星期的位置
//				   break;
//			case 5:lcd_1602_write_com(h1+0x09);//日的位置
//				   break;
//			case 6:lcd_1602_write_com(h1+0x06);//月的位置
//				  break;
//			case 7:lcd_1602_write_com(h1+0x3);//年的位置
//				  break;
//			case 8:lcd_1602_write_com(0x0c);//第8次，光标不闪烁
//				  
//				  TR0=1;//重新打开定时器
//				  temp=(miao)/10*16+(miao)%10;
//				  write_1302(0x8e,0x00);
//				  write_1302(0x80,0x00|temp);//写入秒
//				  write_1302(0x8e,0x80);
//				  break;
//			}
//		}
//	}
//	if(keynum!=0)//当设置键按下时才能操作
//	{
//		if(key2==0)//加键
//		{
//			delay(5);
//			if(key2==0)
//			{
//				beep=0;//蜂鸣器短响一声
//				delay(200);
//				beep=1;
//				while(!key2);//按键松开
//				switch(keynum)
//				{
//					case 1:miao++;//
//						   if(miao==60)	miao=0;
//						   write_sfm(0x06,miao);/*在十位的位置写入，因为为两位数，个位数自动再后面显示*/
//						   temp=(miao)/10*16+(miao)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x80,temp);// 写入秒
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h2+0x07);//液晶模式为写入后自动右移，在此返回原来位置
//						   break;
//					case 2:fen++;
//						   if(fen==60) fen=0;
//						   write_sfm(0x03,fen);//在十位数位置开始写入
//						   temp=(fen)/10*16+(fen)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x82,temp);//写入分
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h2+4);//返回个位数的位置
//						   break;
//					case 3:shi++;
//						   if(shi==24) shi=0;
//						  write_sfm(0,shi);//在0位开始写入
//						   temp=(shi)/10*16+(shi)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x84,temp);//写入时
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h2+1);//返回到个位位置
//						   break;
//					case 4:week++;
//						   if(week==8) week=1;
//						 lcd_1602_write_com(h1+0x0d);//显示位置
//						   write_week(week);//写入星期
//						   temp=(week)/10*16+(week)%10;
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x8a,temp);//写入周
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h1+0x0e);
//						   break;
//					case 5:ri++;
//						   if(ri==32) ri=1;
//						   write_nyr(8,ri);//注意是在十位开始写入
//						   temp=(ri)/10*16+(ri)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x86,temp);//写入日
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h1+9);//返回个位数
//						   break;
//					case 6:yue++;
//						   if(yue==13) yue=1;
//						   write_nyr(5,yue);//在十位开始写入
//						   temp=(yue)/10*16+(yue)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x88,temp);//写入月
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h1+6);//返回个位位置 
//						   break;
//					case 7:nian++;
//						   if(nian==100) nian=0;
//						   write_nyr(2,nian);//在第一行第三个字符开始写入
//						   temp=(nian)/10*16+(nian)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x8c,temp);//写入年
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h1+3);//返回个位位置
//						   break;
//				}		   

//			}
//		}
//		//以下是减的函数
//		if(key3==0)
//		{
//			delay(5);//消抖
//			if(key3==0)
//			{
//				beep=0;//蜂鸣器短响一声
//				delay(200);
//				beep=1;
//				while(!key3);
//				switch(keynum)
//				{
//					case 1:miao--;
//						   if(miao==-1) miao=59;//减到-1返回59
//						  write_sfm(0x06,miao);//在十位数写入 
//						   temp=(miao)/10*16+(miao)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写
//						   write_1302(0x80,temp);//写入秒
//						   write_1302(0x8e,0x80);//打开保护
//						 lcd_1602_write_com(h2+0x07);//返回个位位置
//						   break;
//					case 2:fen--;
//						   if(fen==-1) fen=59;
//						   write_sfm(0x03,fen);//在十位数位置写入
//						   temp=(fen)/10*16+(fen)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x82,temp);//写入分
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h2+4);//返回个位数位置
//						   break;
//				    case 3:shi--;
//						   if(shi==-1) shi=23;
//						  write_sfm(0,shi);//在0位开始写入
//						   temp=(shi)/10*16+(shi)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x84,temp);//写入时
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h2+1);//返回到个位位置
//						   break;
//					case 4:week--;
//						   if(week==0) week=7;
//						   lcd_1602_write_com(h1+0x0d);//显示位置
//						   write_week(week);//写入星期
//						   temp=(week)/10*16+(week)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x8a,temp);//写入周
//						   write_1302(0x8e,0x80);//打开保护
//						  lcd_1602_write_com(h1+0x0e);//返回原来位置
//						   break;
//					case 5:ri--;
//						   if(ri==0) ri=31;
//						   write_nyr(8,ri);//在十位开始显示
//						   temp=(ri)/10*16+(ri)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x86,temp);//写入日
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h1+9);//返回个位数
//						   break;
//					case 6:yue--;
//						   if(yue==0) yue=12;
//						   write_nyr(5,yue);//在十位数位置开始写入
//						   temp=(yue)/10*16+(yue)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x88,temp);//写入月
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h1+6);//返回到个位位置
//						   break;
//					case 7:nian--;
//						   if(nian==-1) nian=99;
//						   write_nyr(2,nian);//第一行第三个字符开始写入
//						   temp=(nian)/10*16+(nian)%10;//转换为bcd码
//						   write_1302(0x8e,0x00);//允许写入
//						   write_1302(0x8c,temp);//写入年
//						   write_1302(0x8e,0x80);//打开保护
//						   lcd_1602_write_com(h1+3);//返回在年的尾数位置
//						   break;
//							
//				}
//			}
//		}
//		
//	}

//}

///*********************************************************************************************
//函数名：PWM初始化函数
//调  用：PWM_init();
//参  数：无
//返回值：无
//结  果：将PCA初始化为PWM模式，初始占空比为0
//备  注：需要更多路PWM输出直接插入CCAPnH和CCAPnL即可
///**********************************************************************************************/
//void PWM_init (void)
//{
//	CMOD=0x02; //设置PCA定时器
//  	CL=0x00; 
//  	CH=0x00;
// 	CCAPM0=0x42; //PWM0设置PCA工作方式为PWM方式（0100 0010）
//  	CCAP0L=0x00; //设置PWM0初始值与CCAP0H相同
//  	CCAP0H=0x00; // PWM0初始时为0

// //CCAPM1=0x42; //PWM1设置PCA工作方式为PWM方式（使用时删除//）
// //CCAP1L=0x00; //设置PWM1初始值与CCAP0H相同
//  //CCAP1H=0x00; // PWM1初始时为0

// //CCAPM2=0x42; //PWM2设置PCA工作方式为PWM方式
// //CCAP2L=0x00; //设置PWM2初始值与CCAP0H相同
//  //CCAP2H=0x00; // PWM2初始时为0

// //CCAPM3=0x42; //PWM3设置PCA工作方式为PWM方式
// //CCAP3L=0x00; //设置PWM3初始值与CCAP0H相同
//  //CCAP3H=0x00; // PWM3初始时为0

//  	CR=1; //启动PCA定时器
//}
///**********************************************************************************************/

///*********************************************************************************************
//函数名：PWM0占空比设置函数
//调  用：PWM0_set();
//参  数：0x00~0xFF（亦可用0~255）
//返回值：无
//结  果：设置PWM模式占空比，为0时全部高电平，为1时全部低电平
//备  注：如果需要PWM1的设置函数，只要把CCAP0L和CCAP0H中的0改为1即可
///**********************************************************************************************/
//void PWM0_set (unsigned char a){
// 	CCAP0L= a; //设置值直接写入CCAP0L
//  	CCAP0H= a; //设置值直接写入CCAP0H
//}


//void beep_time()
//{
//	uchar i;
//		if(shi==2 && fen==0 && miao==5)
//		{
//				beep=0;	
//		}
//if(shi==2 && fen==0 && miao==10)
//		{
//			beep=1;
//		}
//	
//}
////*******************主函数**************************			
//void main()
//{
// 		int i=0;   
//		Lcd_1602_init(); //调用液晶屏初始化子函数
//		HTU21DInit();
//		lcd_string(0,0,5,"hello");
//		lcd_string(1,0,6,"123456");
//		while(1)
//		{
//		
//		keyscan(); //调用键盘扫描子函数
//	
//			if(key8!=0)
//			{
//		PWM_init(); //PWM初始化
//		for(i=0;i<0xFF;i++)
//	 	{
// 		PWM0_set(i); //设置PWM占空比,总共255,除以2,转换成十六进制得7F
//		}
//		i=0;
//			}
//					beep_time();
//		}
//}
//void timer0() interrupt 1 using 0//取得并显示日历和时间
//{
//	TH0=(65536-50000)/256; //对T0定时器重装初值
//  	TL0=(65536-50000)%256;
//	//读取秒时分周日月年七个数据
//	miao = BCD_Decimal(read_1302(0x81));
//	fen = BCD_Decimal(read_1302(0x83));
//	shi  = BCD_Decimal(read_1302(0x85));
//	ri  = BCD_Decimal(read_1302(0x87));
//	yue = BCD_Decimal(read_1302(0x89));
//	nian=BCD_Decimal(read_1302(0x8d));
//	week=BCD_Decimal(read_1302(0x8b));
//	lcd_string(0,0,15,"20  /  /   W< >");
//	write_nyr(8,ri);//日期，从第二行第8个字符后开始显示
//	write_nyr(5,yue);//月份，从第二行第5个字符后开始显示
//	write_nyr(2,nian);//年，从第二行第2个字符后开始显示
//	write_week(week);
//	lcd_string(1,0,16,"  :  :          ");
//	write_sfm(6,miao);//秒，从第二行第6个字后开始显示（调用时分秒显示子函数）
//	write_sfm(3,fen);//分，从第二行第3个字符后开始显示
//	write_sfm(0,shi);//小时，从第二行第1个字符后开始显示
//	
//}

