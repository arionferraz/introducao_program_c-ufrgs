#include <stdio.h>

int main() {
    FILE *fp;
    char fileName[50], temp[1024];
    int line=1;

    printf("\nDigite o nome do arquivo que deseja abrir: ");
    gets(fileName);
    printf("\nEntrada: %s\n", fileName);

    fp= fopen(fileName,"r");
    if(fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!");
        return 1;
    }
    rewind(fp);

    printf("\n\n");
    while(fgets(temp, sizeof(temp), fp) != NULL) {
        printf("%d\t>>\t%s", line, temp);
        line++;
    }
    printf("\n\n");

    fclose(fp);
    system("pause");
    return 0;
}
