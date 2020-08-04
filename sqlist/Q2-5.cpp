#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

template<typename Elemtype>
bool DeleteBetween(SqList<Elemtype> &L, Elemtype s, Elemtype t) {
	if (s >= t || L.length == 0) return false;
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] < s || L.data[i] > t) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
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