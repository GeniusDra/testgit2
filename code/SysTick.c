#include "SysTick.h"

static uint32_t TimingDelay;

//��ʼ���δ�ʱ��
void SysTick_Init(void)
{
	/* SystemCoreClock / 1000    1ms�ж�һ��
	   SystemCoreClock / 100000	 10us�ж�һ��
	   SystemCoreClock / 1000000 1us�ж�һ��
	 */
	if (SysTick_Config(SystemCoreClock / 1000000))
  { 
    //��ʼ������  ����������
    while (1);
  }
}


//us��ʱ����,10usΪһ����λ 
void delay_us(uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void delay_ms(uint32_t mTime)
{
	while(mTime--)
		delay_us(1000);

}


//��ȡ���ĳ����� SysTick �жϺ��� SysTick_Handler()����
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}



