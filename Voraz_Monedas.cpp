/*PROBLEMA DE LAS MONEDAS; ALGORITMO VORAZ
* MONTSERRAT ALEJANDRA ULLOA RIVERA
* TEORÍA DE LA COMPLEJIDAD COMPUTACIONAL
*/
#include<stdio.h>
#define max  100

int ans[max];

int findMinCoins(int coins[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        //Evalua cuántas monedas se necesitan para coins[i]
        while(value >= coins[i])
        {
            //Después de tomar una moneda se reduce value
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;

    }

    return count;
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
