
#include<reg52.h>                    

void InitUART  (void)
{
    EA=1;

    SCON  = 0x50;		        // SCON: ģʽ 1, 8-bit UART, ʹ�ܽ���  
	TMOD &=0x0F;
    TMOD |= 0x20;               // TMOD: timer 1, mode 2, 8-bit ��װ
    TH1   = 0xF3;               // TH1:  ��װֵ 9600 ������ ���� 11.0592MHz  
	TL1=TH1;
    TR1   = 1;  
    PCON=0x80;                
}                       

void main (void)
{

InitUART();

ES=1;
//SEND();

while (1);                       

}


void UART_SER (void) interrupt 4 //�����жϷ������
{
    unsigned char Temp;          //������ʱ���� 
   
                       //�ж��ǽ����жϲ���
	  //RI=0;                      //��־λ����
	  Temp=SBUF;                    //��ֵ�����P1�ڣ����ڹ۲�
	  RI=0;
	  P1=Temp;
	  SBUF=Temp;		  
      while(TI==0);                        //����Ƿ��ͱ�־λ������
      TI=0;
} 


