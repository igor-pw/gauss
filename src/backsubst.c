#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
<<<<<<< HEAD
double sum(Matrix *mat, Matrix* x, int i){
	double tmp = 0;
	
=======
int sum(Matrix *mat, Matrix* x, int i){
	int tmp = 0;
>>>>>>> c0199725d73d967955118d32c245b42b04681744
	for(int j = mat->c-1; j>=0; j--){
		if(j != i){
			tmp = tmp + (x->data[j][0]*mat->data[i][j]);
		}
	}
	
	return tmp;
}	

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	
	if(x->r == mat->r && b->r == mat->r && mat->c == mat->r){
	
		for(int i = x->r-1; i>=0; i--)
			x->data[i][0] = 0;

		for(int i = mat->c-1; i>=0; i--){
			if(mat->data[i][i] != 0){
				x->data[i][0]=(b->data[i][0] - sum(mat,x,i))/(mat->data[i][i]);
		
			}	
			else{
				return 1;
		
			}	
		}
	}

	else{
		return 2;
	}
	return 0;
}
