#pragma once
#include <limits>
#include <iostream>

template <class T>
class Vector
{
	T** vector;
	int size;
public:
	Vector();
	Vector(const Vector& other);
	Vector(Vector&& other);
	~Vector();
	void insert(int idx, T val);
	void remove(int idx);
	void sort(int(*callback)(T, T));
	void print();
	T operator[](int idx);
};

template <class T>
Vector<T>::Vector()
{
	this->vector = nullptr;
	this->size = 0;
}

template <class T>
Vector<T>::Vector(const Vector& other)
{
	this->size = other.size;
	this->vector = new T * [this->size];
	for (int i = 0; i < this->size; i++)
		this->vector[i] = new T(*other.vector[i]);
}

template <class T>
Vector<T>::Vector(Vector&& other)
{
	this->size = other.size;
	this->vector = other.vector;
	other.vector = nullptr;
	other.size = 0;
}

template <class T>
Vector<T>::~Vector()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->vector[i];
	delete[] vector;
	this->size = 0;
}


template <class T>
void Vector<T>::insert(int idx, T val)
{
	if (idx<0 || idx>this->size) {
		std::cout << "Illegal index!\n";
		return;
	}

	this->size += 1;
	T** tmpVector = new T * [this->size];
	for (int i = 0; i < idx; i++) {
		tmpVector[i] = this->vector[i];
	}
	for (int i = idx; i < this->size - 1; i++)
	{
		tmpVector[i + 1] = this->vector[i];
	}
	tmpVector[idx] = new T(val);
	delete[] this->vector;
	this->vector = tmpVector;
}

template <class T>
void Vector<T>::remove(int idx)
{
	if (idx<0 || idx>this->size) {
		std::cout << "Illegal index!\n";
		return;
	}

	T** tmpVector = new T * [this->size - 1];
	for (int i = 0; i < idx; i++) {
		tmpVector[i] = this->vector[i];
	}
	for (int i = idx; i < this->size - 1; i++)
	{
		tmpVector[i] = this->vector[i + 1];
	}
	delete[] this->vector;
	this->size -= 1;
	this->vector = tmpVector;
}

template <class T>
void Vector<T>::sort(int(*callback)(T, T))
{
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = i + 1; j < this->size; j++)
		{
			if ((callback != nullptr && callback(*this->vector[i], *this->vector[j]) >= 1)
				|| (callback == nullptr && *this->vector[i] > *this->vector[j]))
			{
				T* tmp = this->vector[i];
				this->vector[i] = this->vector[j];
				this->vector[j] = tmp;
			}
		}
	}
}

template <class T>
void Vector<T>::print()
{
	for (int i = 0; i < this->size; i++)
		std::cout << *this->vector[i] << ' ';
	std::cout << '\n';
}

template <class T>
T Vector<T>::operator[](int idx)
{
	if (idx<0 || idx>this->size) {
		std::cout << "Illegal index!\n";
		return 0;
	}
	return *this->vector[idx];
}

