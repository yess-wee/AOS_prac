// AIM: WAP that use fork() and assign some different task to child process and make
// sure that parent exist after child fineshes


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
  int a = fork();
  
  if(a<0){
    printf("child not created! \n");
  }
  else if(a == 0){
    printf("child created! \n");
    //task
    execlp("bin/ls","1s",NULL);
    
    printf("child terminated! \n");
  }
  else if(a > 0){
    printf("parent created! \n");
    wait(NULL);
    printf("parent terminated!\n");
  }
}
