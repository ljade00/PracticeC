#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define num_threads 1 

// stores all the stats results
double average = 0.0;
int minimum = INT_MAX; // the int max
int maximum = INT_MIN; // the int min
// the thread for the avg, min, & max
void* compute_average(void* arg) {
  int* numbers = (int*)arg;
// count of #'s
  int count = numbers[0];
// computes the avg, min, & max
for (int i = 1; i <= count; ++i) {
  average += numbers[i];
    if (numbers[i] < minimum)
      minimum = numbers[i];
    if (numbers[i] > maximum)
      maximum = numbers[i];
    }
// calculates the avg
  average /= count; 
  pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
// checks if the correct # of args is there
  if (argc < 2) {
    printf("Usage: %s <number1> <number2> ... <numberN>\n", argv[0]);
      return 1;
    }
// calculates the # of ints as args
int num_count = argc - 1;
int* numbers = (int*)malloc((num_count + 1) * sizeof(int));
// stores the count of #'s 
  numbers[0] = num_count; 
// converts arg to ints and stores it 
  for (int i = 1; i <= num_count; ++i)
    numbers[i] = atoi(argv[i]);
// initializes the thread
pthread_t thread;
pthread_attr_t attr;
pthread_attr_init(&attr);
// creates the thread to give the avg, min, & max
pthread_create(&thread, &attr, compute_average, numbers);
// waiting for the thread to get done
pthread_join(thread, NULL);
// prints the results
  printf("The average value: %d\n", (int)average);
  printf("The minimum value: %d\n", minimum);
   printf("The maximum value: %d\n", maximum);
// free the memory
  free(numbers);
    return 0;
}