#include "includes.h"    
   
OS_STK task_led2_stk[TASK_LED2_STK_SIZE];         //定义栈    
OS_STK task_led3_stk[TASK_LED3_STK_SIZE];         //定义栈    
OS_STK task_Serial_stk[TASK_Serial_STK_SIZE];
OS_STK task_com_stk[TASK_COM_STK_SIZE];
 OS_EVENT* Com1_MBOX;
 //主任务 
void Task_Start(void *p_arg)    
{    
    (void)p_arg;                           // 'p_arg' 并没有用到，防止编译器提示警
   Com1_MBOX=OSMboxCreate((void *) 0);		     //建立串口1中断的消息邮箱
    
 
        
   OSTaskCreate(Task_LED2,(void *)0,           //创建任务2    
		&task_led2_stk[TASK_LED2_STK_SIZE-1], TASK_LED2_PRIO);    
       
   OSTaskCreate(Task_LED3,(void *)0,           //创建任务3    
		&task_led3_stk[TASK_LED3_STK_SIZE-1], TASK_LED3_PRIO);    
   OSTaskCreate(Task_Serial,(void *)0,
		    &task_Serial_stk[TASK_Serial_STK_SIZE-1],TASK_Serial_PRIO);
   OSTaskCreate(Task_Com,(void *)0,
		    &task_com_stk[TASK_COM_STK_SIZE-1],TASK_Com_PRIO);
   
	
   while (1)   
   {   
	     LED1( ON );   
	 OSTimeDlyHMSM(0, 0,milsec1,0);   
	 LED1( OFF);      
	 OSTimeDlyHMSM(0, 0,milsec1,0);        
    }   
 }    
       //任务2 
 void Task_LED2(void *p_arg)    
 {    
     (void)p_arg;                        
             
     while (1)    
     {    
         LED2( ON );    
         OSTimeDlyHMSM(0, 0,milsec2,0);    
         LED2( OFF);    
         OSTimeDlyHMSM(0, 0,milsec2,0);      
     }    
 }    
    
 //任务3 
 void Task_LED3(void *p_arg)    
 {    
     (void)p_arg;          
         
     while (1)    
     {    
         LED3( ON );    
         OSTimeDlyHMSM(0, 0,milsec3,0);    
         LED3( OFF);    
         OSTimeDlyHMSM(0, 0,milsec3,0);            
     }    
 }  

//串口任务
void Task_Com(void *p_arg)
{

     (void)p_arg;          
	  while(1)
	  {
	 OSTimeDlyHMSM(0, 1,0,0);            
      printf("\r\n this is a Com task\r\n"); 
	  } 
	
}

//++++++++++++COM1处理任务++++++++++++++++++++++++++
static  void Task_Serial(void *p_arg)
{    
   INT8U err;	
   unsigned char * msg;
   (void)p_arg;	
   
 
   while(1)
   {
      //OSSemPend(Com1_SEM,0,&err); 		  //等待串口接收指令成功的信号量
	  msg=(unsigned char *)OSMboxPend(Com1_MBOX,10,&err); 		  //等待串口接收指令成功的邮箱信息

   	  if(msg[0]=='L'&&msg[1]==0x31)
	  {
	  	 milsec1=atoi(&msg[3]);               //LED1 的延时毫秒  (mini and V3)
		  printf("\r\n LED1 %ds 间隔闪烁! \r\n",milsec1);
	  }
	  else if(msg[0]=='L'&&msg[1]==0x32)
	  {
	  	 milsec2=atoi(&msg[3]);		   //LED2 的延时毫秒  (only V3)
		 printf("\r\n LED2 %ds 间隔闪烁! \r\n",milsec2);
		 
	  }
	  else if(msg[0]=='L'&&msg[1]==0x33)
	  {
	  	  milsec3=atoi(&msg[3]);		   //LED3 的延时毫秒  (only V3)
		  printf("\r\n LED3 %ds 间隔闪烁! \r\n",milsec3);
	  } 
		  
   } 
   
}

