#include <iostream>
using namespace std;
#include <string>
#include "SqList.h"

template<typename Elemtype>
void DeleteX(SqList<Elemtype> &L, Elemtype x) {
	int k = 0;
	// 在遍历元素的同时，记录可以留下来的数据个数，然后同时将这些数据赋到原数组上
	// k可以看作是下一个可以留下的元素的下标
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

template<typename Elemtype>
void DeleteX2(SqList<Elemtype> &L, Elemtype x) {
	int k = 0;
	// k记录目标值个数，表示两个目标值之间的元素要前移的单位数
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[i-k] = L.data[i];
		}
		else {
			k++;
		}
	}
	L.length = L.length - k;
}

template<typename Elemtype>
void DeleteX3(SqList<Elemtype> &L, Elemtype x) {
	int m = 0;
	int n = L.length - 1;
	while (m <= n) {
		// 首尾两个指针，首指针将目标值找出，尾指针将非目标值找出，两者进行交换
		if ((L.data[m] == x) && (L.data[n] != x)) {
			L.data[m] = L.data[n];
			L.data[n] = x;
		}
		if (L.data[m] != x) {
			m++;
		}
		if(L.data[n] == x) {
			n--;
		}
	}
	L.length = m;
}

/*int main() {
	int a[] = { 1,1,5,1,8,42,54,1,32,2,0,1,32,1};
	//int a[] = { 1,1 };
	int len = sizeof(a) / sizeof(a[0]);
	SqList<int> s1;

	InitList(s1, a, len);
	PrintList(s1);


	//DeleteX(s1,1);
	//PrintList(s1);

	DeleteX2(s1, 1);
	PrintList(s1);



	cout << endl;	cout << endl;	cout << endl;
	system("pause");
	return 0;
}*/