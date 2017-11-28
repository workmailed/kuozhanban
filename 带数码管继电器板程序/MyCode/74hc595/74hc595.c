#include "74HC595.h"
#include "delay.h"

#define DATA  PAout(8)
#define S_CLK  PBout(14)
#define R_CLK  PBout(15)
//�̵�����Ӧ��ϵ(��12λ��Ӧ12���̵���)��
//��λ��ǰ����ʮ��λ��Ӧ�̵���9-12
void HC595SendData(u16 SendVal)
{
	u8 i;
	for(i=0;i<16;i++)
	{
		if((SendVal<<i)&0x8000)	DATA=1;
		else DATA=0;
		S_CLK=0;
		delay_us(5);
		S_CLK=1;
	}
	R_CLK=0;
	delay_us(5);
	R_CLK=1;
}
