#include<STC12C5A60S2.H> 
#include "typedef.h"
#include "intrins.h"
#include <math.h>


uint8_t a,miao,shi,fen,ri,yue,nian,week,temp,keynum,flag,alarmflag;


////Һ���˿ڶ���
//#define lcd_date P0 
//#define delay5us(){_nop_();_nop_();_nop_();_nop_();_nop_();}
//#define h1 0x80 //LCD��һ�еĳ�ʼ��λ��
//#define h2 0x80+0x40 //LCD�ڶ��г�ʼ��λ��

////����1602��عܽ�
//sbit lcdrs=P0^0;
//sbit lcden=P0^2;
//sbit lcdrw=P0^1;

////��ʪ�ȴ�����
//#define HTU21DADDR 0x80		//SHT21��IIC��ַ
//sbit SDA = P3^1;
//sbit SCL = P3^0;

//#define ACK		0   //Ӧ��
//#define NACK	1 	//��Ӧ��

////����
//sbit key1=P1^0;//���ð���
//sbit key2=P1^1;//��һ��
//sbit key3=P1^4;//��һ��
//sbit key4=P1^5;//�л���ʾʱ��
//sbit key5=P1^6;//�л���ʾ��ʪ��

//sbit beep=P1^7;//������
//sbit key8=P3^5;//�������


////DS1302оƬ�ĹܽŶ���
//sbit RST=P3^4;
//sbit IO=P3^3;
//sbit SCLK=P3^2;
//sbit ACC0=ACC^0;//�����ۼ���
//sbit ACC7=ACC^7;

//void delay(uint z)//��ʱ����
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

////Һ����æ�ȴ�
//void lcd_busy_wait()
//{
//uchar Hi,Lo;
//	do
//	{
//		lcd_date |=0xf0;//4λģʽ�µ����ݶ˿��øߵ�ƽ
//		lcdrs=0;
//		lcdrw=1;//ѡ��ָ��Ĵ��� ��
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

////дָ��
//void lcd_1602_write_com(uchar com)   
//{
//	lcd_busy_wait();
//	lcd_date=com&0xf0|0x04;//д�����λ,��ʱ�Ѿ���rs,rw,en�ĵ�ƽ��λ
//	delay5us();
//	lcden=0;
//	delay5us();
//	lcd_date=com<<4|0x04;//д�����λ
//	delay5us();
//	lcden=0;
//	delay5us();
//}	
// 
////д����
// void lcd_1602_write_dat(uchar dat)
//{
//	lcd_busy_wait();
//	lcd_date=dat&0xf0|0x05;//д�����λ
//	delay5us();
//	lcden=0;
//	delay5us();
//	lcd_date=dat<<4|0x05;//д�����λ
//	delay5us();
//	lcden=0;
//	delay5us();
//}

//void Lcd_1602_init()
//{
//	lcd_date=0xff;//��ʼ��Һ���˿�ȫ���øߵ�ƽ
//	lcd_date=0x24;//4λģʽ����lcden,lcdrw,lcdrs=100(4),׼��дָ��Ĵ���
//	lcden=0;//��ɿ��������д��

//	lcd_1602_write_com(0x28); //4λ��2�У�5x7���� 	 
//  	delayms(15);                          
//  	lcd_1602_write_com(0x0c); //����ʾ
//	delayms(15); 
// 	lcd_1602_write_com(0x06);  //д�������ݣ��������
//	delayms(15); 	 
//  	lcd_1602_write_com(0x01);//����
//	delayms(15); 
//	lcd_1602_write_com(0x02);//��궨λ�����Ͻ�
//	delayms(15);
//}	

////��ʾ�ַ�
//void lcd_string(uchar r,uchar c,char j,char *str)
//{
//	uchar i=0;
//	code uchar ddram[]={0x80,0xc0};//Һ��������������ʼλ��
//	 lcd_1602_write_com(ddram[r]|c);//������ʾ��ʼλ��
//	//����ַ���
//	for(i=0;i<j;i++)
//		{
//			lcd_1602_write_dat(str[i]);
//		}
//}



////************************************************************//
///*DS1302DS1302�й��Ӻ���*/
////************************************************************//
//void write_byte(uchar dat)//дһ���ֽ�
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


//uchar read_byte()//��һ���ֽں���
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

