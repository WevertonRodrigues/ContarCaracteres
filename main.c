#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "contagem.h"


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int * listaTelefonica;
	int i, n = 0, v = 0; 
	
	printf("Digite a quantidade de números que serão inseridos na lista telefônica: ");
	scanf("%d", &n);
	
	listaTelefonica = (int *) malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++){
		printf("Digite o %dº número da lista: ", i+1);
		scanf("%d", listaTelefonica+i);
	}
	
	printf("\n\n%d caracteres serão reduzidos!\n\n\n", qtdCaracteresReduzidos(listaTelefonica, n, 0));
	
	free(listaTelefonica);
	system("pause");
	return 0;
}

