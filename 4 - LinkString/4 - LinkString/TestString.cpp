#include "String.h"			// ����

int main(void) {
	cout << "����Ҫ���Ե��ַ�����" ;
	string t;
	char c = '9';
	cin >> t;
	String test(t);
//	cout << test.CStr();
	while (c != '0') {
		cout << endl << "1. ����Insert()";
		cout << endl << "2. ����Delete()";
		cout << endl << "3. ����Copy()";
		cout << endl << "4. ���Թ�ϵ�����==";
		cout << endl << "5. ����SubString()";
		cout << endl << "6. �����±������";
		cout << endl << "7. �������������+=";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~9):";
		cin >> c;
		switch (c) 	{
			case '1': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << "��������ַ�����";
				cin >> t;
				String ins(t);
				cout << endl << "�������λ�ã�";
				int p;
				cin >> p;
				Insert(test, ins, p);
				cout << endl << "������Ϊ��";
				cout << test << endl;
				cout << endl;
			}

			break;
			case '2': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << endl << "����ɾ�������λ�úͳ��ȣ�";
				int p1, l1;
				cin >> p1 >> l1;
				Delete(test, p1, l1);
				cout << endl << "ɾ�����Ϊ��";
				cout << test << endl;
				cout << endl;
				break;
			}
			case '3': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << "�ַ���s2Ϊ��";
				String s2;
				cout << s2 << endl;
				Copy(s2, test);
				cout << endl << "���ƽ��Ϊ��";
				cout << s2 << endl;
				cout << endl;
				break;
			}
			case '4': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << "����Ƚϴ�s3��";
				cin >> t;
				String s3(t);
				if (test == s3)
					cout << "test��s3���" << endl;
				else
					cout << "test��s3�����" << endl;
				break;
			}
			case '5': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << endl << "�����Ӵ������λ�úͳ��ȣ�";
				int p2, l2;
				cin >> p2 >> l2;
				String s4;
				SubString(s4,test, p2, l2);
				cout << endl << "ȡ�Ӵ����Ϊ��";
				cout << s4 << endl;
				cout << endl;
				break;
			}
			case '6': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << endl << "�����ַ��±꣺";
				int p3;
				cin >> p3;
				cout << endl << "�����±���������Ϊ��" << endl;
				cout << test[p3] << endl;
				break;
			}
			case '7': {
				cout << "�����ַ���testΪ��";
				cout << test << endl;
				cout << "�������ַ�����";
				cin >> t;
				String s5(t);
				cout << endl << "�ַ������ӽ��Ϊ��";
				test += s5;
				cout << test << endl;
				cout << endl;
				break;
			}
		}
	}
	system("PAUSE");        // ���ÿ⺯��system()*/
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