//void write_1302(uchar add,uchar dat)//��ʱ��оƬд�뺯����ָ����ַ������
//{
//	RST=0;
//	SCLK=0;
//	RST=1;
//	write_byte(add);
//	write_byte(dat);
//	SCLK=1;
//	RST=0;
//}


//uchar read_1302(uchar add)//��оƬ�������ݣ�ָ����ַ
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

//uchar BCD_Decimal(uchar bcd) //BCD��תʮ���ƺ���������BCD������ʮ����
//{
//uchar Decimal;
//Decimal=bcd>>4;
//return(Decimal=Decimal*10+(bcd&=0x0F));
//}


//void ds1302_init() 
//{
//  RST=0;
//	SCLK=0;
//	write_1302(0x8e,0x00); //����д����ֹд����  
//	write_1302(0x80,0x00);//��DS1302��д��Ĵ���80Hд���ʼ������00 
//	write_1302(0x82,0x00);//��DS1302��д�ּĴ���82Hд���ʼ������00
//	write_1302(0x84,0x00);//��DS1302��дСʱ�Ĵ���84Hд���ʼСʱ����00
//	write_1302(0x8a,0x02); //��DS1302��д�ܼĴ���8aHд���ʼ������2
//	write_1302(0x86,0x01);//��DS1302��д���ڼĴ���86Hд���ʼ��������11
//	write_1302(0x88,0x12); //��DS1302��д�·ݼĴ���88Hд���ʼ�·�����06
//	write_1302(0x8c,0x15);//��DS1302��д��ݼĴ���8cHд���ʼ�������13
//	write_1302(0x8e,0x80);  //��д����
//	

//}

////ʱ������ʾ�Ӻ���
//void write_sfm(uchar add,uchar dat)//��LCDдʱ����,����ʾλ�á���ʾ���ݣ���������
//{
//	uchar gw,sw;
//	gw=dat%10;//ȡ�ø�λ����
//	sw=dat/10;//ȡ��ʮλ����
//	lcd_1602_write_com(h2+add);//h2��ͷ�ļ��涨��ֵ0x80+0x40
//	lcd_1602_write_dat(0x30+sw); //����+30�õ�ʮλ��LCD1602��ʾ��   
//	lcd_1602_write_dat(0x30+gw); //����+30�õ���λ��LCD1602��ʾ��
//}

////��������ʾ�Ӻ���
//void write_nyr(uchar add,uchar dat)//��LCDд�����գ�����ʾλ�á���ʾ���ݣ���������
//{
//	uchar gw,sw;
//	gw=dat%10;//ȡ�ø�λ����
//	sw=dat/10;//ȡ��ʮλ����
//	lcd_1602_write_com(h1+add);//�趨��ʾλ��Ϊ��һ�е�һ��λ��+add
//	lcd_1602_write_dat(0x30+sw);//����+30�õ������ֵ�LCD1602��ʾ�� 
//	lcd_1602_write_dat(0x30+gw); //����+30�õ������ֵ�LCD1602��ʾ��
//}

