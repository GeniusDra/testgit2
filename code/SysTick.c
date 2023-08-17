#include "SysTick.h"

static uint32_t TimingDelay;

//初始化滴答定时器
void SysTick_Init(void)
{
	/* SystemCoreClock / 1000    1ms中断一次
	   SystemCoreClock / 100000	 10us中断一次
	   SystemCoreClock / 1000000 1us中断一次
	 */
	if (SysTick_Config(SystemCoreClock / 1000000))
  { 
    //初始化错误  卡死在这里
    while (1);
  }
}


//us延时程序,10us为一个单位 
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


//获取节拍程序，在 SysTick 中断函数 SysTick_Handler()调用
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}



