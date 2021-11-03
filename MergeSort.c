/*
Andrea de satiago legaspi
Merge Sort
*/
#include <stdio.h>
#define max 10

int A[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };

void merge(int ini, int m, int fin) {
	int B[fin-ini+1];
	int i=ini, j=m+1, k=0;
	
	while(i<=m && j<=fin){
		if(A[i]<A[j]){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	
	while(i<=m){
		B[k]=A[i];
		i++;
		k++;
	}
	
	while(j<=fin){
		B[k] = A[j];
		j++;
		k++;
	}
	
	i=ini;
	k=0;
	while(i<=fin){
		A[i] = B[k];
		i++;
		k++;
	}
	
}

void mergeSort(int ini, int fin) {
   int m;
   if(ini >= fin){return;}
   else {
      m = (ini + fin) / 2;
      mergeSort(ini, m);
      mergeSort(m+1, fin);
      merge(ini, m, fin);
   }  
}

int main() { 
   int i;

   printf("Vector que se va a ordenar:\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", A[i]);

   mergeSort(0, max);

   printf("\nVector ordenado\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ",A[i]);
      
    return 0;
}
