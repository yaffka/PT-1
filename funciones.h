struct entrada {
	char    el[2];
	double  x;
	double  y;
	double  z;
} ;

void centromasa(int j, int na,struct entrada *molA);
void tensor( int na, struct entrada *molA, double A[3][3]);
void diagonal(double A[3][3]);


