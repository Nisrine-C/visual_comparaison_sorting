#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/sort.h"
#include "../include/calc.h"

int arraySize=0;
#define ROWS  41
#define COLUMNS  6

float matrix[ROWS][COLUMNS];

void (*sortingFunctions[])(int[], int, bool) = {
  bubbleSort,
  insertionSort,
  selectionSort,
  //quickSort,
  //mergeSort
};

void generateXaxis(){
  FILE *fp = NULL;
  fp = fopen("X-axis", "w");
  int j = 0;
  for (int i = 0; i <= 10000; i=i+250)
  {
    matrix[j][0] = i;
    fprintf(fp,"%d \n",i);
    j++;
  }
}

void generateYaxis(int order){
  int k = 0;
  for (int i = 0; i <= 10000; i=i+250)
  {
    arraySize = i;
    int A[arraySize],B[arraySize];
    initRand(A, arraySize);
    for (int j = 1; j < 4; j++){
      for (int l = 0; l < arraySize; l++){
        B[l] = A[l];
      }
      mySort = sortingFunctions[j - 1];
      float time = calc(mySort, B, arraySize, order);
      matrix[k][j] = time;
    }
    k++;
  }
}

int main(){
  generateXaxis();
  generateYaxis(true);

  for (int row=0; row<ROWS; row++)
  {
    for(int columns=0; columns<COLUMNS; columns++)
    {
      printf("%.2f | ", matrix[row][columns]);
    }
    printf("\n");
  }
  
  
  
  
  /*
  FILE *fp = NULL;
  FILE *fp2 = NULL;
  FILE *gnupipe = NULL;
  char *GnuCommands[] = {"set title \"Sort\"", "plot 'data.tmp' w lp ","plot 'dat.tmp w lp"};

  fp = fopen("data.tmp","w");
  gnupipe = _popen("gnuplot -persisten", "w");
  if (gnupipe == NULL)
  {
    printf("Error: Unable to open gnuplot.\n");
    return 1;
  }
  for (int i = 0; i < 10000; i=i+500)
  {
    arraySize = i;
    int A[arraySize];
    initRand(A, arraySize);
    mySort = selectionSort;
    float time = calc(mySort,A,arraySize,1);
    fprintf(fp, "%d %.2f\n", i, time);
  }
  fprintf(gnupipe, "%s\n", GnuCommands[0]);
  for (int i = 0; i < 10000; i=i+500)
  {
    arraySize = i;
    int A[arraySize];
    initRand(A, arraySize);
    mySort = selectionSort;
    float time = calc(mySort,A,arraySize,1);
    fprintf(fp, "%d %.2f\n", i, time);
  }
  */
  return 0;
}

