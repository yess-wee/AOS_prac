//inter process communication using pipe

#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    int p1[2],p2[2];
    int pid = fork();
    
    if(pid == 0){
        close(p1[0]);
        close(p2[1]);
        
        char s[20], data[20];
        
        read(p2[0],20);
        
        printf("p read %s\n",s);
        
        int fd1 = open(s,O_RDONLY);
        
        if(fd1>=0){
            read(fd1,&data,20);
            write(p1[1],&data,20);
        }
        else{
            write(p1[1],"error",20);
            
            printf("c to p read %s\n",s);
            close(p2[0]);
        }
    }
    else if(pid > 0){
        
        close(p1[1]);
        close(p2[0]);
        
        char s[20], data[20];
        
        printf("Enter: ");
        scanf("%[\n]%*c",&s);
        
        write(p2[1],&s,20);
        
        printf("data send p to c: %s",s);
        
        wait(NULL);
        
        read(p1[0],&data,20);
        
        printf("data recieved from c to p : %s\n",data);
        
        close(p1[1]);
        close(p2[0]);
        
        
    }
}
