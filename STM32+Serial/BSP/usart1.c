#include "usart1.h"


/*  
 * 函数名：USART1_Config  
 * 描述  ：USART1 GPIO 配置,工作模式配置。115200 8-N-1  
 * 输入  ：无  
 * 输出  : 无  
 * 调用  ：外部调用  
 */  
void USART1_Config(void)   
{   
    GPIO_InitTypeDef GPIO_InitStructure;   
    USART_InitTypeDef USART_InitStructure;   
       
    /* config USART1 clock */  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); 
    /* USART1 GPIO config */  
    /* Configure USART1 Tx (PA.09) as alternate function push
pull */  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
    GPIO_Init(GPIOA, &GPIO_InitStructure);       
    /* Configure USART1 Rx (PA.10) as input floating */  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
    GPIO_Init(GPIOA, &GPIO_InitStructure);   
         
    /* USART1 mode config */  
    USART_InitStructure.USART_BaudRate = 115200;   
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;   
    USART_InitStructure.USART_StopBits = USART_StopBits_1;   
    USART_InitStructure.USART_Parity = USART_Parity_No ;   
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;   
    USART_Init(USART1, &USART_InitStructure);    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);                    //使能接收中断
    USART_ITConfig(USART1, USART_IT_TXE, ENABLE);                    //使能接收中断

    USART_Cmd(USART1, ENABLE);   

    
}  


