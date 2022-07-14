#include <stdio.h>

typedef struct {
    char titulo[20];
    char autor[20];
    char estilo[10];
    int cod;
    float preco;
}livros;

livros leLivros(){

    livros temp;

    printf("Digite o título: ");
    fflush(stdin);
    scanf("%s", temp.titulo);

    printf("Digite o autor: ");
    fflush(stdin);
    scanf("%s", temp.autor);

    printf("Digite o estilo: ");
    fflush(stdin);
    scanf("%s", temp.estilo);

    printf("Digite o codigo: ");
    scanf("%d", &temp.cod);

    printf("Digite o preço: ");
    scanf("%f", &temp.preco);

    return temp;
}

void printaLivros(livros temp[3]){
    int i;
    for(i=0;i<3;i++){
        printf("\nLivro %d:\n\n",i+1);
        printf("Título:\t%s\n",temp[i].titulo);
        printf("Autor:\t%s\n", temp[i].autor);
        printf("Estilo:\t%s\n", temp[i].estilo);
        printf("Codigo:\t%d\n", temp[i].cod);
        printf("Preço:\t%.2f\n", temp[i].preco);
    }
}

int main(){
    int i;
    livros lista[3];

    printf ("Entre com os dados dos livros abaixo:\n");

    for(i=0;i<3;i++){
        printf("\nLivro %d:\n\n",i+1);
        lista[i]=leLivros();
    }

    printf ("\nConfira abaixo os livros cadastrados:\n");
    printaLivros(lista);

    return 0;
}
