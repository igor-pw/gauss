#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);
	
	printf("\n\n");

	res = eliminate(A,b);

	printToScreen(A);

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		printf("\n");
		switch(res){
			case 0:
				printToScreen(x);
				freeMatrix(x);
				break;
			case 1:
				printf("Błąd - prubowano podzielić przez 0 !\n");
				break;
			case 2:
				printf("Błąd - niepoprawne wymiary macierzy !\n");
				break;
		}	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
