#include <stdbool.h>
#include "../include/sort.h"

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort(int A[], int n, bool order) 
{
  bool swapped = false;
  int tmp;

  if (order) {
    for (int i = 0; i < n - 1; i++) {
      swapped = false;
      for (int j = 0; j < n - i - 1; j++) { 
        if (A[j] >= A[j + 1]) {
          swap(&A[j], &A[j + 1]);
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
  } else {
    for (int i = 0; i < n - 1; i++) { 
      swapped = false;
      for (int j = 0; j < n - i - 1; j++) { 
        if (A[j] <= A[j + 1]) {
          swap(&A[j], &A[j + 1]);
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
  }
}

void selectionSort(int A[],int n,bool order)
{
  int min,max,tmp,index;
  if(order){
    for (int i = 0; i < n;i++){
      index = i;
      min = A[i];
      for (int j = i + 1; j < n; j++){
        if (min > A[j]){
          min = A[j];
          index = j;
        }
      }
      swap(&A[i], &A[index]);
    }
  }else{
    for (int i = 0; i < n;i++){
      index = i;
      max = A[i];
      for (int j = i + 1; j < n; j++){
        if (max < A[j]){
          max = A[j];
          index = j;
        }
      }
      swap(&A[i],&A[index]);
    }
  }
}

void insertionSort(int A[],int n,bool order)
{
  int key,j;
  if(order){
    for (int i = 1; i < n; i++){
      key = A[i];
      j = i - 1;

      while (j >= 0 && A[j] > key){
        A[j + 1] = A[j];
        j--;
      }
      A[j + 1] = key;
    }
  }else{
    for (int i = 1; i < n; i++){
      key = A[i];
      j = i - 1;

      while (j >= 0 && A[j] < key){
        A[j + 1] = A[j];
        j--;
      }
      A[j + 1] = key;
    }
  }
}

void quickSort(int A[],int n,bool order){
  //
}

void mergeSort(int A[],int n,bool order){
  //
}

void (*mySort)(int[], int, bool) = bubbleSort;

