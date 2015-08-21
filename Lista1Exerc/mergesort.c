#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void Merge(int * , int , int , int );
/* Logica: USAR O METODO DE DIVIDIR E CONQUISTAR...
         1 - Dividir o vetor em duas partes e chamar as partes de metade direita e metade esquerda.
         exemplo: 1 5 2 7 10 23 0 54
         * parte esquerda: 1 5 2 7
         * parte direita: 10 23 0 54
         
         2 - aplicar o sort nas duas metades
		
		 3 - e usar o merge para juntar novamente as metades.
*/      
void MergeSort(int *array, int left, int right)
{
        int mid = (left+right)/2;
        /* We have to sort only when left<right because when left=right it is anyhow sorted*/
        if(left<right)
        {
                /* aplica o sort na parte esquerda*/
                MergeSort(array,left,mid);
                /* aplica o sort na parte direita */
                MergeSort(array,mid+1,right);
                /* aplica o merge nas duas partes*/
                Merge(array,left,mid,right);
        }
}
/* Merge functions merges the two sorted parts. Sorted parts will be from [left, mid] and [mid+1, right].
 */
void Merge(int *array, int left, int mid, int right)
{
        /*usar um array temporario para armazenar o novo vetor ao qual vai aplicar o sort*/
        int tempArray[right-left+1];
        int pos=0,lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right)
        {
                if(array[lpos] < array[rpos])
                {
                        tempArray[pos++] = array[lpos++];
                }
                else
                {
                        tempArray[pos++] = array[rpos++];
                }
        }
        while(lpos <= mid)  tempArray[pos++] = array[lpos++];
        while(rpos <= right)tempArray[pos++] = array[rpos++];
        int iter;
    
        for(iter = 0;iter < pos; iter++)
        {
                array[iter+left] = tempArray[iter];
        }
        return;
}
int main(){
        int number_of_elements;
        printf("Insira a quantidade de elementos:\n");
        scanf("%d",&number_of_elements);
        int array[number_of_elements]; 
        int iter;
        
        struct timeval inicio,final;
		int time;
		gettimeofday(&inicio,NULL);
        
        for(iter = 0;iter < number_of_elements;iter++)
        {
                scanf("%d",&array[iter]);
        }
        /* chamada para aplicar o sort no vetor */
        MergeSort(array,0,number_of_elements-1); 
        for(iter = 0;iter < number_of_elements;iter++)
        {
                printf("Vetor[%d]: %d \n",iter,array[iter]);
        }
        printf("\n");
	
		gettimeofday(&final,NULL);
		time = (int)(1000*(final.tv_sec - inicio.tv_sec)+(final.tv_usec - inicio.tv_usec) / 1000);

		printf("Tempo decorrido: %d segundos \n",time);

        return 0;
}