////д���ں���
//void write_week(uchar week)
//{
//	lcd_1602_write_com(h1+0x0d);/*ע�⣺��һ���Ǵ�0λ��ʼ��*/
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
///*��ʪ�ȴ�����*/
////*************************************************************//
///*================================================================
//���� �ơ�void I2CDelay (unsigned char t)
//���� �ܡ�ģ��IIC�õĶ���ʱ
//================================================================*/
//void I2CDelay (unsigned char t)
//{
//	while(t--);
//}
///*================================================================
//���� �ơ�void I2CInit(void)
//���� �ܡ�I2C��ʼ��������״̬
//================================================================*/
//void I2CInit(void)
//{
//	SDA = 1; 
//	I2CDelay(10);
//	SCL = 1;
//	I2CDelay(10);
//}
///*================================================================
//���� �ơ�void I2CStart(void)
//���� �ܡ�I2C�����ź�
//���� ע��SCL��SDAͬΪ�ߣ�SDA����ɵ�֮��SCL����ɵ�
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
//���� �ơ�void I2CStop(void)
//���� �ܡ�I2Cֹͣ�ź�
//���� ע��SCL��SDAͬΪ�ͣ�SCL����ɸ�֮��SDA����ɸ�
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
//���� �ơ�unsigned char I2CWRByte(unsigned char WriteData)
//���� �ܡ�I2Cдһ���ֽ����ݣ�����ACK����NACK
//���� ע���Ӹߵ��ͣ����η���
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
//		SCL = 1;	    //���SDA�ȶ�������SCL���������أ��ӻ���⵽��������ݲ���
//		I2CDelay(500);
//		SCL = 0;
//		I2CDelay(100);
//		WriteData <<= 1;
//	} 
//	I2CDelay(20);
//	SDA = 1;
//	SCL = 1;
//	I2CDelay(30);
//	if(SDA == 1)			//SDAΪ�ߣ��յ�NACK
//	{
//		return NACK;	
//	}
//	else 				    //SDAΪ�ͣ��յ�ACK
//	{
//		SCL = 0;
//		I2CDelay(50);
//		return ACK;
//	}
//}
///*================================================================
//���� �ơ�unsigned char I2CRDByte(unsigned char AckValue)
//���� �ܡ�I2C��һ���ֽ����ݣ���ڲ������ڿ���Ӧ��״̬��ACK����NACK
//���� ע���Ӹߵ��ͣ����ν���
//================================================================*/
//uchar I2CReadByte(uchar AckValue)
//{
//	uchar i,ReadData = 0;
//	SCL = 0;
//	SDA = 1;			//�ͷ�����	
//	for(i = 0;i < 8;i++) 
//	{
//		SCL = 1;		//����������
//		I2CDelay(30);	//��ʱ�ȴ��ź��ȶ�
//		ReadData <<= 1;	
//		if(SDA == 1) 		//������ȡ����
//		{
//			ReadData |= 0x01;
//		}
//		else
//		{
//			ReadData &= 0xfe;
//		}
//		I2CDelay(10);
//		SCL = 0;   		//�½��أ��ӻ�������һλֵ
//		I2CDelay(20);
//	}   
//	SDA = AckValue;	//Ӧ��״̬
//	I2CDelay(10);
//	SCL = 1;                         
//  	I2CDelay(50);          
//  	SCL = 0;
//	  I2CDelay(50);
//	return ReadData;
//}

///*================================================================
//���� �ơ�void Delay(unsigned int t)
//���� �ܡ���ʱ��
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
//���� �ơ�void SHT21Init(void)
//���� �ܡ�SHT21��ʼ������
//================================================================*/
//void HTU21DInit(void)
//{
//	I2CInit();		//I2C��ʼ��
//	I2CStart();		//����I2C
//	I2CWriteByte(HTU21DADDR&0xfe);		//дSHT21��I2C��ַ
//	I2CWriteByte(0xfe);
//	I2CStop();		//ֹͣI2C
//	HTUDelay(600);		//����ʱ
//}


///*================================================================
//���� �ơ�long Sht21Work(unsigned char order)
//���� �ܡ�Sht21������ʪ��
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
//				if (order == 0xf3)//���������¶ȼ��
//			{
//				TH=(175.72)*temp/65536-46.85;//�¶�:T= -46.85 + 175.72 * ST/2^16
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
//				shidu = (uint)(fabs(TH)*100);//ʪ��: RH%= -6 + 125 * SRH/2^16
//				return shidu;
//			}
//		}
//	}
//	return 0;
//}

///*********  ������ʾ���� ******/
//void LCD_Display(	uint TEMP, 	uint HUMI)
//{
//					uchar wendu1[7],shidu[8];
//					wendu1[0]=TEMP/10000+'0';     //��λ		
//      		wendu1[1]=(TEMP%10000)/1000+'0';  //ʮλ   		
//					wendu1[2]=(TEMP%1000)/100+'0';		//��λ
//      		wendu1[3]=0x2E;						//С����
//					wendu1[4]=(TEMP%100)/10+'0';//С����һλ
//					wendu1[5]='%';
//					wendu1[6]='C';	
//					lcd_string(0,5,7,wendu1);//��ʾ�¶�
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


//void init() //��ʱ�������������ú���
//{
//	TMOD=0x01; //ָ����ʱ/������T0,T1�Ĺ�����ʽΪ1
//	TH0=(65536-50000)/256; //��T0��ʱ��װֵ
//  TL0=(65536-50000)%256;
//	ET0=1;//����T0�ж�
//	TR0=1;//�����жϣ�������ʱ��
//	EA=1;  //�������ж�
//}



