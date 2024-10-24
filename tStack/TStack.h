#pragma once
template <class T>
class TStack {
	T* pMem;
	int Num;
	int MaxSize;
public:
	//������������ � �����������
	TStack(int sz = 10);
	TStack(const TStack& s);
	~TStack();
	//���������
	TStack& operator=(const TStack& s);
	bool operator==(const TStack& s);
	bool operator!=(const TStack& s);
	//������
	bool isEmpty() const return Num == -1;
	bool isFull() const return Num == (MaxSize - 1);
	void push(T value);
	T pop();
	T top() const return pMem[Num];
	void clear() Num = -1;
};