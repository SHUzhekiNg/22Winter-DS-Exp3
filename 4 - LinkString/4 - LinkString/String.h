#ifndef __STRING_H__
#define __STRING_H__
#include "Assistance.h"
#include "Node.h"
#include<iostream>

using namespace std;

class String {
	private:
		Node *head;
		Node *rear;
		int length;
		friend ostream& operator<<(ostream &out, String &s);
	public:
		String();
		~String();
		String(const String &s);
		String(const char *s);
		String(string &s);
		int GetLength() const;
		bool IsEmpty() const;
		String& operator=(const String &s);
		String& operator=(const char *s);
		String& operator+=(const String &s);
		const char *CStr() const;
		char &operator [](int p) const;
};


void Copy(String &s1, const String &s2);

void Copy(String &s1, const String &s2, int n);

Status Insert(String &s1, const String &s2, int p);

Status Delete(String &s, int p, int n);

String SubString(const String &s, int p, int n);

String operator +(const String &s1, const String &s2);

bool operator ==(const String &s1, const String &s2);

bool operator <(const String &s1, const String &s2);

bool operator >(const String &s1, const String &s2);

bool operator <=(const String &s1, const String &s2);

bool operator >=(const String &s1, const String &s2);

bool operator !=(const String &s1, const String &s2);


// 串类及相关操作的实现部分
String::String() {
	head = new Node;
	rear = NULL;
	length = 0;
}

String::~String() {
	if (head->next == NULL)
		delete head;
	else {
		Node *p = head->next;
		while (head->next != NULL) {
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
	}
}

String::String(const String &s) {
	head = new Node;
	rear = head;
	length = 0;
	Node *p = s.head->next;
	for (int i = 0; p != NULL; i++) {
		int len = p->Nodelen;
		rear->next = new Node;
		rear = rear->next;
		for (int j = 0; j < len; j++) rear->data[i] = p->data[i];
		rear->Nodelen = len;
		rear->next = NULL;
		p = p->next;
		length += len;
	}
}

String::String(const char *s) {
	head = new Node;
	rear = head;
	length = 0;
	int strlength = strlen(s);
	while (length < strlength) {
		rear->next = new Node;
		rear = rear->next;
		int i = 0;
		while (i < 4 && length < strlength) {
			rear->data[i++] = s[length++];
		}
		rear->next = NULL;
		rear->Nodelen = i;
	}
}

String::String(string &s) {
	head = new Node;
	rear = head;
	length = 0;
	int strlength = s.size();
	while (length < strlength) {
		rear->next = new Node;
		rear = rear->next;
		int i = 0;
		while (i < 4 && length < strlength) {
			rear->data[i++] = s[length++];
		}
		rear->next = NULL;
		rear->Nodelen = i;
	}
}

int String::GetLength() const {
	return length;
}

bool String::IsEmpty() const {
	return length == 0;
}

String &String::operator=(const char *s) {
	head = new Node;
	rear = head;
	length = 0;
	int strlength = strlen(s);
	while (length < strlength) {
		rear->next = new Node;
		rear = rear->next;
		int i = 0;
		while (i < 4 && length < strlength) {
			rear->data[i++] = s[length++];
		}
		rear->next = NULL;
		rear->Nodelen = i;
	}
	return *this;
}

String &String::operator=(const String &s) {
	this->~String();
	head = new Node;
	rear = head;
	length = 0;
	Node *p = s.head->next;
	for (int i = 0; p != NULL; i++) {
		int len = p->Nodelen;
		rear->next = new Node;
		rear = rear->next;
		for (int j = 0; j < len; j++) rear->data[i] = p->data[i];
		rear->Nodelen = len;
		rear->next = NULL;
		p = p->next;
		length += len;
	}
	return *this;
}


char &String::operator[](int p) const {
	Node *q = head->next;
	int x = p / 4;
	for (int i = 0; i < x; i++) {
		q = q->next;
	}
	if (p % 4 == 0)
		return q->data[3];
	else {
		return q->data[p % 4 - 1];
	}
}

String& String::operator+=(const String &s) {
	const char *cs1 = this->CStr();
	const char *cs2 = s.CStr();
	char *cs = new char[length + s.length + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	(*this) = cs;
	return *this;
}

const char* String::CStr() const {
	char *cstr = new char[length + 1];
	Node *p = head->next;
	int i = 0;
	while (p) {
		for (int j = 0; j < p->Nodelen; j++) cstr[i++] = p->data[j];
		p = p->next;
	}
	cstr[length] = '\0';
	return cstr;
}

void Copy(String &s1, const String &s2) {
	const char *cs2 = s2.CStr();
	char *cs1 = new char[strlen(cs2) + 1];
	strcpy(cs1, cs2);
	s1 = cs1;
	delete []cs1;
}

void Copyn(String &s1, const String &s2, int n) {
	const char *cs2 = s2.CStr();
	int s2len = strlen(cs2);
	int len = s2len < n ? s2len : n;
	char *cs1 = new char[len + 1];
	strncpy(cs1, cs2, n);
	cs1[len] = '\0';
	s1 = cs1;
}

Status Insert(String &s1, String &s2, int p) {
	const char *cs1 = s1.CStr();
	const char *cs2 = s2.CStr();
	int s1len = strlen(cs1);
	if (p >= 0 && p < s1len) {
		int len = strlen(cs1) + strlen(cs2);
		char *cs = new char[len + 1];
		strncpy(cs, cs1, p);
		cs[p] = '\0';
		strcat(cs, cs2);
		int	 j = p + strlen(cs2);
		for (int i = p; i < s1len; i++, j++)
			cs[j] = cs1[i];
		cs[len] = '\0';
		//for(int i=0;i<len;i++) cout << cs[i];
		//cout << endl;
		s1 = cs;
		return SUCCESS;
	}
	return RANGE_ERROR;
}

Status Delete(String &s, int p, int n) {
	const char *cs = s.CStr();
	int cslen = strlen(cs);
	if (p >= 0 && (p + n) < cslen) {
		int len = strlen(cs) - n;
		char *news = new char[len + 1];
		strncpy(news, cs, p);
		int	 j = p + n;
		for (int i = p; i < len; i++, j++)
			news[i] = cs[j];
		news[len] = '\0';
		s = news;
		delete []news;
		return SUCCESS;
	}
	return RANGE_ERROR;
}

Status SubString(String &dest, const String &s, int p, int n) {
	if  (p >= 0 && p + n < s.GetLength() && n >= 0)	{
		char *sub = new char[n + 1];
		const char *strp = s.CStr();
		strncpy(sub, strp + p, n);
		sub[n] = '\0';
		//for(int i=0;i<n;i++) cout << sub[i];
		//cout << endl;
		dest = sub;
		delete []sub;
		return SUCCESS;
	} else	{
		return RANGE_ERROR;
	}
}

String operator +(const String &s1, const String &s2) {
	const char *cs1 = s1.CStr();
	const char *cs2 = s2.CStr();
	char *cs = new char[strlen(cs1) + strlen(cs2) + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	static String s = cs;
	delete []cs;
	//cout << s << endl;
	return s;
}

bool operator ==(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const String &s1, const String &s2) {
	return strcmp(s1.CStr(), s2.CStr()) != 0;
}



ostream& operator<<(ostream &out, String &s) {
	cout << '\"';
	Node *p = s.head->next;
	while (p) {
		for (int i = 0; i < p->Nodelen; i++) cout << p->data[i];
		p = p->next;
	}
	cout << '\"';
	return out;
}
#endif
