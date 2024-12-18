#include <stdlib.h>
#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	for(int i = 0; i < mat->c; i++)
	{
		ReplaceRows(mat, b, i, i);
		
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

void ReplaceRows(Matrix *mat, Matrix *b, int col, int row)
{
        double max = abs(mat->data[row][col]);
        int index;

        for(int i = row; i < mat->r; i++)
        {
                if(max < abs(mat->data[i][col]))
                {
                        max = abs(mat->data[i][col]);
                        index = i;
                }
        }

        if(max != abs(mat->data[row][col]))
        {
                double temp;

                for(int i = 0; i < mat->c; i++)
                {
                        temp = mat->data[row][i];
                        mat->data[row][i] = mat->data[index][i];
                        mat->data[index][i] = temp;
                }

                temp = b->data[row][0];
                b->data[row][0] = b->data[index][0];
                b->data[index][0] = temp;

        }
}

