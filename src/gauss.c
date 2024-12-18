#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	for(int i = 0; i < mat->c; i++)
	{
		for(int j = i+1; j < mat->r; j++)
		{
			if(mat->data[i][i] == 0)
				return 1;
			
			double value = mat->data[j][i]/mat->data[i][i];

			for(int k = 0; k < mat->c; k++)
			{
				mat->data[j][k] -= mat->data[i][k]*value;
			}

			b->data[j][0] -= b->data[i][0]*value;

		}
		
	}	

		return 0;
}


