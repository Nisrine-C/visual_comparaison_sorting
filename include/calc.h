#ifndef CALC_H
#define CALC_H

void initRand(int A[], int n);//random array initialisation ( takes Array and arraySize)
void initRandNeg(int A[], int n);//random array initialisation ( takes Array and arraySize)

float calc(void (*mySort)(int[], int, bool),int[] , int,bool); //calculates the time necessary for a sort (takes sorting function and arraySize)
void movingAverage(float[], int, int );
/*void lisserMesures(float [] [], int, int);//calcul des moyens ponderees ???*/

//structure des donnees pour les differentes mesures => matrice
#define MAX_PTS 10000
#define MAX_METH 10


#endif /* CALC_H */