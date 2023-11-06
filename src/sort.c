#include <stdbool.h>
#include <stdlib.h>
#include "../include/sort.h"


void swap(int *a,int *b){//fonction de permutation
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void merge(int A[], int left, int mid, int right, bool order) {//fonction de fusion
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

void mergeSortHelper(int A[], int left, int right, bool order) {//fonction d'aide de tri par fusion
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(A, left, mid, order);
        mergeSortHelper(A, mid + 1, right, order);
        merge(A, left, mid, right, order);
    }
}

void bubbleSort(int A[], int n, bool order) { // tri a bulles
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

void selectionSort(int A[],int n,bool order){ //tri par selection
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

void insertionSort(int A[],int n,bool order){ //tri par insertion
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

void countingSort(int A[], int n, bool order) { // tri par comptage
    if (n <= 0) {
        return;
    }
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    // Create a count array to store the count of each element
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Reconstruct the sorted array from the count array
    int index = 0;
    if (order) {  // Ascending order
        for (int i = 0; i <= max; i++) {
            while (count[i] > 0) {
                A[index] = i;
                index++;
                count[i]--;
            }
        }
    } else {  // Descending order
        for (int i = max; i >= 0; i--) {
            while (count[i] > 0) {
                A[index] = i;
                index++;
                count[i]--;
            }
        }
    }
}

void mergeSort(int A[],int n,bool order){ // tri par fusion
  mergeSortHelper(A, 0, n - 1, order);
}

void (*mySort)(int[], int, bool) = bubbleSort; // fonction generique (par default:tri a bulle)
 
