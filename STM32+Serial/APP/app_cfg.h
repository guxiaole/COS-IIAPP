// #ifndef  __APP_CFG_H__    
// #define  __APP_CFG_H__    
//    
// /*******************�����������ȼ�*******************/   
// #define STARTUP_TASK_PRIO       4          
//    
// /************����ջ��С����λΪ OS_STK ��************/   
// #define STARTUP_TASK_STK_SIZE   80         
// #endif

#ifndef  __APP_CFG_H__    
#define  __APP_CFG_H__    
   
   
/*******************�����������ȼ�*******************/   
#define STARTUP_TASK_PRIO       4          
#define TASK_LED2_PRIO          7    
#define TASK_LED3_PRIO          6     
#define TASK_Serial_PRIO        5
#define TASK_Com_PRIO           8
   /************����ջ��С����λΪ OS_STK ��************/   
 #define STARTUP_TASK_STK_SIZE   80       
 #define TASK_LED2_STK_SIZE      80    
 #define TASK_LED3_STK_SIZE      80    
#define  TASK_Serial_STK_SIZE    80
#define TASK_COM_STK_SIZE        80
 #endif 
