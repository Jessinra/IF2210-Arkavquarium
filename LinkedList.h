// kelas generik LinkedList
// indeks dimulai dari 1

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	struct Node {
		T value;
		Node *next;
	};
public:	
	// ctor
	LinkedList();
	// cctor + operator=
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	// dtor
	~LinkedList();

	// method
	bool isEmpty() const;
	void add(const T&);
	void remove(const T&);		// menghapus element dengan identitas demikian yang paling pertama
	int find(const T&);			// mengembalikan indeks element dengan identitas demikian yang paling pertama. bila tidak ada return -1
	T get(const int&);			// dipastikan ada
	void printList() const;		// print isi list dengan format [1,2,...,n]
	int getNBelmt() const;		// get number of element in list		

	// operator override
	friend ostream& operator<<(ostream& s, const LinkedList<T>& L) {
		if (!L.isEmpty()) {
			s << "[";
			Node *list = L.head;
			s << list->value;

			while (list->next != NULL) {
				list = list->next;
				s << "," << list->value;
			}
			s << "]";
		}
		else {
			s << "[]";
		}
		return s;
	}

	Node *head;
};

#endif

// implementasi
template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L) {
	head = new Node();
	head->value = L.head->value;

	Node *prec = head;
	Node *n1 = L.head;
	while (n1->next != NULL) {
		n1 = n1->next;
		Node *n = new Node();
		n->value = n1->value;
		prec->next = n;
		prec = n;
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L) {
	head = new Node();
	head->value = L.head->value;

	Node *prec = head;
	Node *n1 = L.head;
	while (n1->next != NULL) {
		n1 = n1->next;
		Node *n = new Node();
		n->value = n1->value;
		prec->next = n;
		prec = n;
	}

	return *this;
}

template <class T>
LinkedList<T>::~LinkedList() {
	if (!isEmpty()) {
		Node *list = head;

		while (list->next != NULL) {
			Node *temp = list;
			list = list->next;
			delete temp;
		}
	}
}


// method 
template <class T>
bool LinkedList<T>::isEmpty() const {
	return head == NULL;
}

template <class T>
void LinkedList<T>::add(const T& t) {
	if (!isEmpty()) {	
		Node *i = head;

		while (i->next != NULL) {
			i = i->next;
		}

		Node *n = new Node();
		n->value = t;
		n->next = NULL;

		i->next = n;
	}
	else {
		Node *n = new Node();
		n->value = t;
		n->next = NULL;
		
		head = n;
	}
}

template <class T>
void LinkedList<T>::remove(const T& t) {
	if (head->value == t) {
		Node *temp = head;
		head = temp->next;
		delete temp;
	}
	else {
		Node *prec = head;
		Node *del = head->next;

		while (del->next != NULL && del->value != t) {
			prec = del;
			del = del->next;
		}
		prec->next = del->next;
		delete del;
	}
}

template <class T>
int LinkedList<T>::find(const T& t) {
	if (!isEmpty()) {
		Node *del = head;
		int idx = 1;

		while (del->next != NULL && del->value != t) {
			del = del->next;
			idx++;
		}

		if (del->value == t) {
			return idx;
		}
	}
	return -1;
}

template <class T>
T LinkedList<T>::get(const int& idx) {
	if (!isEmpty()) {
		int i = 1;
		Node *n = head;

		while (n->next != NULL && i != idx) {
			n = n->next;
			i++;
		}

		if (i == idx) {
			return n->value;
		}
	}
	return 0;
}

template <class T>
void LinkedList<T>::printList() const {
	if (!isEmpty()) {
		cout << "[";
		Node *list = head;
		cout << list->value;

		while (list->next != NULL) {
			list = list->next;
			cout << "," << list->value;
		}
		cout << "]";
	}
	else {
		cout << "[]";
	}
}

template <class T>
int LinkedList<T>::getNBelmt() const {
	if (!isEmpty()) {
		int i = 1;
		Node *list = head;
		while (list->next != NULL) {
			list = list->next;
			i++;
		}
		return i;
	}
	else {
		return 0;
	}
}
