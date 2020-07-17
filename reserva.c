#include <stdio.h>
#include <stdlib.h>

int main()
{
	double *energia;
	double *A;
	int size_1D,size1_2D,size2_2D;

	printf("Insert array size (1D): ");
	scanf("%d",&size_1D);

	printf("Insert first dimension size (2D): ");
	scanf("%d",&size1_2D);
	printf("Insert first dimension size (2D): ");
	scanf("%d",&size2_2D);

	energia = (double *) malloc(size_1D * sizeof(double));
	
	A = (double *) malloc(size1_2D * size2_2D * sizeof(double));

	energia[size_1D-1]=500.500;
	A[size1_2D-1][size2_2D-1]=33.33;

	if(energia)
	{
		printf("apoco si\n");
		printf("%lf\n",energia[size_1D-1]);
	}	
	else
	{
		printf("acaray\n");
	}
	

	printf("%lf\n",A[size1_2D-1][size2_2D-1]);

	free(energia);
	free(A);

	return 0;
}
