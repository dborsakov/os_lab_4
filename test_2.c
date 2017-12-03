#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define CHILD_COUNT 15

int child_arr[CHILD_COUNT] = {0};
int child_time_arr[CHILD_COUNT];
int count = 0;
pthread_mutex_t mutex, mut_write;

// pthread_t pthread_t_= pthread_self(); номер потока

/*
void add_fam(int t) {
  count++;
  b[count] = t;
}
*/
void *c() {
  //sleep(3);
  //unsigned int microseconds = 1000000;
  usleep(microseconds);
   //pthread_cond_timedwait(3);
  int id;
  pthread_mutex_lock(&mutex);
  id = count;
  count++;
  pthread_mutex_unlock(&mutex);

  child_arr[id] = 1;
  child_time_arr[id] = 2 + rand() % 9;

  pthread_mutex_lock(&mut_write);
  printf("%d ", id);
  printf("%d\n", child_time_arr[id]);
  pthread_mutex_unlock(&mut_write);



/*
    int n = *((int *)x);
    printf("%lu \n", pthread_self());
*/
    pthread_exit(0);
}

int main() {
  srand(getpid());

  //int f = 10;
  pthread_mutex_init(&mutex, NULL);
  pthread_mutex_init(&mut_write, NULL);
  pthread_t f1_thread, f2_thread;
  pthread_t thread[CHILD_COUNT];

  for (int i=0;i<CHILD_COUNT;i++){
    pthread_create(&thread[i], NULL, &c, NULL);
  }
  for (int i=0;i<CHILD_COUNT;i++){
    pthread_join(thread[i], NULL);
  }
  pthread_mutex_destroy(&mutex);
  pthread_mutex_destroy(&mut_write);
/*
  pthread_create(&f1_thread, NULL, c, NULL);
  pthread_create(&f2_thread, NULL, c, NULL);

  pthread_join(f1_thread, NULL);
  pthread_join(f2_thread, NULL);
*/

  //void *f2(); void *f1();
  //int i1=1, i2=0;
  //int x = CHILD_COUNT;

  //pthread_mutex_t mutex =  PTHREAD_MUTEX_INITIALIZER;

  //pthread_create(&f1_thread, NULL, new_visitor, NULL);
  //pthread_create(&f2_thread, NULL, f2, &x);

  //pthread_join(f1_thread, NULL);
  //pthread_join(f2_thread, NULL);


  return 0;
}
/*
void *visitor(){
int time = srand()%10+1; //random time
*/
