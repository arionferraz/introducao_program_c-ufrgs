#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define tamCinemas 5

//ESTRUTURA PARA ARMAZENAR OS DADOS DAS SESSÕES
typedef struct {
    int hora, exib3D;
    float preco;
    char idioma;
}sessao;

//ESTRUTURA PARA ARMAZENAR OS DADOS DE CADA CINEMA
typedef struct {
    char nome[50];
    sessao sessaoDisponivel[2]; //SERÃO ARMAZENADOS DADOS DE APENAS 2 SESSOES PARA CADA CINEMA
}cinema;

//FUNÇÃO AUXILIAR PARA LER OS DADOS DAS SESSÕES, RETORNA UMA ESTRUTURA DO TIPO SESSAO
sessao le_sessao (){
    sessao sessao_temp;

    printf("\n\tDigite o horario da sessao:");
    fflush(stdin);
    scanf("%d",&sessao_temp.hora);

    printf("\n\tDigite o valor da sessao:");
    fflush(stdin);
    scanf("%f",&sessao_temp.preco);

    printf("\n\tDigite o idioma da sessao (L: Legendado - D: Dublado):");
    fflush(stdin);
    scanf(" %c",&sessao_temp.idioma);

    printf("\n\tSera exibido em 3D? (1: Sim - 0: Nao):");
    fflush(stdin);
    scanf("%d",&sessao_temp.exib3D);
    return sessao_temp;
}

//FUNÇÃO PARA LER OS DADOS DOS CINEMAS, LE O NOME DO CINEMA E DADOS DE DUAS SESSÕES
cinema le_cinema (){
    cinema cinema_temp;

    printf("\nDigite o nome do cinema:");
    fflush(stdin);
    //gets(cinema_temp.nome);
    fgets(cinema_temp.nome, 50, stdin);
    printf("\nPrimeira sessao:");
    cinema_temp.sessaoDisponivel[0]=le_sessao();
    printf("\nSegunda sessao:");
    cinema_temp.sessaoDisponivel[1]=le_sessao();

    return cinema_temp;
}

//PROCEDIMENTO PARA OS DADOS DE UM VETOR DE SESSÕES
void imprime_sessoes(sessao vetor[], int tam){
    int j;
    for(j=0;j<tam;j++){
        printf("\n\nSessao %d.", j+1);
        printf("\n\t- Horario:   %d.", vetor[j].hora);
        printf("\n\t- Valor:     %.2f.", vetor[j].preco);
        printf("\n\t- Idioma:    %c.", vetor[j].idioma);
        printf("\n\t- 3D:        %d.", vetor[j].exib3D);
    }
}

