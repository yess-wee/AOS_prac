#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3
#define MAX_ITEMS 3

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;


pthread_mutex_t lock;


void* producer(void* arg) {
   int item = 1;

    for(int i=0;i<3;i++){
        
        
    
      pthread_mutex_lock(&lock);

      while (count == BUFFER_SIZE);

      buffer[in] = item;
      printf("Produced: %d\n", item);
      item++;
      in = (in + 1) % BUFFER_SIZE;

      count++;

      pthread_mutex_unlock(&lock);
      
      
    }
   

//   pthread_exit(NULL);
}

void* consumer(void* arg) {
    
    for(int i=0;i<3;i++){
        
    
  
      pthread_mutex_lock(&lock);

      while (count == 0) ;

      int item = buffer[out];
      printf("Consumed: %d\n", item);
      out = (out + 1) % BUFFER_SIZE;

      count--;

      
      pthread_mutex_unlock(&lock);
      
      
    }
   

   //pthread_exit(NULL);
}

int main() {
   pthread_t producerThread, consumerThread;

   pthread_mutex_init(&lock, NULL);
 

   pthread_create(&producerThread, NULL, producer, NULL);
   pthread_create(&consumerThread, NULL, consumer, NULL);

   pthread_join(producerThread, NULL);
   pthread_join(consumerThread, NULL);

   pthread_mutex_destroy(&lock);
 

   return 0;
}


//output:

// Produced: 1
// Produced: 2
// Produced: 3
// Consumed: 1
// Consumed: 2
// Consumed: 3
