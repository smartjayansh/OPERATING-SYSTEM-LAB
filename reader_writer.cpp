#include<stdio.h>   
#include<semaphore.h>   
#include<windows.h>
#include<iostream>
#include<pthread.h>
#include<cstdint>
int cpp =6;
 void * reader(void *) ;  
 void * writer (void *) ;  
 sem_t wsem,mutex ;  
 int readcount=0 ;  
 main()  
 {  
  int a=1,b=1;  
  sem_init(&wsem,0,1) ;  
  sem_init(&mutex,0,1) ;  
  pthread_t r,w,r1,w1 ;  
  pthread_create(&r,NULL,reader,(void *)a);  
     a++;  
  pthread_create(&w1,NULL,writer,(void *)b);  
     b++;  
  pthread_create(&r1,NULL,reader,(void *)a);  
  pthread_create(&w,NULL,writer,(void *)b);  
  pthread_join(r,NULL);  
  pthread_join(w1,NULL);  
  pthread_join(r1,NULL);  
  pthread_join(w,NULL) ;  
  printf("main terminated and final value of variable is %d \n",cpp);  
 }  
 void * reader(void * arg)  
 {  
  intptr_t c=(intptr_t)arg ;  
  printf("\nreader %d is created",c);  
     Sleep(1);  
  sem_wait(&mutex) ;  
     readcount++;  
     if(readcount==1)  
         sem_wait(&wsem) ;  
  sem_post(&mutex) ;  
 /*Critcal Section */  
  printf("\n\nreader %d is reading\n ",c);
  printf("Value of variable is %d\n",cpp);  
  Sleep(1) ;  
  printf("\nreader%d finished reading\n",c);  
 /* critical section completd */  
  sem_wait(&mutex) ;  
     readcount-- ;  
     if(readcount==0)  
         sem_post(&wsem) ;  
  sem_post(&mutex) ;  
 }  
 void * writer(void * arg)  
 {  
  intptr_t c=(intptr_t)arg ;  
  printf("\nwriter %d is created",c);  
     Sleep(1);  
  sem_wait(&wsem) ;  
  printf("\nwriter %d is writing and incrementing the value of variable\n",c) ;  
  cpp++;
  Sleep(1);  
  printf("\nwriter%d finished writing\n",c);  
  sem_post(&wsem) ;  
 }
