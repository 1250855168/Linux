
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *x(void *arg) {
  int i = (long)arg;
  printf("%d\n", i);
  return NULL;
}

int main() {
  pthread_t xxx;

  long i = 10;
  printf("%ld\n", sizeof(void *));
  printf("%ld\n", sizeof(int *));
  printf("%ld\n", sizeof(long *));
  void *g = (void *)i;

  printf("%d\n", (int)i);

  pthread_create(&xxx, NULL, x, (void*)g);
  sleep(1);
  return 0;
}