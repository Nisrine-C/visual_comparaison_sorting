#include <stdbool.h>
#include <stdlib.h>
#include "../include/sort.h"

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int A[],int low,int high, bool order){
	int pivot = A[high];
	int i = (low-1);
	for (int j = low; j < high; j++){
		if ((order && A[j] < pivot) || (!order && A[j] > pivot)){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1], &A[high]);
	return (i+1);
}

void merge(int A[], int left, int mid, int right, bool order) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if ((order && L[i] <= R[j]) || (!order && L[i] >= R[j])) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(int A[], int left, int right, bool order) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(A, left, mid, order);
        mergeSortHelper(A, mid + 1, right, order);
        merge(A, left, mid, right, order);
    }
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

/*
void quickSort(int A[],int n,bool order){
  int low = A[0];
  int high = A[n-1];
  if(low < high){
    int pivotIndex = partition(A,low,high,order);
    quickSort(A,low,pivotIndex-1,order);
    quickSort(A,pivotIndex+1,high,order);
	}
}
*/

void countingSort(int A[], int n, bool order) {
    if (n <= 0) {
        return;
    }
    int max_value = A[0];
    int min_value = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max_value) {
            max_value = A[i];
        }
        if (A[i] < min_value) {
            min_value = A[i];
        }
    }
    int range = max_value - min_value + 1;
    int* count = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < n; i++) {
        count[A[i] - min_value]++;
    }

    int index = 0;

    if (order) {
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                A[index] = i + min_value;
                index++;
                count[i]--;
            }
        }
    } else {
        for (int i = range - 1; i >= 0; i--) { // Fixed the loop condition
            while (count[i] > 0) {
                A[index] = i + min_value;
                index++;
                count[i]--;
            }
        }
    }

    free(count);
}

void mergeSort(int A[],int n,bool order){
  mergeSortHelper(A, 0, n - 1, order);
}

void (*mySort)(int[], int, bool) = bubbleSort;

