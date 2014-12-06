#include "includes.h"
/*   
 * ��������BSP_Init   
 * ����  ��ʱ�ӳ�ʼ����Ӳ����ʼ��   
 * ����  ����   
 * ���  ����   
 */   
void BSP_Init(void)   
 {    
    SystemInit();     /* ����ϵͳʱ��Ϊ72M */ 
     SysTick_init();    /* ��ʼ����ʹ��SysTick��ʱ�� */ 
    LED_GPIO_Config();  /* LED �˿ڳ�ʼ�� */   
    USART1_Config();
	NVIC_Configuration();
    
}    
   
/*   
 * ��������SysTick_init   
 * ����  ������SysTick��ʱ��   
 * ����  ����   
 * ���  ����   
 */   
void SysTick_init(void)    
{    


    SysTick_Config(72000000/OS_TICKS_PER_SEC);//��ʼ����ʹ��SysTick��ʱ��  
}

	   void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //ͨ������Ϊ����1��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //�ж�ռ�ȵȼ�0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //�ж���Ӧ���ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //���ж�
    NVIC_Init(&NVIC_InitStructure);//
}