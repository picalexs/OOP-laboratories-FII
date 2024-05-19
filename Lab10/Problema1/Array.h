#pragma once
#include <stdexcept>

using namespace std;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
void swapp(T& t1, T& t2)
{
	T tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template<class T>
class ArrayIterator
{
	int Current;
	T** List;
public:
	ArrayIterator() : Current(0), List(nullptr) {}
	ArrayIterator& operator ++ ()
	{
		this->Current += 1;
		return *this;
	}
	ArrayIterator& operator -- ()
	{
		this->Current -= 1;
		return *this;
	}
	bool operator= (ArrayIterator<T>& other)
	{
		this->Current = other.Current;
		this->List = other.List;
		return true;
	}
	bool operator!= (ArrayIterator<T>& other)
	{
		return Current != other.Current;
	}
	auto operator*() { return GetElement(); }
	T* GetElement() { return this->List[this->Current]; }
	int GetCurrent() const { return this->Current; }
	T** GetList() const { return this->List; }
	void SetCurrent(int current) { this->Current = current; }
	void SetList(T** list) { this->List = list; }
};

template<class T>
class Array
{
	T** List;
	int Capacity;
	int Size;
public:
	Array() : List(nullptr), Capacity(0), Size(0) {}
	~Array()
	{
		delete[] this->List;
		this->Capacity = 0;
		this->Size = 0;
	}
	Array(int capacity)
	{
		this->List = new T * [capacity];
		this->Capacity = capacity;
		this->Size = 0;
	}
	Array(const Array<T>& otherArray)
	{
		this->List = new T * [otherArray.Size];
		this->Size = otherArray.Size;
		this->Capacity = otherArray.Capacity;
		for (int i = 0; i < this->Size; i++)
			this->List[i] = otherArray.List[i];
	}
	T& operator[] (int index)
	{
		if (index < 0 || index >= Size)
			throw out_of_range("Index out of range");

		return *(this->List[index]);
	}
	const Array<T>& operator+=(const T& newElem)
	{
		if (Size >= Capacity)
			throw out_of_range("Array capacity exceeded");

		this->List[this->Size] = new T(newElem);
		this->Size += 1;
		return *this;
	}
	const Array<T>& Insert(int index, const T& newElem)
	{
		if (Size >= Capacity)
			throw out_of_range("Array capacity exceeded");
		if (index < 0 || index > Size)
			throw out_of_range("Index out of range");

		for (int i = this->Size - 1; i >= index; i--)
			this->List[i + 1] = this->List[i];
		this->List[index] = new T(newElem);
		this->Size += 1;
		return *this;
	}
	const Array<T>& Insert(int index, const Array<T>& otherArray)
	{
		if (Size + otherArray.Size > Capacity)
			throw out_of_range("Array capacity exceeded");
		if (index < 0 || index > Size)
			throw out_of_range("Index out of range");

		for (int i = this->Size - 1; i >= index; i--)
			this->List[i + otherArray.Size] = this->List[i];
		for (int i = index; i < index + otherArray.Size; i++)
			this->List[i] = otherArray.List[i - index];

		this->Size += otherArray.Size;
		return *this;
	}
	const Array<T>& Delete(int index)
	{
		if (index < 0 || index >= Size)
			throw out_of_range("Index out of range");

		delete this->List[index];
		for (int i = index; i < this->Size - 1; i++)
			this->List[i] = this->List[i + 1];
		this->Size -= 1;
		return *this;
	}
	bool operator=(const Array<T>& otherArray)
	{
		if (otherArray.Size > Capacity)
			throw out_of_range("Array capacity exceeded");

		this->List = new T * [otherArray.Size];
		this->Size = otherArray.Size;
		for (int i = 0; i < this->Size; i++)
			this->List[i] = new T(*(otherArray.List[i]));
		return true;
	}
	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = 0; j < Size - i - 1; j++)
			{
				if (*List[j] > *List[j + 1])
				{
					swapp(List[j], List[j + 1]);
				}
			}
		}
	}
	void Sort(int(*compare)(const T&, const T&))
	{
		if (Size <= 1)
			return;
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = 0; j < Size - i - 1; j++)
			{
				if (compare(*List[j], *List[j + 1]) > 0)
				{
					swapp(List[j], List[j + 1]);
				}
			}
		}
	}
	void Sort(Compare* comparator)
	{
		if (Size <= 1)
			return;
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = 0; j < Size - i - 1; j++)
			{
				if (comparator->CompareElements(List[j], List[j + 1]) > 0)
				{
					swapp(List[j], List[j + 1]);
				}
			}
		}
	}
	int BinarySearch(const T& elem)
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (*List[mid] == elem)
				return mid;
			if (*List[mid] < elem)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (compare(*List[mid], elem) == 0)
				return mid;
			if (compare(*List[mid], elem) < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator)
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (comparator->CompareElements(List[mid], &elem) == 0)
				return mid;
			if (comparator->CompareElements(List[mid], &elem) < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	int Find(const T& elem)
	{
		for (int i = 0; i < this->Size; i++)
			if (*(this->List[i]) == elem)
				return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < this->Size; i++)
			if (compare(*(this->List[i]), elem) == 0)
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)
	{
		for (int i = 0; i < this->Size; i++)
			if (comparator->CompareElements(this->List[i], &elem) == 0)
				return i;
		return -1;
	}
	int GetSize() const { return this->Size; }
	int GetCapacity() const { return this->Capacity; }

	void printArray() {
		for (int i = 0; i < this->Size; ++i) {
			cout << *this->List[i] << " ";
		}
		cout << endl;
	}

	ArrayIterator<T> GetBeginIterator()
	{
		ArrayIterator<T> it;
		it.SetCurrent(0);
		it.SetList(this->List);
		return it;
	}

	ArrayIterator<T> GetEndIterator()
	{
		ArrayIterator<T> it;
		it.SetCurrent(this->Size);
		it.SetList(this->List);
		return it;
	}
	ArrayIterator<T> begin() { return GetBeginIterator(); }
	ArrayIterator<T> end() { return GetEndIterator(); }
};
