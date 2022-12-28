#include<iostream>
#include<fstream>
#include<string>
#include<omp.h>
using namespace std;

int BF_find(string &obj, string &pat, int* cnt);
int* GetNextVal(string &pat);
int KMP_find(string &obj, string &pat, int* cnt);
int BM_find(const char *obj, const char *pat, int *cnt);
int BM_find(const char *obj, const char *pat);
void test01();
void test02();

int main() {
	cout << "——————————模式匹配算法测试——————————" << endl;
	while (1) {
		cout << "1.手动输入样例" << endl;
		cout << "2.读取文件样例" << endl;
		cout << "3.结束测试" << endl;
		int order;
		cin >> order;
		if (order == 1) {
			test01();
		} else if (order == 2) {
			test02();
		} else {
			break;
		}
	}
	return 0;
}

void test01() {
	string obj, pat;
	int cnt;
	cout << "输入主串：" ;
	cin >> obj;
	cout << "输入模式串：";
	cin >> pat;

	double start = omp_get_wtime();
	int a = BF_find(obj, pat, &cnt);
	double stop = omp_get_wtime();
	double time = (stop - start) * 1000;
	cout << "BF匹配算法返回结果：" << a << endl;
	cout << "BF匹配算法用时：" << time << "ms" << endl;
	cout << "BF匹配算法模式串与主串比较次数：" << cnt << endl << endl;

	start = omp_get_wtime();
	a = KMP_find(obj, pat, &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "KMP匹配算法返回结果：" << a << endl;
	cout << "KMP匹配算法用时：" <<  time << "ms" << endl;
	cout << "KMP匹配算法模式串与主串比较次数：" << cnt << endl << endl;

	start = omp_get_wtime();
	a = BM_find(obj.c_str(), pat.c_str(), &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "BM匹配算法返回结果："  << a << endl;
	cout << "BM匹配算法用时："  << time << "ms" << endl;
	cout << "BM匹配算法模式串与主串比较次数："<< cnt << endl << endl;
}

void test02() {
	fstream fs;
	fs.open("text01.txt", ios::in);
	if (!fs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	int cnt = 0;;
	string obj, pat;
	getline(fs,obj);
	getline(fs, pat);

	double start = omp_get_wtime();
	int a = BF_find(obj, pat, &cnt);
	double stop = omp_get_wtime();
	double time = (stop - start) * 1000;
	cout << "BF匹配算法返回结果：" << a << endl;
	cout << "BF匹配算法用时："  << time << "ms" << endl;
	cout << "BF匹配算法模式串与主串比较次数："  << cnt << endl << endl;

	start = omp_get_wtime();
	a = KMP_find(obj, pat, &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "KMP匹配算法返回结果：" << a << endl;
	cout << "KMP匹配算法用时："  << time << "ms" << endl;
	cout << "KMP匹配算法模式串与主串比较次数："  << cnt << endl << endl;

	start = omp_get_wtime();
	a = BM_find(obj.c_str(), pat.c_str(), &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "BM匹配算法返回结果："  << a << endl;
	cout << "BM匹配算法用时："  << time << "ms" << endl;
	cout << "BM匹配算法模式串与主串比较次数：" << cnt << endl << endl;
	fs.close();
}