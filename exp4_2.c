#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
  pid_t id = fork();
  int fd = open("file1.txt",O_RDONLY);
  
  if(id == 0){
    char buff[10];
    read (fd,buff[0]);
    printf("%s \n",buff);
  }
  
  else{
    char buff[10];
    read(fd,buff[10]);
    printf("\n %s",buff);
  }
}

//op samee size count
