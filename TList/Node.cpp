template <class T>
struct Node {
	T val;
	Node* pNext;
	Node(const Node& n);
	Node(T v = T());
};
template <class T>
Node<T>::Node(T v) :val(v), pNext(nullptr) {}
template <class T>
Node<T>::Node(const Node& n) :val(n.val), pNext(n.pNext) {}
template <class T>
class TList {
	Node<T>* pFirst;
public:
	int GetSize();
	void PushFront(T value);
};
template <class T>
int TList<T>::GetSize() {
	int res = 0;
	Node<T>* cur = pFirst;
	while (cur != nullptr) {
		res++;
		cur = cur->pNext;
	}
	return res;
}
template <class T>
void TList<T>::PushFront(T value) {
	Node<T>* tmp = pFirst;
	pFirst = new Node<T>;
	pFirst->pNext = tmp;
	pFirst->val = value;
}