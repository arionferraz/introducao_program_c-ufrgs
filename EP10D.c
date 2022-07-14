#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(){
    
    int num;
    num=rand() %6 + 1;

    return(num);
}

int main(){

    int i, j, cont[6]={0,0,0,0,0,0}, gerado;
    float percent;

    for(i=0; i<1000;i++){

        gerado=dado();

        if(gerado==1){
            cont[0]=cont[0]+1;
        }else if(gerado==2){
            cont[1]=cont[1]+1;
        }else if(gerado==3){
            cont[2]=cont[2]+1;
        }else if(gerado==4){
            cont[3]=cont[3]+1;
        }else if(gerado==5){
            cont[4]=cont[4]+1;
        }else if(gerado==6){
            cont[5]=cont[5]+1;
        }
    }

    printf("\n\nO dado foi lançado 1000 vezes. os resultados foram distribuidos da seguinte forma:\n\n");

    for(i=0; i<6;i++){

        percent=((float)cont[i]/1000)*100;

        printf("\nLado %d: %.2f%%. \n ", i+1, percent);

    }
              
    return (0);
}
