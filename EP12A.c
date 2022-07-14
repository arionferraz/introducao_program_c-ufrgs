#include<stdio.h>

void alteraVetor(int *vetor, int A, int B){
    int i;
    for(i=0;i<12;i++){
        if(*vetor==A)
            *vetor=B;
        vetor++;
    }
}

int main(){
    int i, vetor[12], A, B;

    printf("Digite os valores do vetor: \n");

    for(i=0;i<12;i++)
        scanf("%d", &vetor[i]);

    printf("\nDigite o valor de A: \n");
    scanf("%d", &A);
    printf("\nDigite o valor de B: \n");
    scanf("%d", &B);

    alteraVetor(vetor, A, B);

    printf("\nO vetor alterado eh: \n");
    for(i=0;i<12;i++){
        printf("%d\n", vetor[i]);
    }
    return 0;
}
