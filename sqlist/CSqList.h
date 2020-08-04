#include <iostream>
#include <string>
using namespace std;
#define MaxSize 20

template<typename ElemType>
class CSqList {

private:

	ElemType data[MaxSize];
	int length;

public:

	// �޲ι��캯��
	CSqList() {
		length = 0;
	}

	// �вι��캯��
	CSqList(ElemType a[], int len) {
		if (len > MaxSize) {
			throw "�����Ƿ���";
		}
		for (int i = 0; i < len; i++) {
			data[i] = a[i];
		}
		length = len;
	}

	// ����˳���ĳ���
	int getLength() {
		return length;
	}

	// �ж�˳����Ƿ�Ϊ��
	bool isEmpty() {
		return (length == 0);
	}

	// �ж�˳����Ƿ�����
	bool isFull() {
		return (length >= MaxSize);
	}

	// ���˳��������Ԫ��ֵ
	void typeAll() {
		if (isEmpty()) {
			throw "˳���Ϊ�գ�";
		}
		for (int i = 0; i < length; i++) {
			cout << data[i] << '\t';
		}
		cout << endl;
	}

	// ��ȡ˳����еĵ�i��Ԫ��
	ElemType getElem(int i) {
		if (isEmpty()) {
			throw "˳���Ϊ�գ�";
		}
		if (i < 1 || i > length) {
			throw "����λ�ò�����";
		}
		return data[i - 1];
	}

	// ȷ��ֵΪe��Ԫ����˳����еĵڼ�����
	int locateElem(ElemType e) {
		if (isEmpty()) {
			throw "˳���Ϊ�գ�";
		}
		for (int i = 0; i < length; i++) {
			if (data[i] == e) {
				return (i + 1);
			}
		}
		throw "��Ԫ�ز�����";
	}

	// ��Ԫ��e�����i��λ��
	bool ListInsert(int i, ElemType e) {
		if (isFull()) {
			return false;
		}
		if (i < 1 || i > length + 1) {
			return false;
		}
		for (int j = length + 1; j >= i; j--) {
			data[j] = data[j - 1];
		}
		data[i - 1] = e;
		length++;
		return true;
	}

	// ����i��λ�õ�Ԫ��
	bool ListDelete(int i, ElemType &e) {
		// ����Ҳ���Թ��˵���Ϊ�յ����
		if (i < 1 || i > length) {
			return false;
		}
		e = data[i - 1];
		for (int j = i ; j < length; j++) {
			data[j - 1] = data[j];
		}
		length--;
		return true;
	}

};
