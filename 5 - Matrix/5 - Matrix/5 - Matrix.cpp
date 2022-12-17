#include <iostream>
using namespace std;


bool Check(int *rs, int *cs, int r, int c, int *er, int *ec) {
	bool iscorrect = true;
	for (int i = 0; i < r; i++) {
		if (rs[i] % 2 != 0) {
			iscorrect = false;
		} else {
			(*er)++;
		}
	}
	for (int i = 0; i < c; i++) {
		if (cs[i] % 2 != 0) {
			iscorrect = false;
		} else {
			(*ec)++;
		}
	}
	return iscorrect;
}

int main() {
	int row, col,t, evenr = 0, evenc = 0;
	cout << "输入矩阵行数和列数：";
	cin >> row >> col;
	//bool matrix[row][col];
	int *rowsum = new int[row]();
	int *colsum = new int[col]();
//	for (int i = 0; i < row; i++) rowsum[i] = 0;
//	for (int i = 0; i < col; i++) colsum[i] = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> t;
			//matrix[i][j] = t;
			rowsum[i] += t;
			colsum[j] += t;
		}
	}
	if (Check(rowsum, colsum, row, col, &evenr, &evenc)) {
		cout << "OK" << endl;
		return 0;
	} else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int temper = evenr,tempec = evenc;
				if (rowsum[i] % 2 == 0) evenr--;
				else evenr++;
				if(colsum[j] % 2 == 0) evenc--;
				else evenc++;
				
				if(evenr==row && evenc==col) {
					cout << "Change("<<i<<','<<j<<')'<<endl;
					return 0;
				}
				evenr = temper;
				evenc = tempec;
			}
		}
	}
	cout << "Corrupt" << endl;
	return 0;
}
