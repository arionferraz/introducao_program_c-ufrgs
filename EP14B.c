#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *f1, *f2;
    char fileName[50], L1, L2, temp[1000];

    printf("\nDigite o nome do arquivo que deseja abrir: ");
    gets(fileName);

    f1= fopen(fileName,"r");
    f2= fopen("teste.txt","w");
    if(f1 == NULL || f2 == NULL) {
        printf("Erro ao abrir o arquivo");
        system("pouse");
        exit(1);
    }
    rewind(f1);

    printf("\nDigite a letra que sera substituida: ");
    L1=getchar();
    printf("\nDigite a letra que devara substituir a letra anterior: ");
    while ((getchar()) != '\n');
    L2=getchar();

    while(fgets(temp, sizeof(temp), f1) != NULL) {

        int i;
        for(i=0;i<=sizeof(temp);i++){
            if(temp[i]==L1){
                temp[i]=L2;
            }
        }
        fputs(temp, f2);
    }

    fclose(f1);
    fclose(f2);

    system("pause");
    return 0;
}
