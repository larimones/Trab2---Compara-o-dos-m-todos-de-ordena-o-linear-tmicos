#include <time.h>
#include<stdio.h>
#include<stdlib.h>
int vet[];
//ordena por HeapSort

void rebuild(int vetor[], int MAX, int pos)
{        
    int c1, c2;
    
    c1 = 2 * pos;
    c2 = c1 + 1;
    
    if(c1 > MAX || (vetor[pos - 1] >= vetor[c1 - 1] && vetor[pos - 1] >= vetor[c2 - 1]))
        return;
    
    int greater_index = -1;
    
    if(c2 >MAX)
        greater_index = c1;
    else
    {        
        if(vetor[c1 - 1] > vetor[c2 - 1])
            greater_index = c1;
        else
            greater_index = c2;
    }
    
    if(greater_index != -1)
    {
        int aux = vetor[greater_index - 1];
        vetor[greater_index - 1] = vetor[pos - 1];
        vetor[pos - 1] = aux;
        rebuild(vetor, MAX, greater_index);
    }
}
void build(int vetor[], int Vsize)
{
    int left;
    
    if(Vsize % 2 == 0)
        left = Vsize / 2 + 1;
    else
        left = (Vsize - 1) / 2 + 1;
    
    while(left > 1)
    {
        left--;
        rebuild(vetor, Vsize, left);
    }
}

void HeapSort(int vetor[], int Vsize)
{
    
  build(vetor, Vsize);
  int MAX = Vsize;
  while(1)
  {        
    int aux = vetor[0];
    vetor[0] = vetor[MAX- 1];
    vetor[MAX - 1] = aux;
    rebuild(vetor, MAX - 1, 1); 
    MAX--;

    if(MAX <= 2 && vetor[0] <= vetor[1])
      break;
  }
}
//Ordena por mergesort

void Merge(int *A,int *B,int leftCount,int *T,int rightCount) {
    int i,j,k;

    i = 0; j = 0; k =0;

    while(i<leftCount && j< rightCount) {
        if(B[i]  < T[j]) A[k++] = B[i++];
        else A[k++] = T[j++];
    }
    while(i < leftCount) A[k++] = B[i++];
    while(j < rightCount) A[k++] = T[j++];
}


void MergeSort(int *A,int n) {
    int mid,i, *B, *T;
    if(n < 2) return;
    mid = n/2;  

    B = (int*)malloc(mid*sizeof(int)); 
    T = (int*)malloc((n- mid)*sizeof(int)); 
    
    for(i = 0;i<mid;i++) B[i] = A[i]; 
    for(i = mid;i<n;i++) T[i-mid] = A[i]; 

    MergeSort(B,mid);  
    MergeSort(T,n-mid);  
    Merge(A,B,mid,T,n-mid);  
        free(B);
        free(T);
} 

//ordena por quicksort

void quicksort(int *target, int left, int right)
{
  if(left >= right){
    return;
  }
  int i = left, j = right;
  int tmp, pivot = target[i];
  for(;;) {
    while(target[i] < pivot){ 
      i++;
    }  
    while(pivot < target[j]){ 
      j--;
    }  
    if(i >= j){ 
      break;
    }  
    tmp = target[i]; target[i] = target[j]; target[j] = tmp;
    i++; j--;
  }
  quicksort(target, left, i-1);
  quicksort(target, j+1, right);
}

int main() {
    clock_t start, end;
    int k = NULL, *vet = NULL, a, b, inicio = 0, fim = k-1;
    printf("tamanho do vetor = ");
    scanf("%d", &k);  
    int i;
    vet = (int *)malloc(k * sizeof(int));

//gera valor aleatorio
printf("1 -> Vetor aleatório \n2 -> Vetor Decrescente \n3 -> Vetor Crescente \n");
scanf("%d", &a);
if (a==1){
for (int i = 0; i < k; i++)
{
    vet[i] = rand() % k + 1;

    printf("%i", vet[i]);
}
}

//vetor decrescente
if (a==2){
for (int i = 0; i < k; i++ ) {
        vet[ i ] = k - i;
        printf ( "%d ", vet[ i ] );
    }
  }

// vetor crescente
if (a==3){
for (int i = 0; i < k; i++ ) {
        vet[ i ] = i;
        printf ( "%d ", vet[ i ] );
    }
  }

printf("\n\n1 -> Ordenar por HeapSort \n2 -> Ordenar por MergeSort  \n3 -> Ordenar por QuickSort\n\n");
scanf("%d", &b);
if (b==1){  
  start = clock();
  HeapSort(vet, k);
  end = clock();
}
if (b==2){
  start = clock();
  MergeSort(vet, k);
  end = clock();
}
if (b==3){
  start = clock();
  quicksort(vet, 0, k-1);
  end = clock();
}

for (int i = 0; i < k; i++) {
    printf("%d ",vet[i]);
  }
  double difTempo = ((double) end - start)/CLOCKS_PER_SEC;
  printf("\n\n-> Clock before in seconds  = %lf", start);
  printf("\n-> Clock difference in seconds =  %lf", difTempo);
 
return 0;

}
  
