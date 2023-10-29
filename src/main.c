#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

void generateFile(int n){
  FILE *fp = NULL;
  char name[20];
  sprintf(name, "file_%d.data", n);
  fp = fopen(name, "w");
  int j = 0;
  for (int i = 0; i <= 10000; i=i+250)
  {
    fprintf(fp, "%d %.2f\n", i, matrix[j][n]);
    j++;
  }
}

int main(){
  generateYaxis(true);
  for (int i = 1; i < 4; i++){
    generateFile(i);
  }
  char sortingFunctions[5][20] = {
    "bubbleSort",
    "insertionSort",
    "selectionSort",
    //quickSort,
    //mergeSort
  };
  FILE *gnupipe = NULL;
  char *GnuCommands[] = {
    "set title \"Sort\"", 
    "plot 'file_1.data' w lp title 'bubble', 'file_2.data' w lp title 'insertion', 'file_3.data' w lp title 'selection'"};  
  gnupipe = _popen("gnuplot -persisten", "w");
  for (int i = 0; i < 2; i ++){
    fprintf(gnupipe, "%s\n", GnuCommands[i]);
  }

  /*
  FILE *fp = NULL;
  FILE *gnupipe = NULL;
  char *GnuCommands[] = {"set title \"Sort\"", "plot 'data.tmp' w lp ","plot 'dat.tmp w lp"};

  fp = fopen("data.tmp","w");
  gnupipe = _popen("gnuplot -persisten", "w");
  if (gnupipe == NULL)
  {
    printf("Error: Unable to open gnuplot.\n");
    return 1;
  }
  fprintf(gnupipe, "%s\n", GnuCommands[0]);
  */
  return 0;
}

