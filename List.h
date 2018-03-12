// generic class List

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
public:
	// ctor
	List();
	//cctor
	List(const List&);
	// dtor
	~List();

	// setter getter
	T getElement(int i) const;		// return element ke-i
	int len() const;				// return length of list
	int getNelmt() const;			// return number of element in list
	void setElement(int i, T&);		// set element ke-i

	// operator override
	List& operator=(const List&);
	T& operator[](int i);

private:
	T* element;
	int length;
	int Nelmt;
	const int defaultListLength = 100;
};

#endif // !LIST_H

// implementasi
template <class T>
List<T>::List() {
	element = new T[defaultListLength];
	length = defaultListLength;
	Nelmt = 0;
}

template <class T>
List<T>::List(const List<T>& L) {
	element = new T[L.length];
	length = L.length;
	Nelmt = L.Nelmt;

	for (int i = 0; i < Nelmt; i++) {
		element[i] = L.element[i];
	}
}

template <class T>
List<T>::~List() {
	delete[]element;
}

// setter getter
template <class T>
T List<T>::getElement(int i) const {
	return element[i];
}

template <class T>
int List<T>::len() const {
	return length;
}

template <class T>
int List<T>::getNelmt() const {
	return Nelmt;
}

template <class T>
void List<T>::setElement(int i, T& t) {
	element[i] = t;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& L) {
	element = new T[L.length];
	length = L.length;
	Nelmt = L.Nelmt;

	for (int i = 0; i < Nelmt; i++) {
		element[i] = L.element[i];
	}

	return *this;
}

template <class T>
T& List<T>::operator[](int i) {
	return element[i];
}