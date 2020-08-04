#include <iostream>
#define MaxSize 50

template<typename ElemType>
struct SqList {
	ElemType data[MaxSize];
	int length;
};

// �����ձ�
template<typename ElemType>
void InitList(SqList<ElemType> &L) {
	L.length = 0;
}

// �������鴴����
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

// �жϱ��Ƿ�Ϊ��
template<typename ElemType>
bool Empty(SqList<ElemType> L){
	return (L.length == 0);
}

// ��ӡ���е���������
template<typename ElemType>
void PrintList(SqList<ElemType> L) {
	cout << "����Ԫ��Ϊ��";
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
	cout << "��Ϊ��" << L.length;
	cout << endl;
}

// ��ȡ��
template<typename ElemType>
void Length(SqList<ElemType> L) {
	return L.length;
}

// ��ֵ����
template<typename ElemType>
int LocateElem(SqList<ElemType> L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) return i + 1;
	}
	return 0;
}

// ��λ����
template<typename ElemType>
ElemType GetElem(SqList<ElemType> L, int i) {
	if (i < 1 || i > L.length) throw "�����Ƿ���\n";
	return L.data[i-1];
}

// �ڵ�i��λ�ò����µ�Ԫ�أ���������Ϊe
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

// �ڵ�i��λ��ɾ��Ԫ�أ���ȡ��Ԫ�ص�ֵ
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
