#ifndef __STRING_H__
#define __STRING_H__
#include "Assistance.h"

class String 
{
public:                           
	String();
	~String();
	String(const String &s);
	String(const char *s);
	int GetLength() const;	 
	bool IsEmpty() const;
	String &operator =(const String &s);
	const char *CStr() const;
	char &operator [](int p) const;
	static void GetFailure(const String& pat,int f[]);
	static int KMP_find(const String& ob, const String& pat, int p = 0);

private:
	char* sVal;
	int length;
};

int String::KMP_find(const String& ob, const String& pat, int p)
{
	int* f = new int[pat.GetLength()];
	String::GetFailure(pat, f);
	int i = p, j = 0;
	while (i < ob.GetLength() && j < pat.GetLength() && pat.GetLength() - j <= ob.GetLength() - i)
	{
		if (j == -1 || pat[j] == ob[i])
		{
			i++; j++;
		}
		else
		{
			j = f[j];
		}
	}		
	delete[]f;
	if (j < pat.GetLength())
		return -1;
	else
		return i - j;
}
void String::GetFailure(const String& pat,int f[])
{
	int j = 0, k = -1;
	f[0] = -1;
	int l = pat.GetLength();
	while (j < l - 1)
	{
		if (k == -1 || pat[k] == pat[j])
		{
			f[++j] = ++k;
			if (pat[k] == pat[j]) f[j] = f[k];
		}
		else
		{
			k = f[k];
		}
	}
}
void Write(const String &s);
void Read(String &s);
void Copy(String &s1, const String &s2);
void Copyn(String &s1, const String &s2, int n);
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

String::String()
{
	length = 0;
	sVal = NULL;
}

String::~String()
{
	delete []sVal;
}

String::String(const String &s)
{
	length = strlen(s.CStr());
	sVal = new char[length + 1];
	strcpy(sVal, s.CStr());
}

String::String(const char *s)
{
	length = strlen(s);
	sVal = new char[length + 1];
	strcpy(sVal, s);
	sVal[length] = '\0';
}

int String::GetLength() const
{
	return length;
}

bool String::IsEmpty() const
{
	return length == 0;
}

String &String::operator =(const String &s)
{
	if (&s != this)  {
		delete []sVal;
		length = strlen(s.CStr());
		sVal = new char[length + 1];
		strcpy(sVal, s.CStr());
	}
	return *this;
}

const char *String::CStr() const
{
	return (const char *)sVal;
}

char &String::operator [](int p) const
{
	return sVal[p];
}

void Write(const String &str)
{
	cout << str.CStr() << endl;
}

void Read(String &str)
{
	string s;
	cin >> s;
	char *cs = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++)
		cs[i] = s[i];
	cs[s.length()] = '\0';
  	str = cs;
}

void Copy(String &s1, const String &s2)
{
	const char *cs2 = s2.CStr();
	char *cs1 = new char[strlen(cs2) + 1];
	strcpy(cs1, cs2);
	s1 = cs1;
//	delete []cs1;
}

void Copyn(String &s1, const String &s2, int n)
{
	const char *cs2 = s2.CStr();
	int len = strlen(cs2) < n ? strlen(cs2) : n;
	char *cs1 = new char[len + 1];
	strncpy(cs1, cs2, n);
	cs1[len] = '\0';
	s1 = cs1;
}

Status Insert(String &s1, const String &s2, int p)
{
	const char *cs1 = s1.CStr();
	const char *cs2 = s2.CStr();
	if (p >=0 && p < strlen(cs1)) {
 	    int len = strlen(cs1) + strlen(cs2);
        char *cs = new char[len + 1];
	    strncpy(cs, cs1, p);
		cs[p] = '\0';
		strcat(cs, cs2);
		int	 j = p + strlen(cs2);
		for (int i = p; i < strlen(cs1); i++, j++)
	        cs[j] = cs1[i];
  	    cs[len] = '\0';
  	    s1 = cs;
  	    return SUCCESS;
  	} 
  	return RANGE_ERROR;
}

Status Delete(String &s, int p, int n)
{
    const char *cs = s.CStr();
	if (p >=0 && (p + n) < strlen(cs)) {
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

String SubString(const String &s, int p, int n)
{
	if  (0 <= p && p + n < s.GetLength() && 0 <= n)	{
		char *sub = new char[n + 1];
		const char *strp = s.CStr();
		strncpy(sub, strp + p, n);
		sub[n] = '\0';
		String cs(sub);
		delete []sub;
		return cs;
	}
	else{
		String cs("");
		return cs;
	}
}

String operator +(const String &s1, const String &s2)
{
	const char *cs1 = s1.CStr();
	const char *cs2 = s2.CStr();
	char *cs = new char[strlen(cs1) + strlen(cs2) + 1];
	strcpy(cs, cs1);
	strcat(cs, cs2);
	String s(cs);
	delete []cs;
	return s;
}

bool operator ==(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const String &s1, const String &s2)
{
	return strcmp(s1.CStr(), s2.CStr()) != 0;
}

#endif

