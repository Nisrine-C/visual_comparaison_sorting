#ifndef SORT_H
#define SORT_H

void bubbleSort(int A[],int n,bool order); //tri a bulle
void selectionSort(int A[],int n,bool order); //tri par selection
void insertionSort(int A[],int n,bool order); //tri par insertion
void quickSort(int A[],int n,bool order); //tri rapide
void countingSort(int A[], int n, bool order);
void mergeSort(int A[],int n,bool order); //tri par fusion


extern void (*mySort)(int[], int, bool);//fonction generique

#endif /* SORT_H */