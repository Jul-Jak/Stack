#pragma once

const int STACK_MAX_SIZE = 1000000;

template<class T>
class TStack {
private:
	T* array;
	int maxsize;
	int size;

public:
	TStack(int ms = 100); //конструктор с параметром
	TStack(const TStack& ts); //конструктор копирования
	~TStack(); //деструктор
	TStack& operator=(const TStack& ts); //присваивание
	void clear(); //очистить стек
	bool isFull(); //заполнен ли стек?
	bool isEmpty(); //пуст ли стек?
	T top(); //вершина стека
	T pop(); //удалить элемент из стека
	void push(const T& element); //добавить элемент в стек
};

template<class T>
TStack<T>::TStack(int ms) {
	if (ms <= 0 || ms > STACK_MAX_SIZE) throw ms;
	maxsize = ms;
	size = 0;
	array = new T[maxsize];
}

template<class T>
TStack<T>::TStack(const TStack<T>& ts) {
	maxsize = ts.maxsize;
	size = ts.size;
	array = new T[maxsize];
	for (int i = 0; i < size; i++) array[i] = ts.array[i];
}

template<class T>
TStack<T>::~TStack() {
	delete[] array;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& ts) {
	if (*this != ts) {
		if (maxsize != ts.maxsize) {
			delete[] array;
			maxsize = ts.maxsize;
			array = new T[maxsize];
		}
		size = ts.size;
		for (int i = 0; i < size; i++) array[i] = ts.array[i];
	}
}

template<class T>
bool TStack<T>::isFull() {
	return size == maxsize;
}

template<class T>
bool TStack<T>::isEmpty() {
	return size == 0;
}

template<class T>
T TStack<T>::top() {
	if (isEmpty()) throw - 1;
	return array[size - 1];
}

template<class T>
T TStack<T>::pop() {
	if (isEmpty()) throw - 1;
	size--;
	return array[size];
}

template<class T>
void TStack<T>::push(const T& element) {
	if (isFull())
	{
		maxsize *= 2.0;
		T* temp = new int[maxsize];
		memmove(temp, array, sizeof(array) * size);
		delete[] array;
		array = temp;
	}
	array[size] = element;
	size++;;
}

template<class T>
void TStack<T>::clear() {
	size = 0;
}