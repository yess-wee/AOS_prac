#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3
#define MAX_ITEMS 3

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;


pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;

void* producer(void* arg) {
   int item = 1;

    for(int i=0;i<3;i++){
        
        
    
      pthread_mutex_lock(&mutex);

      while (count == BUFFER_SIZE) {
         pthread_cond_wait(&empty, &mutex);
      }

      buffer[in] = item;
      printf("Produced: %d\n", item);
      item++;
      in = (in + 1) % BUFFER_SIZE;

      count++;

      pthread_cond_signal(&full);
      pthread_mutex_unlock(&mutex);
      
      
    }
   

//   pthread_exit(NULL);
}

void* consumer(void* arg) {
    
    for(int i=0;i<3;i++){
        
    
  
      pthread_mutex_lock(&mutex);

      while (count == 0) {
         pthread_cond_wait(&full, &mutex);
      }

      int item = buffer[out];
      printf("Consumed: %d\n", item);
      out = (out + 1) % BUFFER_SIZE;

      count--;

      pthread_cond_signal(&empty);
      pthread_mutex_unlock(&mutex);
      
      
    }
   

   //pthread_exit(NULL);
}

int main() {
   pthread_t producerThread, consumerThread;

   pthread_mutex_init(&mutex, NULL);
   pthread_cond_init(&full, NULL);
   pthread_cond_init(&empty, NULL);

   pthread_create(&producerThread, NULL, producer, NULL);
   pthread_create(&consumerThread, NULL, consumer, NULL);

   pthread_join(producerThread, NULL);
   pthread_join(consumerThread, NULL);

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&full);
   pthread_cond_destroy(&empty);

   return 0;
}



//output:

// Produced: 1
// Produced: 2
// Produced: 3
// Consumed: 1
// Consumed: 2
// Consumed: 3
