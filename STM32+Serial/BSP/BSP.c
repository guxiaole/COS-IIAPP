#include "includes.h"
/*   
 * 函数名：BSP_Init   
 * 描述  ：时钟初始化、硬件初始化   
 * 输入  ：无   
 * 输出  ：无   
 */   
void BSP_Init(void)   
 {    
    SystemInit();     /* 配置系统时钟为72M */ 
     SysTick_init();    /* 初始化并使能SysTick定时器 */ 
    LED_GPIO_Config();  /* LED 端口初始化 */   
    USART1_Config();
	NVIC_Configuration();
    
}    
   
/*   
 * 函数名：SysTick_init   
 * 描述  ：配置SysTick定时器   
 * 输入  ：无   
 * 输出  ：无   
 */   
void SysTick_init(void)    
{    


    SysTick_Config(72000000/OS_TICKS_PER_SEC);//初始化并使能SysTick定时器  
}

	   void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //通道设置为串口1中
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //中断占先等级0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //中断响应优先级0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //打开中断
    NVIC_Init(&NVIC_InitStructure);//
}