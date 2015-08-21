#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*

Complexidade do Pior Caso: O(n²);
Complexidade Caso Médio: O(n²);
Complexidade Melhor Caso: O(n);
*/


/*
Incluir a biblioteca <sys/time.h> e usar a função gettimeofday() que 
* recebe um ponteiro para uma estrutura struct timeval e preenche seus 
* campos com os dados do tempo decorrido desde o último boot.
*  A estrutura struct timeval é uma estrutura que contem dois campos: 
* tv_sec e tv_usec. O primeiro indica o número de segundos decorridos 
* desde o último boot, e o segundo o número de microsegundos decorridos
*  desde o último segundo. Ao chamar a função gettimeofday() você deve 
* passar como primeiro parâmetro um ponteiro para uma struct timeval e 
* como segundo parâmetro o valor NULL. A função  então popula os campos 
* tv_sec e tv_usec. Veja o manual da função gettimeofday() para maiores 
* informações.

*/



void insertionSort (int numeros[], int tam)
{

     int i,j,eleito;    //O(1);
     
     for(i=1; i<tam; i++){     //O(n);
              eleito = numeros[i];    //O(1);
              j=i-1;   //O(1);
              while((j>=0)&& (eleito<numeros[j])){  //O(n);
                             numeros[j+1] = numeros[j];    //O(1);
                             j--;         //O(1);                      
              }
              numeros[j+1] = eleito;      //O(1);
     }
}

int main(){

    int numeros[5];        //O(1);
    int i;                 //O(1);
    int n;                 //O(1);
	struct timeval inicio,final;
	int time;
	gettimeofday(&inicio,NULL);


    n=5;                   //O(1);
    
    for(i=0; i<5; i++){    //O(n);
             printf("Entre com o numero %d: ", i+1);                   //O(5);
             scanf("%d", &numeros[i]);  //O(1);
    }
    
    insertionSort(numeros,n );          //-
    
    for (i=0;i<n;i++){      //O(n);
        printf("\nNumeros[%d]: %d",i+1,numeros[i]);                    //O(1);    
    }
    printf("\n\n");            //O(1);
	

	gettimeofday(&final,NULL);
	time = (int)(1000*(final.tv_sec - inicio.tv_sec)+(final.tv_usec - inicio.tv_usec) / 1000);

	printf("Tempo decorrido: %d millisegundos \n",time);
   
	return 0;
}
