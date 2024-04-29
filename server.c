//inter process communication using shared memory

//server-client

#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<time.h>

int main(){
    void *ptr;
    
    int shm_fd = shm_open("shared",O_CREAT|O_RDWR,0777);
    
    if(shm_fd == -1){
        printf("Error \n");
    }
    
    f_truncate(shm_fd,4096);
    
    ptr = mmap(NULL,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
    
    char buffer[4096];
    
    read(shm_fd,buffer,4096);
    
    printf("client recieve %s\n",buffer);
    
    return 0;
}

