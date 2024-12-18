#pragma once
#include "Node.cpp"
template <class T>
class LStack {
	Node<T>* pFirst;
public:
	LStack() :pFirst(nullptr) {}
	LStack(const LStack<T>& s);
	bool IsEmpty() { return pFirst == nullptr; }
	bool IsFull();
	void Clear();

	T Peek() { return pFirst->val; }
	void Push(T v);
	T Pop();

	bool operator ==(const LStack<T>& s) const;
	bool operator !=(const LStack<T>& s) const { return !(*this == s); }
	LStack& operator=(const LStack<T>& s);

	~LStack();
};
//___________________________________ ŒÕ—“–” “Œ–  Œœ»–Œ¬¿Õ»ﬂ
template <class T>
LStack<T>::LStack(const LStack& s) {
	if (s.pFirst != nullptr) {
		pFirst = new Node<T>();
		pFirst->val = s.pFirst->val;
		pFirst->pNext = nullptr;
		Node<T>* prev = pFirst;
		Node<T>* tmp = s.pFirst->pNext;
		while (tmp != nullptr)
		{
			Node<T>* node = new Node<T>();
			node->val = tmp->val;
			node->pNext = nullptr;
			prev->pNext = node;
			tmp = tmp->pNext;
			prev = prev->pNext;
		}
	}
	else {
		pFirst = nullptr;
	}
}
//___________________________________—À”∆≈¡Õ€≈ Ã≈“Œƒ€
template <class T>
bool LStack<T>::IsFull() {
	Node<T>* tmp;
	try {
		tmp = new Node<T>();
	}
	catch (...) {
		return true;
	}
	delete tmp;
	return false;
}
template <class T>
void LStack<T>::Push(T v) {
	if (IsFull()) throw - 1;
	Node<T>* tmp = new Node<T>();
	tmp->val = v;
	tmp->pNext = pFirst;
	pFirst = tmp;
}
template <class T>
T LStack<T>::Pop() {
	if (IsEmpty()) throw - 1;
	Node<T>* tmp = pFirst;
	T res = tmp->val;
	pFirst = pFirst->pNext;
	delete tmp;
	return res;
}
template <class T>
void LStack<T> ::Clear() {
	Node<T>* tmp;
	while (pFirst != nullptr) {
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}
//___________________________________ƒ≈—“–” “Œ–
template <class T>
LStack<T>::~LStack() {
	Node<T>* tmp;
	while (pFirst != nullptr) {
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

//___________________________________Œœ≈–¿÷»»
template <class T>
bool LStack<T>::operator==(const LStack<T>& s) const {
	if (this == &s) return true;
	Node<T>* tmp1 = pFirst;
	Node<T>* tmp2 = s.pFirst;
	while (tmp1 != nullptr && tmp2 != nullptr) {
		if (tmp1->val != tmp2->val) return false;
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	return (tmp1 == tmp2);
}
template <class T>
LStack<T>& LStack<T>::operator=(const LStack& s) {
	if (this == &s) return *this;
	Node<T>* tmp;
	while (pFirst != nullptr) {
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	if (s.pFirst != nullptr) {
		pFirst = new Node<T>();
		pFirst->val = s.pFirst->val;
		pFirst->pNext = nullptr;
		Node<T>* prev = pFirst;
		Node<T>* tmp = s.pFirst->pNext;
		while (tmp != nullptr)
		{
			Node<T>* node = new Node<T>();
			node->val = tmp->val;
			node->pNext = nullptr;
			prev->pNext = node;
			tmp = tmp->pNext;
			prev = prev->pNext;
		}
	}
	else {
		pFirst = nullptr;
	}
}