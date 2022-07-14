#include <stdio.h>

typedef struct {
    char nome[50];
    int cavalos;
    float preco;
}carros;


int main(){
    int i;
    float filtro;
    carros dataCarros[5];

    printf ("Entre com os dados dos carros abaixo:\n\n");

    for(i=0;i<5;i++){
        printf("\nDigite o nome do carro %d:", i+1);
        fflush(stdin);
        scanf("%s", dataCarros[i].nome);

        printf("\nDigite a potencia do carro %d (CV):", i+1);
        fflush(stdin);
        scanf("%d", &dataCarros[i].cavalos);

        printf("\nDigite o preço do carro %d (BRL):", i+1);
        fflush(stdin);
        scanf("%f", &dataCarros[i].preco);
    }

    printf("\n\nExibir nome dos carros de valor até: ");
    scanf("%f", &filtro);

    for(i=0;i<5;i++){
        if(dataCarros[i].preco <= filtro){
            printf("\n");
            printf("%s:\t%.2f", dataCarros[i].nome, dataCarros[i].preco);
        }
    }
     printf("\n");
     return 0;
}