////**************************************************************//
///*����*/
////**************************************************************//
//void keyscan()
//{
//	/**�����л�**/		
//		if(key4==0)//���ü�����
//	{
//		delay(5);//��ʱ
//		if(key4==0)
//		{
//			while(!key4);
//			init(); //���ö�ʱ�������������Ӻ���
//			ds1302_init(); //����DS1302ʱ�ӵĳ�ʼ���Ӻ���
//				
//			delay(10);
//		}
//	}
//	if(key5==0)//���ü�����
//	{
//		  uint tem=0,htu=0;
//		delay(5);//��ʱ
//		if(key5==0)
//		{
//			while(!key5);
//				TR0=0;
//				lcd_1602_write_com(0x01);//����
//				delayms(15);
//			lcd_string(0,0,5,"TEMP:");
//			lcd_string(1,0,5,"HUMI:");
//			
//	while(key4!=0)
//	 {
//		tem=HTU21DWork(0xf3);//���������¶ȼ��
//		htu=HTU21DWork(0xf5);//��������ʪ�ȼ��
//		LCD_Display(tem,htu);//��ʾ��ʪ��
//		delayms(5000);//ˢ����һЩ
//		}
//		}
//	}
//	
//	if(key1==0)//���ü�����
//	{
//		delay(5);//��ʱ
//		if(key1==0)
//		{
//			beep=0;//����������һ��
//			delay(200);
//			beep=1;
//			alarmflag=0;/*���±�־�����ڷ�ֹ����ʱ��ʱ����*/
//			while(!key1);
//			keynum++;
//			if(keynum==9)
//			keynum=1;
//			switch(keynum)
//			{
//			case 1:TR0=0;//�رն�ʱ��
//				   lcd_1602_write_com(h2+0x07);//���λ��
//					 lcd_1602_write_com(0x0f);//����Ϊ�����˸
//				   temp=(miao)/10*16+(miao)%10;//�뻯Ϊbcd��
//				   write_1302(0x8e,0x00);
//				   write_1302(0x80,0x80|temp);//������д��
//				   write_1302(0x8e,0x80);
//				   break;
//			case 2:lcd_1602_write_com(h2+4);//�ֵ�λ��
//				   break;
//			case 3:lcd_1602_write_com(h2+1);//ʱ��λ��
//				   break;
//			case 4:lcd_1602_write_com(h1+0x0d);//���ڵ�λ��
//				   break;
//			case 5:lcd_1602_write_com(h1+0x09);//�յ�λ��
//				   break;
//			case 6:lcd_1602_write_com(h1+0x06);//�µ�λ��
//				  break;
//			case 7:lcd_1602_write_com(h1+0x3);//���λ��
//				  break;
//			case 8:lcd_1602_write_com(0x0c);//��8�Σ���겻��˸
//				  
//				  TR0=1;//���´򿪶�ʱ��
//				  temp=(miao)/10*16+(miao)%10;
//				  write_1302(0x8e,0x00);
//				  write_1302(0x80,0x00|temp);//д����
//				  write_1302(0x8e,0x80);
//				  break;
//			}
//		}
//	}
//	if(keynum!=0)//�����ü�����ʱ���ܲ���
//	{
//		if(key2==0)//�Ӽ�
//		{
//			delay(5);
//			if(key2==0)
//			{
//				beep=0;//����������һ��
//				delay(200);
//				beep=1;
//				while(!key2);//�����ɿ�
//				switch(keynum)
//				{
//					case 1:miao++;//
//						   if(miao==60)	miao=0;
//						   write_sfm(0x06,miao);/*��ʮλ��λ��д�룬��ΪΪ��λ������λ���Զ��ٺ�����ʾ*/
//						   temp=(miao)/10*16+(miao)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x80,temp);// д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h2+0x07);//Һ��ģʽΪд����Զ����ƣ��ڴ˷���ԭ��λ��
//						   break;
//					case 2:fen++;
//						   if(fen==60) fen=0;
//						   write_sfm(0x03,fen);//��ʮλ��λ�ÿ�ʼд��
//						   temp=(fen)/10*16+(fen)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x82,temp);//д���
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h2+4);//���ظ�λ����λ��
//						   break;
//					case 3:shi++;
//						   if(shi==24) shi=0;
//						  write_sfm(0,shi);//��0λ��ʼд��
//						   temp=(shi)/10*16+(shi)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x84,temp);//д��ʱ
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h2+1);//���ص���λλ��
//						   break;
//					case 4:week++;
//						   if(week==8) week=1;
//						 lcd_1602_write_com(h1+0x0d);//��ʾλ��
//						   write_week(week);//д������
//						   temp=(week)/10*16+(week)%10;
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x8a,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h1+0x0e);
//						   break;
//					case 5:ri++;
//						   if(ri==32) ri=1;
//						   write_nyr(8,ri);//ע������ʮλ��ʼд��
//						   temp=(ri)/10*16+(ri)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x86,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h1+9);//���ظ�λ��
//						   break;
//					case 6:yue++;
//						   if(yue==13) yue=1;
//						   write_nyr(5,yue);//��ʮλ��ʼд��
//						   temp=(yue)/10*16+(yue)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x88,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h1+6);//���ظ�λλ�� 
//						   break;
//					case 7:nian++;
//						   if(nian==100) nian=0;
//						   write_nyr(2,nian);//�ڵ�һ�е������ַ���ʼд��
//						   temp=(nian)/10*16+(nian)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x8c,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h1+3);//���ظ�λλ��
//						   break;
//				}		   

