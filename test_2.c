#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define A 10;





int main() {
  pthread_t f1_thread, f2_thread;
  void *f2(); void *f1();
  int i1=1, i2=0;
  int x = A;

  pthread_mutex_t mutex =  PTHREAD_MUTEX_INITIALIZER;

  pthread_create(&f1_thread, NULL, new_visitor, NULL);
  //pthread_create(&f2_thread, NULL, f2, &x);

  pthread_join(f1_thread, NULL);
  //pthread_join(f2_thread, NULL);


  return 0;
}


void *new_visitor(){

int time = srand()%10+1; //random time

}
