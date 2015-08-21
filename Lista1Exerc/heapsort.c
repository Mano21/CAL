//program para realizar o sort de um vetor de elementos usando o metodo heap sort
//http://mybestcode.blogspot.com.br/2012/04/heap-sort-in-c.html


#include<stdio.h>
#include <sys/time.h>
#define MAX 100

void buildHeap(int [],int);
void HeapSort(int [],int n);

int main(){
	int vetor[MAX],n,i; //vetor para armazenar os elementos,total elementos,indice
	
	struct timeval inicio,final;
	int time;
	gettimeofday(&inicio,NULL);
	
	printf("Insira a quantidade de elementos: \n");
	scanf("%d",&n); //leitura da quantidade
	printf("Insira os elementos do vetor: \n");
	for(i=1;i<=n;i++){ //inserindo...
		scanf("%d",&vetor[i]);
	}
	HeapSort(vetor,n); //aplicando Heap
	printf("\nVetor com sort aplicado e: \n"); // mostrando vetor com HEAP
	for(i=1;i<=n;i++){
		printf("\t%d",vetor[i]);
	}
	printf("\n");
	
	gettimeofday(&final,NULL);
	time = (int)(1000*(final.tv_sec - inicio.tv_sec)+(final.tv_usec - inicio.tv_usec) / 1000);

	printf("\nTempo decorrido: %d millisegundos \n",time);
	
	return 0;
}

void buildHeap(int V[],int n){ //funcao para construir o Heap
	int i,j,k,l,heap;
	for(i=n/2;i>=1;i--){ //verificando a arvore como se faz nos desenhos de cima para baixo...
		k=i;
		l = V[k];
		heap = 0;
		while(heap == 0 && (2*k) <= n){
			j = 2*k;
			if(j<n){
				if(V[j] < V[j+1]){
					j++;
				}
			}
			if(l >= V[j]){
				heap = 1;
			}else{
				V[k] = V[j];
				k=j;
			}
		}
		V[k] = l;
	}
}


void HeapSort(int V[],int n){ //funçao Heapsort
	int i,t;
	for(i=n;i>=1;i--){
		buildHeap(V,i);
		t=V[1];
		V[1] = V[i];
		V[i]=t;
	}
}