//			}
//		}
//		//�����Ǽ��ĺ���
//		if(key3==0)
//		{
//			delay(5);//����
//			if(key3==0)
//			{
//				beep=0;//����������һ��
//				delay(200);
//				beep=1;
//				while(!key3);
//				switch(keynum)
//				{
//					case 1:miao--;
//						   if(miao==-1) miao=59;//����-1����59
//						  write_sfm(0x06,miao);//��ʮλ��д�� 
//						   temp=(miao)/10*16+(miao)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д
//						   write_1302(0x80,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						 lcd_1602_write_com(h2+0x07);//���ظ�λλ��
//						   break;
//					case 2:fen--;
//						   if(fen==-1) fen=59;
//						   write_sfm(0x03,fen);//��ʮλ��λ��д��
//						   temp=(fen)/10*16+(fen)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x82,temp);//д���
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h2+4);//���ظ�λ��λ��
//						   break;
//				    case 3:shi--;
//						   if(shi==-1) shi=23;
//						  write_sfm(0,shi);//��0λ��ʼд��
//						   temp=(shi)/10*16+(shi)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x84,temp);//д��ʱ
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h2+1);//���ص���λλ��
//						   break;
//					case 4:week--;
//						   if(week==0) week=7;
//						   lcd_1602_write_com(h1+0x0d);//��ʾλ��
//						   write_week(week);//д������
//						   temp=(week)/10*16+(week)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x8a,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						  lcd_1602_write_com(h1+0x0e);//����ԭ��λ��
//						   break;
//					case 5:ri--;
//						   if(ri==0) ri=31;
//						   write_nyr(8,ri);//��ʮλ��ʼ��ʾ
//						   temp=(ri)/10*16+(ri)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x86,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h1+9);//���ظ�λ��
//						   break;
//					case 6:yue--;
//						   if(yue==0) yue=12;
//						   write_nyr(5,yue);//��ʮλ��λ�ÿ�ʼд��
//						   temp=(yue)/10*16+(yue)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x88,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h1+6);//���ص���λλ��
//						   break;
//					case 7:nian--;
//						   if(nian==-1) nian=99;
//						   write_nyr(2,nian);//��һ�е������ַ���ʼд��
//						   temp=(nian)/10*16+(nian)%10;//ת��Ϊbcd��
//						   write_1302(0x8e,0x00);//����д��
//						   write_1302(0x8c,temp);//д����
//						   write_1302(0x8e,0x80);//�򿪱���
//						   lcd_1602_write_com(h1+3);//���������β��λ��
//						   break;
//							
//				}
//			}
//		}
//		
//	}

//}

///*********************************************************************************************
//��������PWM��ʼ������
//��  �ã�PWM_init();
//��  ������
//����ֵ����
//��  ������PCA��ʼ��ΪPWMģʽ����ʼռ�ձ�Ϊ0
//��  ע����Ҫ����·PWM���ֱ�Ӳ���CCAPnH��CCAPnL����
///**********************************************************************************************/
//void PWM_init (void)
//{
//	CMOD=0x02; //����PCA��ʱ��
//  	CL=0x00; 
//  	CH=0x00;
// 	CCAPM0=0x42; //PWM0����PCA������ʽΪPWM��ʽ��0100 0010��
//  	CCAP0L=0x00; //����PWM0��ʼֵ��CCAP0H��ͬ
//  	CCAP0H=0x00; // PWM0��ʼʱΪ0

