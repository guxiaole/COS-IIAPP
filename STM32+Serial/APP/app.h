//#ifndef _APP_H_    
//#define _APP_H_    
//   
///**************** 用户任务声明 *******************/   
//void Task_LED(void *p_arg);    
//   
//#endif  //_APP_H_

 #ifndef _APP_H_    
#define _APP_H_    
   
/**************** 用户任务声明 *******************/   
void Task_Start(void *p_arg);    
void Task_LED2(void *p_arg);    
void Task_LED3(void *p_arg);    
void Task_Serial(void *p_arg);
void Task_Com(void *p_arg);
#endif  //_APP_H_  
