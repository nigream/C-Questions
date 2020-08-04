#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

template<typename Elemtype>
void DeleteMin(SqList<Elemtype> &L, Elemtype &e) {
	Elemtype min = L.data[0];
	int i = 0;
	for (int j = 1; j < L.length; j++) {
		if (min > L.data[j]) {
			min = L.data[j];
			i = j;
		}
	}
	e = L.data[i];
	L.data[i] = L.data[L.length - 1];
	L.length--;
}

template<typename Elemtype>
bool DeleteMin2(SqList<Elemtype> &L, Elemtype &e) {
	if (L.length == 0) return false;
	e = L.data[0];
	int i = 0;
	for (int j = 1; j < L.length; j++) {
		if (e > L.data[j]) {
			e = L.data[j];
			i = j;
		}
	}
	e = L.data[i];
	L.data[i] = L.data[L.length - 1];
	L.length--;
	return true;
}

/*int main() {
	int a[] = { 4,1,5,6,8,2,0,3 };
	int len = sizeof(a) / sizeof(a[0]);
	SqList<int> s1;

	InitList(s1, a, len);
	PrintList(s1);

	int e;
	DeleteMin(s1, e);
	cout << "É¾³ýµÄÖµÊÇ£º" << e << endl;
	PrintList(s1);



	cout << endl;	cout << endl;	cout << endl;
	system("pause");
	return 0;
}*/