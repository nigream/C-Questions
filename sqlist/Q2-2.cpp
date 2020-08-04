#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

template<typename Elemtype>
void ReverseList(SqList<Elemtype> &L) {
	Elemtype temp;
	for (int i = 0; i < L.length/2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}


/*int main() {
int a[] = { 4,1,5,6,8,2,0,3 };
int len = sizeof(a) / sizeof(a[0]);
SqList<int> s1;

InitList(s1, a, len);
PrintList(s1);

ReverseList(s1);
PrintList(s1);



cout << endl;	cout << endl;	cout << endl;
system("pause");
return 0;
}*/