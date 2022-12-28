#include<iostream>
#include<string.h>
using namespace std;

int BF_find(string &obj, string &pat, int* cnt) {
	int objlen = obj.size(), patlen = pat.size();
	(*cnt) = 0;
	for (int i = 0; i <= objlen - patlen; i++) {
		for (int j = 0; j < patlen && i + j < objlen; j++) {
			if (pat[j] != obj[i + j]) {
				(*cnt)++;
				break;
			} else if (pat[j] == obj[i + j] && j == patlen - 1) {
				(*cnt)++;
				return i;
			}
			(*cnt)++;
		}
	}
	return -1;
}

int* GetNextVal(string &pat) {
	int patlen = pat.size(), i = 0, j = -1;
	int* nextval = new int[patlen];
	nextval[i] = j;
	while (i < patlen - 1) {
		if (j == -1 || pat[i] == pat[j]) {
			nextval[++i] = ++j;
			if (pat[i] == pat[nextval[i]]) nextval[i] = nextval[nextval[i]];
		} else {
			j = nextval[j];
		}
	}
	return nextval;
}

int KMP_find(string &obj, string &pat, int* cnt) {
	int i = 0, j = 0, objlen = obj.size(), patlen = pat.size();
	(*cnt) = 0;
	int* nextval = GetNextVal(pat);
	while (i < objlen && j < patlen) {
		if (obj[i] == pat[j]) {
			i++;
			j++;
			(*cnt)++;
			if (j == patlen && i <= objlen) return i - patlen;
		} else {
			if (nextval[j] == -1) {
				i++;
				j = 0;
			} else {
				j = nextval[j];
			}
			(*cnt)++;
		}
	}
	return -1;
}

int BM_find(const char *obj, const char *pat) {
	int objlen = strlen(obj), patlen = strlen(pat);
	int i = 0, j, k;
	while (i <= objlen - patlen) {
		for (j = patlen - 1; j >= 0; j--) {
			if (pat[j] != obj[i + j]) {
				break;
			}
		}
		if (j == -1) return i;
		if (j == patlen - 1) {
			while (j >= 0) {
				if (obj[i + patlen - 1] == pat[j]) {
					break;
				}
				j--;
			}
			i += (patlen - 1 - j);
			continue;
		}
		int temp = BM_find(pat, pat + j + 1);
		k = temp == (j + 1) ? -1 : temp;
		i += (j - k + 1);
	}
	return -1;
}

int BM_find(const char *obj, const char *pat, int *cnt) {
	int objlen = strlen(obj), patlen = strlen(pat);
	int i = 0, j, k;
	while (i <= objlen - patlen) {
		for (j = patlen - 1; j >= 0; j--) {
			if (pat[j] != obj[i + j]) {
				(*cnt)++;
				break;
			}
			(*cnt)++;
		}
		if (j == -1) return i;
		if (j == patlen - 1) {
			while (j >= 0) {
				if (obj[i + patlen - 1] == pat[j]) {
					break;
				}
				j--;
			}
			i += (patlen - 1 - j);
			continue;
		}
		int temp = BM_find(pat, pat + j + 1);
		k = temp == (j + 1) ? -1 : temp;
		i += (j - k + 1);
	}
	return -1;
}