#include <iostream>
#define MaxSize 50

template<typename ElemType>
struct SqList {
	ElemType data[MaxSize];
	int length;
};

// 创建空表
template<typename ElemType>
void InitList(SqList<ElemType> &L) {
	L.length = 0;
}

// 根据数组创建表
template<typename ElemType>
bool InitList(SqList<ElemType> &L,ElemType a[],int len) {
	if (len > MaxSize) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		L.data[i] = a[i];
	}
	L.length = len;
	return true;
}

// 判断表是否为空
template<typename ElemType>
bool Empty(SqList<ElemType> L){
	return (L.length == 0);
}

// 打印表中的所有数据
template<typename ElemType>
void PrintList(SqList<ElemType> L) {
	cout << "表中元素为：";
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
	cout << "表长为：" << L.length;
	cout << endl;
}

// 获取表长
template<typename ElemType>
void Length(SqList<ElemType> L) {
	return L.length;
}

// 按值查找
template<typename ElemType>
int LocateElem(SqList<ElemType> L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) return i + 1;
	}
	return 0;
}

// 按位查找
template<typename ElemType>
ElemType GetElem(SqList<ElemType> L, int i) {
	if (i < 1 || i > L.length) throw "参数非法！\n";
	return L.data[i-1];
}

// 在第i个位置插入新的元素，将数据设为e
template<typename Elemtype>
bool ListInsert(SqList<Elemtype> &L,int i,Elemtype e) {
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	if (L.length >= MaxSize) {
		return false;
	}
	for (int j = L.length + 1; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 在第i个位置删除元素，获取该元素的值
template<typename Elemtype>
bool ListDelete(SqList<Elemtype> &L, int i, Elemtype &e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}
