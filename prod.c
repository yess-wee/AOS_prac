#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define buff_size 5

sem_t mutex,full,empty;
int count = 0;
int in = 0, out = 0;
int item = 0;
int buff[buff_size];

void *producer(){

  for(int i=0;i<=3;i++){
    sem_wait(&empty);
    sem_wait(&mutex);

    item++;

    while(count == buff_size){
      printf("Buffer is full\n");
    }

    in = (in+1)%buff_size;
    buff[in] = item;

    printf("producer produced : %d at location %d\n",item,in);
    
    count++;

    sem_post(&mutex);
    sem_post(&full);
  }
}

void *consumer(){

  for(int i=0;i<=3;i++){

    sem_wait(&full);
    sem_wait(&mutex);

    while(count == 0){
      printf("Buffer is empty\n");
    }

    out = (out+1)%buff_size;
    item = buff[out];

    printf("consumer consumed %d at location %d\n",item,out);

    sem_post(&mutex);
    sem_post(&empty);
  }
  
}

int main(){
  sem_init(&mutex,0,1);
  sem_init(&full,0,0);
  sem_init(&empty,0,buff_size);

  pthread_t prod,cons;
  pthread_create(&prod,NULL,producer,NULL);
  pthread_create(&cons,NULL,consumer,NULL);

  pthread_join(prod,NULL);
  pthread_join(cons,NULL);

  sem_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);
  
}


//output

// producer produced : 1 at location 1
// producer produced : 2 at location 2
// producer produced : 3 at location 3
// producer produced : 4 at location 4
// consumer consumed 1 at location 1
// consumer consumed 2 at location 2
// consumer consumed 3 at location 3
// consumer consumed 4 at location 4
