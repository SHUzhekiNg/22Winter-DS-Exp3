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
	cout << "��������������������ģʽƥ���㷨���ԡ�������������������" << endl;
	while (1) {
		cout << "1.�ֶ���������" << endl;
		cout << "2.��ȡ�ļ�����" << endl;
		cout << "3.��������" << endl;
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
	cout << "����������" ;
	cin >> obj;
	cout << "����ģʽ����";
	cin >> pat;

	double start = omp_get_wtime();
	int a = BF_find(obj, pat, &cnt);
	double stop = omp_get_wtime();
	double time = (stop - start) * 1000;
	cout << "BFƥ���㷨���ؽ����" << a << endl;
	cout << "BFƥ���㷨��ʱ��" << time << "ms" << endl;
	cout << "BFƥ���㷨ģʽ���������Ƚϴ�����" << cnt << endl << endl;

	start = omp_get_wtime();
	a = KMP_find(obj, pat, &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "KMPƥ���㷨���ؽ����" << a << endl;
	cout << "KMPƥ���㷨��ʱ��" <<  time << "ms" << endl;
	cout << "KMPƥ���㷨ģʽ���������Ƚϴ�����" << cnt << endl << endl;

	start = omp_get_wtime();
	a = BM_find(obj.c_str(), pat.c_str(), &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "BMƥ���㷨���ؽ����"  << a << endl;
	cout << "BMƥ���㷨��ʱ��"  << time << "ms" << endl;
	cout << "BMƥ���㷨ģʽ���������Ƚϴ�����"<< cnt << endl << endl;
}

void test02() {
	fstream fs;
	fs.open("text01.txt", ios::in);
	if (!fs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	int cnt = 0;;
	string obj, pat;
	getline(fs,obj);
	getline(fs, pat);

	double start = omp_get_wtime();
	int a = BF_find(obj, pat, &cnt);
	double stop = omp_get_wtime();
	double time = (stop - start) * 1000;
	cout << "BFƥ���㷨���ؽ����" << a << endl;
	cout << "BFƥ���㷨��ʱ��"  << time << "ms" << endl;
	cout << "BFƥ���㷨ģʽ���������Ƚϴ�����"  << cnt << endl << endl;

	start = omp_get_wtime();
	a = KMP_find(obj, pat, &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "KMPƥ���㷨���ؽ����" << a << endl;
	cout << "KMPƥ���㷨��ʱ��"  << time << "ms" << endl;
	cout << "KMPƥ���㷨ģʽ���������Ƚϴ�����"  << cnt << endl << endl;

	start = omp_get_wtime();
	a = BM_find(obj.c_str(), pat.c_str(), &cnt);
	stop = omp_get_wtime();
	time = (stop - start) * 1000;
	cout << "BMƥ���㷨���ؽ����"  << a << endl;
	cout << "BMƥ���㷨��ʱ��"  << time << "ms" << endl;
	cout << "BMƥ���㷨ģʽ���������Ƚϴ�����" << cnt << endl << endl;
	fs.close();
}