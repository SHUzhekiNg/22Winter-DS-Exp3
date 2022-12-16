#include "String.h"
using namespace std;
int main()
{
	while (1)
	{
		cout << "请输入主字符串：";
		char *a = new char[100];
		cin >> a;
		cout << "请输入要匹配的模式串：";
		char *b = new char[100];
		cin >> b;
		String ob(a);
		String pat(b);
		if (a == NULL || b == NULL)
		{
			break;
		}
		int k = String::KMP_find(ob, pat);
		cout << k + 1 << endl;
	}
	
}