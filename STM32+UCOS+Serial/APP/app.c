#include "includes.h"    
   
OS_STK task_led2_stk[TASK_LED2_STK_SIZE];         //����ջ    
OS_STK task_led3_stk[TASK_LED3_STK_SIZE];         //����ջ    
OS_STK task_Serial_stk[TASK_Serial_STK_SIZE];
OS_STK task_com_stk[TASK_COM_STK_SIZE];
 OS_EVENT* Com1_MBOX;
 //������ 
void Task_Start(void *p_arg)    
{    
    (void)p_arg;                           // 'p_arg' ��û���õ�����ֹ��������ʾ��
   Com1_MBOX=OSMboxCreate((void *) 0);		     //��������1�жϵ���Ϣ����
    
 
        
   OSTaskCreate(Task_LED2,(void *)0,           //��������2    
		&task_led2_stk[TASK_LED2_STK_SIZE-1], TASK_LED2_PRIO);    
       
   OSTaskCreate(Task_LED3,(void *)0,           //��������3    
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
       //����2 
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
    
 //����3 
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

//��������
void Task_Com(void *p_arg)
{

     (void)p_arg;          
	  while(1)
	  {
	 OSTimeDlyHMSM(0, 1,0,0);            
      printf("\r\n this is a Com task\r\n"); 
	  } 
	
}

//++++++++++++COM1��������++++++++++++++++++++++++++
static  void Task_Serial(void *p_arg)
{    
   INT8U err;	
   unsigned char * msg;
   (void)p_arg;	
   
 
   while(1)
   {
      //OSSemPend(Com1_SEM,0,&err); 		  //�ȴ����ڽ���ָ��ɹ����ź���
	  msg=(unsigned char *)OSMboxPend(Com1_MBOX,10,&err); 		  //�ȴ����ڽ���ָ��ɹ���������Ϣ

   	  if(msg[0]=='L'&&msg[1]==0x31)
	  {
	  	 milsec1=atoi(&msg[3]);               //LED1 ����ʱ����  (mini and V3)
		  printf("\r\n LED1 %ds �����˸! \r\n",milsec1);
	  }
	  else if(msg[0]=='L'&&msg[1]==0x32)
	  {
	  	 milsec2=atoi(&msg[3]);		   //LED2 ����ʱ����  (only V3)
		 printf("\r\n LED2 %ds �����˸! \r\n",milsec2);
		 
	  }
	  else if(msg[0]=='L'&&msg[1]==0x33)
	  {
	  	  milsec3=atoi(&msg[3]);		   //LED3 ����ʱ����  (only V3)
		  printf("\r\n LED3 %ds �����˸! \r\n",milsec3);
	  } 
		  
   } 
   
}

