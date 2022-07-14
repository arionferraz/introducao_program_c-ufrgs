#include <stdio.h>

int main (){
	
	int num=4, tentativa;
	
	do {
		
		printf("Tente adivinhar o numero da sorte entre 1 e 10!\n");
		scanf("%d", &tentativa);
		
		if(tentativa > num)
			printf("Errooooooou... Tente um numero menor!!\n");
		else if (tentativa < num)
			printf("Errooooooou... Tente um numero maior!!\n");
			
	}while (tentativa != num);
	
	printf("Parabens, voce acertou!\n");
	
	return (0);
	
}