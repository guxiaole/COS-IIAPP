/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "includes.h"
//#include "led.h"
//#include "globals.h"
//#include "ucos_ii.h"

/*extern OS_EVENT* Com1_SEM;*/
extern OS_EVENT* Com1_MBOX;

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
SysTick_Handler;
OSTimeTick();
OSIntExit();
}
/*******************************************************************************
* Function Name  : USART1_IRQHandler
* Description    : This function handles USART1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_IRQHandler(void)
{
   //printf("\r\n enter serial send3 \r\n");   
	
	unsigned int i;
        unsigned char msg[50];
	OS_CPU_SR  cpu_sr;
  	
        /*LED4(ON);   */
	OS_ENTER_CRITICAL();  //保存全局中断标志,关总中断// Tell uC/OS-II that we are starting an ISR
  	OSIntNesting++;
	
  	OS_EXIT_CRITICAL();	  //恢复全局中断标志
	
  	//OSTimeTick();     // Call uC/OS-II's OSTimeTick(),在os_core.c文件里定义,主要判断延时的任务是否计时到
 
   	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)	   //判断读寄存器是否非空
  	{	
    		// Read one byte from the receive data register 
    	
		msg[RxCounter1++]= USART_ReceiveData(USART1);   //将读寄存器的数据缓存到接收缓冲区里
    		if(msg[RxCounter1-1]=='L')
		{
			msg[0]='L'; 
			RxCounter1=1;
		}     //判断起始标志
		if(msg[RxCounter1-1]=='F')                  //判断结束标志是否是"F"
		
    		{
	  			for(i=0; i< RxCounter1; i++)
				{
					TxBuffer1[i]=msg[i]; 	     //将接收缓冲器的数据转到发送缓冲区，准备转发
	  		
				}
				  		
				TxBuffer1[RxCounter1]=0;                                //接收缓冲区终止符
	  			RxCounter1=0; 						
				//OSSemPost(Com1_SEM); 	  
				OSMboxPost(Com1_MBOX,(void *)&msg); 	                   
    		}
  	} 
  	if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)                     // 
  	{ 
     	USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
  	}	
    OSIntExit();  //在os_core.c文件里定义,如果有更高优先级的任务就绪了,则执行一次任务切换    
    /*LED4(OFF);*/
    
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
