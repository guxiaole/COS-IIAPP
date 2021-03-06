#ifndef  __INCLUDES_H__    
#define  __INCLUDES_H__    

#include  <stdlib.h>
#include "stm32f10x.h" 

#include  "stm32f10x_rcc.h"   //SysTick定时器相关
   
/*#include  "ucos_ii.h"       //uC/OS-II系统函数头文件    */
#include "globals.h" 

#include  "..\uCOS-II\Source\ucos_ii.h"

#include    "BSP.h"         //与开发板相关的函数    
#include    "app.h"         //用户任务函数    
#include    "led.h"         //LED驱动函数    
#include    "usart1.h"
#include    "misc.h"
   
#endif //__INCLUDES_H__ 
