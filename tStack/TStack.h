#pragma once
#include <iostream>
template <class T>
class TStack {
	T* pMem;
	int Num;
	int MaxSize;
public:
	//конструкторы и деструкторы
	TStack(int sz = 10);
	TStack(const TStack& s);
	~TStack();
	//операторы
	TStack& operator=(const TStack& s);
	bool operator==(const TStack& s);
	bool operator!=(const TStack& s);
	//методы
	bool isEmpty() const { return Num == -1; }
	bool isFull() const { return Num == (MaxSize - 1); }
	void push(T value);
	T pop();
	T top() const { return pMem[Num]; }
	void clear() { Num = -1; }
};
template <class T>
TStack<T>::TStack(int sz) {
	if (sz <= 0) throw - 1;
	MaxSize = sz;
	pMem = new T[sz];
	Num = -1;
}
template <class T>
TStack<T>::TStack(const TStack& s) {
	MaxSize = s.MaxSize;
	pMem = new T[MaxSize];
	Num = s.Num;
	for (int i = 0; i <= s.Num; i++) pMem[i] = s.pMem[i];
}
template <class T>
TStack<T>::~TStack() {
	delete[] pMem;
}
template <class T>
TStack<T>& TStack<T>::operator=(const TStack& s) {
	if (this == &s) return &this;
	if (MaxSize != s.MaxSize) {
		delete[] pMem;
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
	}
	Num = s.Num;
	for (int i = 0; i <= s.Num; i++) pMem[i] = s.pMem[i];
	return &this;
}
template <class T>
bool TStack<T>::operator==(const TStack& s) {
	if (this == &s) return true;
	if (MaxSize != s.MaxSize || Num != s.Num) return false;
	for (int i = 0; i <= Num; i++) {
		if (pMem[i] != s.pMem[i]) return false;
	}
	return true;
}
template <class T>
bool TStack<T>::operator!=(const TStack& s) {
	return !(&this == s);
}
template <class T>
void TStack<T>::push(T value) {
	if (isFull()) throw - 1;
	pMem[++Num] = value;
}
template <class T>
T TStack<T>::pop() {
	if (isEmpty()) throw - 1;
	return pMem[Num--];
}
