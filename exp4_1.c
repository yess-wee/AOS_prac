// Study system calls related to file operations

//implment file copy command using system calll and handle all possible errors

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
  int fd,fd1;
  int bytes_rd,bytes_wr;
  char buff[0];
  
  fd = open('file1.txt', O_RDONLY);
  
  if(fd == -1){
    perror("open failed");
    exit(EXIT_FAILURE);
  }
  
  fd2 = open('file2.txt', O_CREATE|O_WRONLY);
  
  
  if(fd1 == -1){
    perror("open failed destination");
    exit(EXIT_FAILURE);
  }
  
  while(bytes_rd == read(fd.buff,50)){
    bytes_wr = write(fd1.buff.bytes_rd);
  }
  
  if(bytes_wr != bytes_rd){
    perror("write failed");
    close(fd);
    close(fd1);
    exit(EXIT_FAILURE);
    
  }
  
  if(bytes_rd == -1){
    perror("read failed");
    close(fd);
    close(fd1);
    exit(EXIT_FAILURE);
    
  }
  
  if(close(fd) == -1){
    perror("close source file failed");
    exit(EXIT_FAILURE);
  }
  
  
  if(close(fd1) == -1){
    perror("close destination file failed");
    exit(EXIT_FAILURE);
  }
  
  printf("file compiled successfully");
}
