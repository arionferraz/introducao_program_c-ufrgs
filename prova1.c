#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	char nometime1[31], nometime2[31];
    int pts[2][4], i, j, menorQuartoA=0, menorQuartoB=0, menorPtA=60, menorPtB=60, placarA=0, placarB=0;

//==================================================
//Le nomes de times   

    printf("\nDigite o nome do primeiro time: \n\n");
    gets(nometime1);

    printf("\nDigite o nome do segundo time: \n\n");
    gets(nometime2);

//==================================================
//Recebe e armazena/atribui pontuações

    printf("\nDigite a pontuaçao do primeiro time: \n");
    srand(time(NULL));
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            if(i==0){
                do{
                    printf("\nQuarto %d: ", j+1);
                    scanf("%d", &pts[i][j]);
                }while (pts[i][j]<0 || pts[i][j]>50);               
            }else{
                pts[i][j]= rand() %50 + 1;
            }
        }
    }
//==================================================
//Seleciona periodo de menor pontuação

    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            if(i==0){
                if(menorPtA>pts[i][j]){
                    menorQuartoA=j+1;
                    menorPtA=pts[i][j];
                }               
            }else {
                if(menorPtB>pts[i][j]){
                    menorQuartoB=j+1;
                    menorPtB=pts[i][j];
                }   
            }
        }
    }

//==================================================
//Calcula Placares

    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            if(i==0){
                placarA=placarA+pts[i][j];              
            }else{
                placarB=placarB+pts[i][j]; 
            }
        }
    }
    
//==================================================
//Imprime matriz de pontuação e periodo de menor pontuação

    for(i=0;i<2;i++){
        if (i==0){
            printf("\nPontuação time %s:\n\n\tQuarto 1: %d\n\tQuarto 2: %d\n\tQuarto 3: %d\n\tQuarto 4: %d\n\tSua menor pontuação foi %d e se deu no quarto %d", nometime1, pts[i][0], pts[i][1], pts[i][2], pts[i][3], menorPtA, menorQuartoA);
        }else{
            printf("\n\nPontuação time %s:\n\n\tQuarto 1: %d\n\tQuarto 2: %d\n\tQuarto 3: %d\n\tQuarto 4: %d\n\tSua menor pontuação foi %d e se deu no quarto %d", nometime2, pts[i][0], pts[i][1], pts[i][2], pts[i][3], menorPtB, menorQuartoB);
        }
    }

//==================================================
//Imprime placar final e vencedor

    printf("\n\nO placar final de %s x %s eh respectivamente: \n\n\t %d x %d ", nometime1, nometime2, placarA, placarB);
    if(placarA>placarB){
        printf("\n\nO Vencedor eh %s!", nometime1);
    }else if(placarA<placarB){
        printf("\n\nO Vencedor eh %s!", nometime2);
    }else{
        printf("\n\nHouve empate!");
    }
    
    return 0;
}
