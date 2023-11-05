#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h> 
#include <math.h> 
#include <conio.h>
#include "../include/sort.h"
#include "../include/calc.h"

int arraySize = 0;
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

    for (int column = 0; column < COLUMNS; column++) {
      movingAverage(matrix[column], ROWS,COLUMNS);
    }
    k++;
  }
}

void generateYaxis2(int order){
  int k = 0;
  for (int i = 0; i <= 10000; i=i+250)
  {
    arraySize = i;
    int A[arraySize];
    initRand(A, arraySize);
    mySort(A, arraySize,order);
    for (int j = 1; j < 4; j++){
      mySort = sortingFunctions[j - 1];
      float time = calc(mySort, A, arraySize, order);
      matrix[k][j] = time;
    }
    for (int column = 0; column < COLUMNS; column++) {
      movingAverage(matrix[column], ROWS,COLUMNS);
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
  fclose(fp);
}

void menu(){
  char *GnuCommands[] = {
    "set title \"Sort\"",
    "plot 'file_1.data' w l title 'bubble', 'file_2.data' w l title 'insertion', 'file_3.data' w l title 'selection'"
  };        
  FILE *gnupipe = NULL;   
  while(true){
    aa:
    system("cls");
    gnupipe = _popen("gnuplot -persistent", "w");
    printf("                         Sorting Visualiser\n");
    printf("1.  Standard Random Array                    ");
		printf("2.  Pre Sorted Array           \n");
		printf("3.  exit\n");
    switch(getch()){
			case 49:
      while(true){
        printf("                         Sorting Visualiser\n");
        printf("1.  Ascending                   ");
        printf("2.  Descending                \n");
        printf("3.  Back\n");
        switch(getch()){
          case 49:
            generateYaxis(true);
            for (int i = 1; i < 4; i++){
              generateFile(i);
            }
            for (int i = 0; i < 2; i ++){
              fprintf(gnupipe, "%s\n", GnuCommands[i]);
            }
            _pclose(gnupipe);
             
            goto aa;
          case 50:
            generateYaxis(false);
            for (int i = 1; i < 4; i++){
              generateFile(i);
            }
            for (int i = 0; i < 2; i ++){
              fprintf(gnupipe, "%s\n", GnuCommands[i]);
            }
            _pclose(gnupipe);
             
            goto aa;
          case 51:
            goto aa;
          default:;
        }
      }
      case 50:   
      while(true){
        printf("                         Sorting Visualiser\n");
        printf("1.  Ascending                   ");
        printf("2.  Descending                \n");
        printf("3.  Back\n");
        switch(getch()){
          case 49:
            generateYaxis2(true);
            for (int i = 1; i < 4; i++){
              generateFile(i);
            }
            for (int i = 0; i < 2; i ++){
              fprintf(gnupipe, "%s\n", GnuCommands[i]);
            }
            _pclose(gnupipe);
            
            goto aa;  
          case 50:
            generateYaxis2(false);
            for (int i = 1; i < 4; i++){
              generateFile(i);
            }
            
            for (int i = 0; i < 2; i ++){
              fprintf(gnupipe, "%s\n", GnuCommands[i]);
            }
            _pclose(gnupipe);
             
            goto aa;
          case 51:
            goto aa;
          default:;
        }
      }
      case 51:
        exit(1);
			default:;
    }
  }
}

int main(){
  menu();
  return 0;
}

