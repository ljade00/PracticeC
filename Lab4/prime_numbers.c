#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// checks if a # the prime
int primes(int num) {
  if (num <= 1)
    return 0;
  for (int i=2;i*i <= num;++i) {
    if (num % i == 0)
  return 0;
    }
  return 1;
}
// the thread function to p prime #'s 
void* show_primes(void* arg) {
  int limit = *(int*)arg;
    printf("Following are the prime numbers up to %d:\n", limit);
// go through numbers
  for (int i = 2; i <= limit; ++i) {
  if (primes(i))
// if prime - p the #
    printf("%d ", i);
    }
    printf("\n");
  return NULL;
}
int main(int argc, char* argv[]) {
// arguments are shown
if (argc != 2) {
  printf("The usage: %s <limit>\n", argv[0]);
  return 1;
}
// string to integer
int limit = atoi(argv[1]);
if (limit <= 0) {
  printf("Please enter a positive integer as the limit.\n");
  return 1;
}
// executes the show_primes 
  pthread_t tid;
    pthread_create(&tid, NULL, show_primes, &limit);
// waiting for the thread to get done 
      pthread_join(tid, NULL);

  return 0;
  }