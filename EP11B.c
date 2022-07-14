#include <stdio.h>
#include <math.h>

int primo(int num){
    
	int veredito=0, i, aux, cont=0;
    
   	for(i=1;i<=num;i++){

        	aux=num%i;
        
        	if(aux==0)
            		cont++;
    	}

	if(cont==2)
		veredito=1;

	return(veredito);
}

int main(){

	int j, testePrimo;        

	printf("\n\nOs numeros primos de 0 a 1000 são:\n\n");

	for(j=2;j<=1000;j++){
	
		testePrimo = primo(j);
		
        	if(testePrimo==1)
			printf("%d, ", j);
    	}

    	return (0);
}
