#include "String.h"			// 串类

int main(void) {
	cout << "输入要测试的字符串：" ;
	string t;
	char c = '9';
	cin >> t;
	String test(t);
//	cout << test.CStr();
	while (c != '0') {
		cout << endl << "1. 测试Insert()";
		cout << endl << "2. 测试Delete()";
		cout << endl << "3. 测试Copy()";
		cout << endl << "4. 测试关系运算符==";
		cout << endl << "5. 测试SubString()";
		cout << endl << "6. 测试下标运算符";
		cout << endl << "7. 测试连接运算符+=";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) 	{
			case '1': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << "输入插入字符串：";
				cin >> t;
				String ins(t);
				cout << endl << "输入插入位置：";
				int p;
				cin >> p;
				Insert(test, ins, p);
				cout << endl << "插入结果为：";
				cout << test << endl;
				cout << endl;
			}

			break;
			case '2': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << endl << "输入删除的起点位置和长度：";
				int p1, l1;
				cin >> p1 >> l1;
				Delete(test, p1, l1);
				cout << endl << "删除结果为：";
				cout << test << endl;
				cout << endl;
				break;
			}
			case '3': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << "字符串s2为：";
				String s2;
				cout << s2 << endl;
				Copy(s2, test);
				cout << endl << "复制结果为：";
				cout << s2 << endl;
				cout << endl;
				break;
			}
			case '4': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << "输入比较串s3：";
				cin >> t;
				String s3(t);
				if (test == s3)
					cout << "test和s3相等" << endl;
				else
					cout << "test和s3不相等" << endl;
				break;
			}
			case '5': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << endl << "输入子串的起点位置和长度：";
				int p2, l2;
				cin >> p2 >> l2;
				String s4;
				SubString(s4,test, p2, l2);
				cout << endl << "取子串结果为：";
				cout << s4 << endl;
				cout << endl;
				break;
			}
			case '6': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << endl << "输入字符下标：";
				int p3;
				cin >> p3;
				cout << endl << "测试下标运算符结果为：" << endl;
				cout << test[p3] << endl;
				break;
			}
			case '7': {
				cout << "测试字符串test为：";
				cout << test << endl;
				cout << "输入后接字符串：";
				cin >> t;
				String s5(t);
				cout << endl << "字符串连接结果为：";
				test += s5;
				cout << test << endl;
				cout << endl;
				break;
			}
		}
	}
	system("PAUSE");        // 调用库函数system()*/
	return 0;               // 返回值0, 返回操作系统
}