int main(){

    cinema DoutorEstranho[tamCinemas];
    char conferir;
    int i;

    printf("\nChegando um dos doas mais esperados do ano... A telona nos aguarda! ;)\nInforme abaixo os dados das possiveis sessoes nas redondesas:");

    printf("\n\n======================================================\n");
    for(i=0;i<tamCinemas;i++){
        DoutorEstranho[i]=le_cinema();
        printf("\n======================================================\n");
    }

    printf("Deseja confir as informacoes? (s ou n)");
    scanf(" %c", &conferir);

    if(conferir=='s'){
        for(i=0;i<tamCinemas;i++){
                printf("\n\n=> %s", DoutorEstranho[i].nome);
                imprime_sessoes(DoutorEstranho[i].sessaoDisponivel,2);
        }
    }

    //#######################  ANÁLIZE DOS DADOS  #######################################################################################################

    sessao verificao[2]; //verificao[0]=sessão mais barata das 21h em diante - verificao[1]=sessão mais barata legendada
    int cont_3d=0, cont_2d=0, i_21, i_leg, j;
    float media_3d, media_2d, acumulador_2d=0, acumulador_3d=0, aux=1000, aux_leg=1000;

    for(i=0;i<tamCinemas;i++){
        for(j=0;j<2;j++){
            if(aux>DoutorEstranho[i].sessaoDisponivel[j].preco && DoutorEstranho[i].sessaoDisponivel[j].hora>=21){//sessão mais barata das 21h em diante
                aux=DoutorEstranho[i].sessaoDisponivel[j].preco;
                verificao[0]=DoutorEstranho[i].sessaoDisponivel[j];
                i_21=i;
            }
            if(aux_leg>DoutorEstranho[i].sessaoDisponivel[j].preco && DoutorEstranho[i].sessaoDisponivel[j].idioma=='L'){//sessão legendada mais barata
                aux_leg=DoutorEstranho[i].sessaoDisponivel[j].preco;
                verificao[1]=DoutorEstranho[i].sessaoDisponivel[j];
                i_leg=i;
            }
            if(DoutorEstranho[i].sessaoDisponivel[j].exib3D==1){//testa e conta se 3d
                cont_3d++;
                acumulador_3d+=DoutorEstranho[i].sessaoDisponivel[j].preco;
            }else{//testa e conta se 2d
                cont_2d++;
                acumulador_2d+=DoutorEstranho[i].sessaoDisponivel[j].preco;
            }
        }
    }

    media_3d=acumulador_3d/cont_3d;
    media_2d=acumulador_2d/cont_2d;

    printf("\n\n====================================================================\n\nRESUMO:");
    printf("\n\nA sessao mais barata apos as 21h eh:\n\n- %s", DoutorEstranho[i_21].nome);
    printf("\n\t- Horario:   %d.", verificao[0].hora);
    printf("\n\t- Valor:     %.2f.", verificao[0].preco);
    printf("\n\t- Idioma:    %c.", verificao[0].idioma);
    printf("\n\t- 3D:        %d.", verificao[0].exib3D);

    printf("\n\nA sessao legendada mais barata eh:\n\n- %s", DoutorEstranho[i_leg].nome);
    printf("\n\t- Horario:   %d.", verificao[1].hora);
    printf("\n\t- Valor:     %.2f.", verificao[1].preco);
    printf("\n\t- Idioma:    %c.", verificao[1].idioma);
    printf("\n\t- 3D:        %d.", verificao[1].exib3D);

    printf("\n\n\t- Media 2d:  %.2f.", media_2d);
    printf("\n\t- Media 3d:  %.2f.", media_3d);

    //#######################  GRAVA EM DISCO  “sessoes.txt”  #######################################################################################################

    printf("\n\nDeseja exportar um arquivo .txt com essas informacoes? (s ou n)");
    scanf(" %c", &conferir);

    if(conferir=='s'){
        FILE *f1;
        f1= fopen("sessoes.txt","w");
        if(f1 == NULL) {
            printf("Erro ao exportar para arquivo");
            system("pouse");
            exit(1);
        }
        rewind(f1);
        fprintf(f1,"-------SESSOES DOUTOR EXTRANHO-------\n");
        for(i=0;i<tamCinemas;i++){
            for(j=0;j<2;j++){
                fprintf(f1,"=====================================\n");
                fprintf(f1,"\n=> %s", DoutorEstranho[i].nome);
                fprintf(f1,"\n\nSessao %d.", j+1);
                fprintf(f1,"\n\t- Horario:   %d.", DoutorEstranho[i].sessaoDisponivel[j].hora);
                fprintf(f1,"\n\t- Valor:     %.2f.", DoutorEstranho[i].sessaoDisponivel[j].preco);
                fprintf(f1,"\n\t- Idioma:    %c.", DoutorEstranho[i].sessaoDisponivel[j].idioma);
                fprintf(f1,"\n\t- 3D:        %d.", DoutorEstranho[i].sessaoDisponivel[j].exib3D);
                fprintf(f1,"\n\n=====================================\n");
            }
        }
        fprintf(f1,"\nRESUMO:");
        fprintf(f1,"\n\nA sessao mais barata apos as 21h eh:\n\n- %s", DoutorEstranho[i_21].nome);
        fprintf(f1,"\n\t- Horario:   %d.", verificao[0].hora);
        fprintf(f1,"\n\t- Valor:     %.2f.", verificao[0].preco);
        fprintf(f1,"\n\t- Idioma:    %c.", verificao[0].idioma);
        fprintf(f1,"\n\t- 3D:        %d.", verificao[0].exib3D);
        fprintf(f1,"\n\nA sessao legendada mais barata eh:\n\n- %s", DoutorEstranho[i_leg].nome);
        fprintf(f1,"\n\t- Horario:   %d.", verificao[1].hora);
        fprintf(f1,"\n\t- Valor:     %.2f.", verificao[1].preco);
        fprintf(f1,"\n\t- Idioma:    %c.", verificao[1].idioma);
        fprintf(f1,"\n\t- 3D:        %d.", verificao[1].exib3D);
        fprintf(f1,"\n\n\t- Media 2d:  %.2f.", media_2d);
        fprintf(f1,"\n\t- Media 3d:  %.2f.", media_3d);
        fclose(f1);
    }

    system("pause");
    return 0;
}
