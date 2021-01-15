/* Name: Harman Singh
   Roll_Number: 2019042 */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h>
#include<time.h>

#define SYS_rtnice 441

int main()
{
  
int option;
long op_pid;
  long soft_req;
  printf("Enter soft-realtime-requirements for the parent process : ");
  scanf("%ld",&soft_req);
  printf("Enter 1 if you want to give the value of pid (for the parent process) else enter 0: ");
  scanf("%d",&option);
  if(option==1){
    printf("Enter pid : ");
    scanf("%ld",&op_pid);
  }

  

  pid_t pid=fork();
  if(pid<0){
    perror("The child can't be forked.");
    exit(-1);
  }

  if(pid==0){
   
    clock_t tim=clock();
    for(int i=0;i<100000000;i++);{


    }
    tim=clock()-tim;
  
    printf("Time taken by the child process is %lf ms\n",(((double)tim)/CLOCKS_PER_SEC)*1000);
  }



  else{

    long ans;

    if(option==0){
      ans=(long)getpid();
    }
    else{
      ans=op_pid;
    }
    
    wait(NULL);
    int res=syscall(SYS_rtnice,ans,soft_req);
    if(res!=0){

  

    printf("System call did not get executed succesfully\n");
    printf("System call returned %d.\n", res);
    perror("The process encountered an error ");
    printf("\nError No. : %d\n",errno);

    exit(-1);

   }

   
    clock_t tim=clock();
    for(int i=0;i<100000000;i++);{

    }
    tim=clock()-tim;
   
    printf("Time taken by the parent process is %lf ms\n",(((double)tim)/CLOCKS_PER_SEC)*1000);


  }
  
  return 0;
}