// //CCAPM1=0x42; //PWM1����PCA������ʽΪPWM��ʽ��ʹ��ʱɾ��//��
// //CCAP1L=0x00; //����PWM1��ʼֵ��CCAP0H��ͬ
//  //CCAP1H=0x00; // PWM1��ʼʱΪ0

// //CCAPM2=0x42; //PWM2����PCA������ʽΪPWM��ʽ
// //CCAP2L=0x00; //����PWM2��ʼֵ��CCAP0H��ͬ
//  //CCAP2H=0x00; // PWM2��ʼʱΪ0

// //CCAPM3=0x42; //PWM3����PCA������ʽΪPWM��ʽ
// //CCAP3L=0x00; //����PWM3��ʼֵ��CCAP0H��ͬ
//  //CCAP3H=0x00; // PWM3��ʼʱΪ0

//  	CR=1; //����PCA��ʱ��
//}
///**********************************************************************************************/

///*********************************************************************************************
//��������PWM0ռ�ձ����ú���
//��  �ã�PWM0_set();
//��  ����0x00~0xFF�������0~255��
//����ֵ����
//��  ��������PWMģʽռ�ձȣ�Ϊ0ʱȫ���ߵ�ƽ��Ϊ1ʱȫ���͵�ƽ
//��  ע�������ҪPWM1�����ú�����ֻҪ��CCAP0L��CCAP0H�е�0��Ϊ1����
///**********************************************************************************************/
//void PWM0_set (unsigned char a){
// 	CCAP0L= a; //����ֱֵ��д��CCAP0L
//  	CCAP0H= a; //����ֱֵ��д��CCAP0H
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
////*******************������**************************			
//void main()
//{
// 		int i=0;   
//		Lcd_1602_init(); //����Һ������ʼ���Ӻ���
//		HTU21DInit();
//		lcd_string(0,0,5,"hello");
//		lcd_string(1,0,6,"123456");
//		while(1)
//		{
//		
//		keyscan(); //���ü���ɨ���Ӻ���
//	
//			if(key8!=0)
//			{
//		PWM_init(); //PWM��ʼ��
//		for(i=0;i<0xFF;i++)
//	 	{
// 		PWM0_set(i); //����PWMռ�ձ�,�ܹ�255,����2,ת����ʮ�����Ƶ�7F
//		}
//		i=0;
//			}
//					beep_time();
//		}
//}
//void timer0() interrupt 1 using 0//ȡ�ò���ʾ������ʱ��
//{
//	TH0=(65536-50000)/256; //��T0��ʱ����װ��ֵ
//  	TL0=(65536-50000)%256;
//	//��ȡ��ʱ�����������߸�����
//	miao = BCD_Decimal(read_1302(0x81));
//	fen = BCD_Decimal(read_1302(0x83));
//	shi  = BCD_Decimal(read_1302(0x85));
//	ri  = BCD_Decimal(read_1302(0x87));
//	yue = BCD_Decimal(read_1302(0x89));
//	nian=BCD_Decimal(read_1302(0x8d));
//	week=BCD_Decimal(read_1302(0x8b));
//	lcd_string(0,0,15,"20  /  /   W< >");
//	write_nyr(8,ri);//���ڣ��ӵڶ��е�8���ַ���ʼ��ʾ
//	write_nyr(5,yue);//�·ݣ��ӵڶ��е�5���ַ���ʼ��ʾ
//	write_nyr(2,nian);//�꣬�ӵڶ��е�2���ַ���ʼ��ʾ
//	write_week(week);
//	lcd_string(1,0,16,"  :  :          ");
//	write_sfm(6,miao);//�룬�ӵڶ��е�6���ֺ�ʼ��ʾ������ʱ������ʾ�Ӻ�����
//	write_sfm(3,fen);//�֣��ӵڶ��е�3���ַ���ʼ��ʾ
//	write_sfm(0,shi);//Сʱ���ӵڶ��е�1���ַ���ʼ��ʾ
//	
//}

