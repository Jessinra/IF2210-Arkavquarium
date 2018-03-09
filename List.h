// generic class List

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
public:
	// ctor
	List();
	
	// dtor
	~List();

	// setter getter
	T getElement(int i) const;		// return element ke-i
	int len() const;			// return length of list
	void setElement(int i, T&);		// set element ke-i

	// operator override
	T& operator[](int i);

private:
	T* element;
	int length;
	const int defaultListLength = 100;
};

#endif // !LIST_H

// implementasi
template <class T>
List<T>::List() {
	element = new T[defaultListLength];
	length = defaultListLength;
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
void List<T>::setElement(int i, T& t) {
	element[i] = t;
}

template <class T>
T& List<T>::operator[](int i) {
	return element[i];
}