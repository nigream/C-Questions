#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

template<typename Elemtype>
bool DeleteBetween(SqList<Elemtype> &L,Elemtype s,Elemtype t) {
	if (s >= t) return false;
	if (L.length == 0) return false;
	int i,j;
	for (i = 0; i < L.length && L.data[i] < s; i++);
	if (i > L.length) {
		return false;
	}
	for (j = i; j < L.length && L.data[j] <= t; j++);
	for (; j < L.length; i++, j++) {
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;

}

/*int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(a) / sizeof(a[0]);
	SqList<int> s1;

	InitList(s1, a, len);
	PrintList(s1);

	DeleteBetween(s1, 3, 7);
	PrintList(s1);




	cout << endl;	cout << endl;	cout << endl;
	system("pause");
	return 0;
}*/