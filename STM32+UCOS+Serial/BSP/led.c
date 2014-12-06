/******************** (C) COPYRIGHT 2012 WildFire Team *********  
* �ļ���  ��led.c  
* ����    ��led Ӧ�ú�����           
 
****************************************************************/
 #include "led.h"    
  /*  
   * ��������LED_GPIO_Config  
   * ����  ������ LED �õ��� I/O ��  
   * ����  ����  
   * ���  ����  
   */  
  
  void LED_GPIO_Config(void)   
  {          
      /*����һ�� GPIO_InitTypeDef ���͵Ľṹ��*/  
      GPIO_InitTypeDef GPIO_InitStructure;   
    
      /*���� GPIOE ������ʱ��*/  
      RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE);    
    
     /*ѡ��Ҫ���Ƶ� GPIOE ����*/                                                                 
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 |GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;   
	     
      /*��������ģʽΪͨ���������*/  
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      
    
     /*������������Ϊ 50MHz */      
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
    
      /*���ÿ⺯������ʼ�� GPIOE*/  
      GPIO_Init(GPIOE, &GPIO_InitStructure);           
   
    /* �ر����� led �� */  
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
