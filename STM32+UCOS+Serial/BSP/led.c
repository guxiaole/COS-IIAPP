/******************** (C) COPYRIGHT 2012 WildFire Team *********  
* 文件名  ：led.c  
* 描述    ：led 应用函数库           
 
****************************************************************/
 #include "led.h"    
  /*  
   * 函数名：LED_GPIO_Config  
   * 描述  ：配置 LED 用到的 I/O 口  
   * 输入  ：无  
   * 输出  ：无  
   */  
  
  void LED_GPIO_Config(void)   
  {          
      /*定义一个 GPIO_InitTypeDef 类型的结构体*/  
      GPIO_InitTypeDef GPIO_InitStructure;   
    
      /*开启 GPIOE 的外设时钟*/  
      RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE);    
    
     /*选择要控制的 GPIOE 引脚*/                                                                 
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 |GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;   
	     
      /*设置引脚模式为通用推挽输出*/  
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      
    
     /*设置引脚速率为 50MHz */      
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
    
      /*调用库函数，初始化 GPIOE*/  
      GPIO_Init(GPIOE, &GPIO_InitStructure);           
   
    /* 关闭所有 led 灯 */  
      GPIO_SetBits(GPIOE, GPIO_Pin_2 |GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);      
  }  
//  void LED1(int a)
//  {
//	   if(a)
//	  GPIO_SetBits(GPIOE,GPIO_Pin_2);
//	     else  
//	  GPIO_ResetBits(GPIOE,GPIO_Pin_2); 
//  } 
//    void LED2(int a)
//  {
//	   if(a)
//	  GPIO_SetBits(GPIOE,GPIO_Pin_3);
//	     else  
//	  GPIO_ResetBits(GPIOE,GPIO_Pin_3); 
//  }  
//   void LED3(int a)
//  {
//	   if(a)
//	  GPIO_SetBits(GPIOE,GPIO_Pin_4);
//	     else  
//	  GPIO_ResetBits(GPIOE,GPIO_Pin_4); 
//  } 
//   void LED4(int a)
//  {
//	   if(a)
//	  GPIO_SetBits(GPIOE,GPIO_Pin_5);
//	     else  
//	  GPIO_ResetBits(GPIOE,GPIO_Pin_5); 
//  } 
  /********* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE********/
