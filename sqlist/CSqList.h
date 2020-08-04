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

	// 无参构造函数
	CSqList() {
		length = 0;
	}

	// 有参构造函数
	CSqList(ElemType a[], int len) {
		if (len > MaxSize) {
			throw "参数非法！";
		}
		for (int i = 0; i < len; i++) {
			data[i] = a[i];
		}
		length = len;
	}

	// 返回顺序表的长度
	int getLength() {
		return length;
	}

	// 判断顺序表是否为空
	bool isEmpty() {
		return (length == 0);
	}

	// 判断顺序表是否已满
	bool isFull() {
		return (length >= MaxSize);
	}

	// 输出顺序表的所有元素值
	void typeAll() {
		if (isEmpty()) {
			throw "顺序表为空！";
		}
		for (int i = 0; i < length; i++) {
			cout << data[i] << '\t';
		}
		cout << endl;
	}

	// 获取顺序表中的第i个元素
	ElemType getElem(int i) {
		if (isEmpty()) {
			throw "顺序表为空！";
		}
		if (i < 1 || i > length) {
			throw "查找位置不存在";
		}
		return data[i - 1];
	}

	// 确定值为e的元素是顺序表中的第几个数
	int locateElem(ElemType e) {
		if (isEmpty()) {
			throw "顺序表为空！";
		}
		for (int i = 0; i < length; i++) {
			if (data[i] == e) {
				return (i + 1);
			}
		}
		throw "该元素不存在";
	}

	// 将元素e插入第i个位置
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

	// 将第i个位置的元素
	bool ListDelete(int i, ElemType &e) {
		// 这里也可以过滤掉表为空的情况
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
