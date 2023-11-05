#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "../include/calc.h"
#include "../include/sort.h"


float calcs[MAX_PTS][MAX_METH];
int nb_pts = 0, nb_meth = 0;

void initRand(int A[], int n)
{
  for (int i = 0; i < n; i++){
    A[i] = rand();
  }
}

void initRandNeg(int A[], int n)
{
  for (int i = 0; i < n; i++){
    if(i % 2 == 0){
      A[i] = rand();
    }else{
      A[i] = rand() - RAND_MAX/2;
    }
  }
}

float calc(void (*mySort)(int[], int, bool),int arr[], int size,bool order) {
    clock_t start, end;
    float execution_time;

    // Record the start time
    start = clock();

    // Call the sorting function
    mySort(arr, size,order);
  
    // Record the end time
    end = clock();

    // Calculate the execution time in seconds
    execution_time = (float)(end - start) / CLOCKS_PER_SEC;

    return execution_time;
}

void movingAverage(float data[], int n, int window) {
  for (int i = 0; i < n; i++) {
    float sum = 0;
    int count = 0;
    for (int j = i - window / 2; j <= i + window / 2; j++) {
      if (j >= 0 && j < n) {
        sum += data[j];
        count++;
      }
    }
    data[i] = sum / count;
  }
} 