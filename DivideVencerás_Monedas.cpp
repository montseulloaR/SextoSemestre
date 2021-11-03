#include <bits/stdc++.h>
#include <windows.h>
#include<vector>

int findMinCoins(int coins[], int size, int value){
    	int sol[size], mySol[size];
    	int myFinalSol, k;
		
		/*Caso base*/
		//Si el monto del cambio = 0
       if ( value == 0 )
	   {
           return(0);
       }
       
       /*Inicializar el vector de soluciones*/
       // -1 significa que no fue valido
       for ( k = 0; k < size; k++ ) mySol[k] = -1;                  

	 	/*Probar cada denominacion del vector de las monedas*/
       for ( k = 0; k < size; k++ )
       {
          /*Probar si la denominacion es valida para dar el cambio*/
          if ( coins[k] <= value )
          {
             /*DIVIDIR*/
             sol[k] = findMinCoins(coins, size, value - coins[k]);  // Se usa la moneda coin[k] como la utlima mondeda

             mySol[k] = sol[k] + 1;    // Solucion para $j  
          }
       }
       
       myFinalSol = -1; 
		
		/*Verificar cual de las soluciones encontradas es la menor*/
       for ( k = 0; k < size; k++ )
       {
          if ( mySol[k] >= 0)
          {
             if ( myFinalSol == -1 || mySol[k] < myFinalSol )
                myFinalSol = mySol[k];
          }
       }

       return(myFinalSol);   // Regresar la mejor solucion
   }
   
int main(){
	int value, i;
	int coins[] = {9, 6, 5, 1};
    int size = sizeof(coins)/sizeof(coins[0]);
    
    printf("Vector de monedas disponisbles: ");
    for(int i=0; i<size; i++){
    	printf("%d ", coins[i]);
	}
	
	printf("\nMonto: " );
	scanf("%d", &value);

    printf("Total de monedas: %d\n", findMinCoins(coins, size, value));
	return 0;
}
