#include "TStack.h"	
template <class T>
TStack<T>::TStack(int sz) {
	if (sz <= 0) throw - 1;
	MaxSize = 10;
	pMem = new T[sz];
	Num = -1;
}
template <class T>
TStack<T>::TStack(const TStack& s) {
	MaxSize = s.MaxSize;
	pMem = new T[sz];
	Num = s.Num;
	for (i = 0; i <= s.Num; i++) pMem[i] = s.pMem[Num];
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
	for (i = 0; i <= s.Num; i++) pMem[i] = s.pMem[Num];
	return &this;
}
template <class T>
bool TStack<T>::operator==(const TStack& s) {
	if (this == &) return true;
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