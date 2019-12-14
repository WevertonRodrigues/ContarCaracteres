#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "contagem.h"


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int * listaTelefonica;
	int i, n = 0, v = 0; 
	
	printf("Digite a quantidade de n�meros que ser�o inseridos na lista telef�nica: ");
	scanf("%d", &n);
	
	listaTelefonica = (int *) malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++){
		printf("Digite o %d� n�mero da lista: ", i+1);
		scanf("%d", listaTelefonica+i);
	}
	
	printf("\n\n%d caracteres ser�o reduzidos!\n\n\n", qtdCaracteresReduzidos(listaTelefonica, n, 0));
	
	free(listaTelefonica);
	system("pause");
	return 0;
}

