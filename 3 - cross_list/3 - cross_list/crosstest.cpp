#include "CrossList.h"
using namespace std;
int main()
{
	const int rs = 7, cs = 6;
	CrossList<int> a(rs, cs);
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
	cout << "¾ØÕóa:" << endl;
	for (i = 0; i < a.GetRows(); i++) {
		for (j = 0; j < a.GetCols(); j++) {
			a.GetElem(i, j, v);
			cout << v << "\t";
		}
		cout << endl;
	}
	a.Transpose();
	cout << "¾ØÕóa:" << endl;
	for (i = 0; i < a.GetRows(); i++) {
		for (j = 0; j < a.GetCols(); j++) {
			a.GetElem(i, j, v);
			cout << v << "\t";
		}
		cout << endl;
	}
}