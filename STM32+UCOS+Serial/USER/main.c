//#include "includes.h"    
//   
//static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];        //����ջ    
//      
//int main(void)    
//{    
//    BSP_Init();    
//    OSInit();    
//    OSTaskCreate(Task_LED,(void *)0,    
//       &startup_task_stk[STARTUP_TASK_STK_SIZE-1], STARTUP_TASK_PRIO);    
//   
//    OSStart();    
//    return 0;    
// }

 /******************** (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� ********************  
  * �ļ���  ��main.c   
  * ����    ������3������ǰ3�������һ��LED���Թ̶���Ƶ��������˸��Ƶ�ʿ�
  * 	      ���һ�������Ǵ��ڴ�ӡ���
��            
  * ʵ��ƽ̨��Ұ��STM32������   
  * ��汾  ��ST3.0.0   
  *   
  * ����    ��fire  QQ: 313303034    
  * ����    ��firestm32.blog.chinaunix.net   
 ********************************************************************************/ 
 #define GLOBALS

 #include "includes.h"    
 //#include  "ucos_ii.h"  
    
 OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];       //����ջ    
 
//OS_EVENT* Com1_MBOX;  
       
 int main(void)    
 {    
     BSP_Init();    
     OSInit();    
     milsec1=1,milsec2=2,milsec3=3;
     OSTaskCreate(Task_Start,(void *)0,    
        &startup_task_stk[STARTUP_TASK_STK_SIZE-1], STARTUP_TASK_PRIO);    
    
     OSStart();    
     return 0;    
  }    
    