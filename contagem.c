#include <stdio.h>
#include <stdlib.h>
#include "contagem.h"

int contagemDig(int num){
	int i = 0;
	while(num > 0){
		num /= 10;
		i++;
	}
	return i;
}

int * transformarNumero(int * lista, int pos){
	int i, aux, num = *(lista + pos), qtd = contagemDig(num), * vet = (int *) malloc(sizeof(int *) * qtd);
		
	for(i = 0; i < qtd; i < i++){
		*(vet+i) = num%10;
		num = num / 10;
	}
	
	for (i = 0; i <  qtd / 2; i++) {
        aux = *(vet + i);
        *(vet + i) = *(vet + qtd - 1 - i);
        *(vet + qtd - 1 - i) = aux;
    }
	
	return vet;
}

int qtdCaracteresReduzidos(int * lista, int tam, int posBase){
	int i, j, total = 0, posCmp = posBase+1, pos2 = posCmp+1, * telBase = transformarNumero(lista, posBase), * telCmp = transformarNumero(lista, posCmp), * telPosCmp = transformarNumero(lista, pos2);
	
	for(i = 1; i < tam; i++){
		for(j = 0; j < contagemDig(*(lista + posBase)); j++){
			if(*(telBase+j) == *(telCmp+j))
				total++;
			else
				break;
		}
		if(*(telPosCmp) != *(telBase))
			break;
		else{
			if(posCmp < tam - 1){
				posCmp++;
				free(telCmp);
				telCmp = telPosCmp;
				telPosCmp = transformarNumero(lista, posCmp+1);
				pos2++;
			}
		}
	}

	free(telBase);
	free(telCmp);	
	free(telPosCmp);
	
	if(posCmp == tam - 1)
		return total;
	
	if(posCmp != tam - 1){
		total += qtdCaracteresReduzidos(lista, tam, pos2);
	}
	
	return total;	
}
