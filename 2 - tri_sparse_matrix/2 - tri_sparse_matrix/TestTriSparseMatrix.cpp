#include "TriSparseMatrix.h"

int main(void)
{
	const int rs = 7, cs = 6;
	TriSparseMatrix<int> a(rs, cs);
	int m[rs][cs] = {
		15,	 0,	 0,	22,	 0, -5, 
			0,	11,	 3,	 0,	 0,  0, 
			0,	 0,	 0,	 6,	 0,  0,
			0,	 0,	 0,	 0,	 0,  0,
		91,	 0,	 0,	 0,	 0,  0,
            0,  7,  0,  0,  0,  0,
            0,  0, 28,  0,  0,  0
	};
	int i, j, v;

	for (i = 0; i < rs; i++) 
		for (j = 0; j < cs; j++)
			a.SetElem(i, j, m[i][j]);
	a = a;

	cout << "¾ØÕóa:" << endl;
	for (i = 0; i < a.GetRows(); i++)	{	
		for (j = 0; j < a.GetCols(); j++)	{	
			a.GetElem(i, j, v);
			cout << v << "\t";
		}
		cout << endl;
	}
		
	TriSparseMatrix<int> c(rs, cs);
	int n[rs][cs] = {
		15,	 0,	 0,	22,	 0, 5,
			0,	11,	 3,	 0,	 0,  0,
			0,	 6,	 0,	 6,	 0,  0,
			0,	 0,	 0,	 3,	 0,  0,
		-91, 0,	 0,	 0,	 0,  0,
			0,  2,  0,  4,  0,  0,
			0,  0, 2,  0,  0,  0
	};


	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			c.SetElem(i, j, n[i][j]);


	cout << endl << "¾ØÕóc:" << endl;
	for (i = 0; i < c.GetRows(); i++) {
		for (j = 0; j < c.GetCols(); j++) {
			c.GetElem(i, j, v);	
			cout << v << "\t";
		}
		cout << endl;
	}
	TriSparseMatrix<int> d = c + a;
	cout << endl << "¾ØÕód=c+a:" << endl;
	for (i = 0; i < d.GetRows(); i++) {
		for (j = 0; j < d.GetCols(); j++) {
			d.GetElem(i, j, v);
			cout << v << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


