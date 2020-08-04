#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

// 无序顺序表
template<typename Elemtype>
bool DeleteEqual(SqList<Elemtype> &L) {
	if (L.length == 0) return false;
	int k;
	int len = L.length;
	for (int i = 0; i < len; i++) {
		k = i + 1;
		for (int j = i + 1; j < len; j++) {
			if (L.data[j] != L.data[i]) {
				L.data[k] = L.data[j];
				k++;
			}
		}
		len = k;
	}
	L.length = len;
	return true;
}


// 有序顺序表
template<typename Elemtype>
bool DeleteEqual2(SqList<Elemtype> &L) {
	if (L.length == 0) return false;
	int k = 1;
	for (int i = 0; i < L.length - 1; i++) {
		if (L.data[i + 1] != L.data[i]) {
			L.data[k] = L.data[i + 1];
			k++;
		}
	}
	L.length = k;
	return true;
}


int main() {
	int a[] = { 1,2,3,1,2,3,4,4,5,6,7,8,5,8,1,2,3};
	int len = sizeof(a) / sizeof(a[0]);
	SqList<int> s1;

	InitList(s1, a, len);
	PrintList(s1);

	DeleteEqual(s1);
	PrintList(s1);


	int b[] = { 1,1,1,1,1,2,2,2,3,3,4,4,4,5,6,7,8,8,8,9 };
	int len2 = sizeof(b) / sizeof(b[0]);
	SqList<int> s2;

	InitList(s2, b, len2);
	PrintList(s2);

	DeleteEqual2(s2);
	PrintList(s2);



	cout << endl;	cout << endl;	cout << endl;
	system("pause");
	return 0;
}