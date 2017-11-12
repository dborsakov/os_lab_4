#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define A 10;


struct Fam {
  int count; //uniq number
  static int c=0;
  int tm; //time
  bool bl; // responsible child
  Fam *next;
}

typedef Fam *PFam;
PFam HEAD = NULL;
PFarm LAST = NULL;

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

  for (int i=0;i<10;i++) {

  int time = srand()%10+1; //random time
  PFarm NewNode = CreateFam(time);
  if (HEAD == NULL)
    {
      NewNode -> next = HEAD;
      HEAD = NewNode;
      LAST = NewNode;
    }
  else
    {
      NewNode -> next = LAST -> next;
      LAST -> next = NewNode;
    }
}
}


PFam CreateFam (int time) {
  PFam NewFam = new Fam; //point new
  NewFam->tm = time;
  NewFam->c++;
  NewFam->count = NewFam->c;
  return NewNode;
}

void AddFirst (PFam &Head, PNode NewNode)
{

}
/*void *f1(int *x) {
  sleep(1);
  *x=*x+5;
  printf("f1: %d\n", *x);
  pthread_exit(0);
}

void *f2(int *x) {
    sleep(20);
    *x=*x-5;
    printf("f2: %d\n", *x);
    pthread_exit(0);
}
*/
