//#include "includes.h"    
//   
//static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];        //定义栈    
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

 /******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************  
  * 文件名  ：main.c   
  * 描述    ：建立3个任务，前3任务控制一个LED，以固定的频率轮流闪烁（频率可
  * 	      最后一个任务是串口打印输出
。            
  * 实验平台：野火STM32开发板   
  * 库版本  ：ST3.0.0   
  *   
  * 作者    ：fire  QQ: 313303034    
  * 博客    ：firestm32.blog.chinaunix.net   
 ********************************************************************************/ 
 #define GLOBALS

 #include "includes.h"    
 //#include  "ucos_ii.h"  
    
 OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];       //定义栈    
 
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
    
