#include <iostream>
#include <exception>
#include <string>
using namespace std;
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
class CompCrescator : public Compare
{
	int CompareElements(void* e1, void* e2) {
		int* x = (int*)e1;
		int* y = (int*)e2;
		if (*x == *y)
			return 0;
		if (*x > *y)
			return 1;
		else return -1;
	}
};
template<class T>
class ArrayIterator {
public:
	T** Current;
	ArrayIterator() {
		Current = 0;
	}
	~ArrayIterator() {
		Current = 0;
	}
	ArrayIterator& operator ++ () {
		++Current;
		return *this;
	}
	ArrayIterator& operator -- () {
		--Current;
		return *this;
	}
	bool operator = (ArrayIterator<T>& Iterator) {
		return Current == Iterator.Current;
	}
	bool operator != (ArrayIterator<T>& Iterator) {
		return Current != Iterator.Current + 1;
	}
	T operator * () {
		return **Current;
	}
	T* GetElement() {
		return Current;
	}
};

template<class T>
class Array
{
public:
	T**List = nullptr;
	int Capacity=0;//Dimensiunea liste de pointeri
	int Size=0;//cati pointeri sunt in lista
public:
	Array();
	~Array();
	Array(int capacity);
	bool isEmpty();
	int GetCapacity();
	void printArray();
	Array(const Array<T>&otherArray);
	T& operator[] (int index);
	const Array<T>& operator+=(const T &newElem);
	const Array<T>& Insert(int index, const T &newElem); 
	const Array<T>& Insert(int index,  Array<T>&otherArray);
	const Array<T>& Delete(int index);
	bool operator=(const Array<T> &otherArray);
	bool operator==(const Array<T> &otherArray);
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));
	int BinarySearch(const T& elem, Compare *comparator);
	int BinarySearch(const T& elem);
	int GetSize();
	int Find(const T& elem);
	int Find(const T& elem, int(*compare)(const T&, const T&));
	int Find(const T& elem, Compare *comparator);
	void Sort();
	void Sort(int(*compare)(const T&, const T&));
	void Sort(Compare *comparator); 
	ArrayIterator<T> begin();
	ArrayIterator<T> end();
};
class IndexOutOfBound :public exception 
{
	virtual const char*what() const throw()
	{
		return "Index out of bounds";
	}
};
template<class T>
Array<T>::Array()
{
	Size = Capacity = 0;
}
template<class T>
Array<T>::~Array()
{
	delete [] List;
}
template<class T>
Array<T>::Array(int capacity)
{
	Capacity = capacity;
	Size = 0;
	List = new T*[Capacity];
}
template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
	List = otherArray.List;
	Size = otherArray.Size;
	Capacity = otherArray.Capacity;
}

template<class T>
T & Array<T>::operator[](int index)
{
	IndexOutOfBound excep;
	try
	{
		if (index > Capacity  || index < 0) throw excep;
			return *(List[index]);
	}
	catch (exception & ex)
	{
		cout<<ex.what();
	}
}

template<class T>
const Array<T>& Array<T>::operator+=(const T & newElem)
{
	if (Size + 1 <= Capacity)
	{
		T**newList = new T*[Size + 1];
		newList = List;
		newList[Size] = new T;
		*newList[Size++] = newElem;
		List = newList;
	}
	return *this;
}
template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T & newElem)
{
	IndexOutOfBound inEx;
	try
	{
		if (index<0 || index>Size) throw inEx;
		if (Capacity < Size + 1)
			Capacity++;
		T**newList = new T*[Size + 1];
		newList = List;
		newList[Size] = new T;
		for (int i = Size; i > index; i--)
			*newList[i] = *newList[i - 1];
		*newList[index] = newElem;
		List = newList;
		Size++;
		return *this;
	}
	catch (exception & err)
	{
		cout << err.what();
	}
}
template<class T>
inline const Array<T>& Array<T>::Insert(int index, Array<T> & otherArray)
{
	IndexOutOfBound indExp;
	try
	{
		if (index < 0 || index >= Size) throw indExp;
		for (int i = 0; i < otherArray.GetSize(); i++)
			Insert(index + i, otherArray[i]);
		return *this;

	}
	catch (exception & exp)
	{
		cout << exp.what();
	}
}
template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{
	IndexOutOfBound inEx;
	try
	{
		if (index<0 || index>Size) throw inEx;
		
		for (int i = index; i < Size - 1; i++)
			*List[i] = *List[i + 1];
		Size--;
		return *this;
	}
	catch (exception err)
	{
		cout << err.what();
	}
}
template<class T>
inline void Array<T>::Sort(int(*compare)(const T &, const T &))
{
	bool unsorted = true;
	do
	{
		unsorted = false;
		for (int i = 0; i < Size - 1; i++)
			if (compare(*List[i],*List[i+1])==1)
			{
				T var = *List[i];
				*List[i] = *List[i + 1];
				*List[i + 1] = var;
				unsorted = true;
			}
	} while (unsorted);
}
template<class T>
inline void Array<T>::Sort(Compare * comparator)
{
	bool unsorted = true;
	do
	{
		unsorted = false;
		for (int i = 0; i < Size - 1; i++)
			if (comparator->CompareElements(List[i],List[i+1])==1)
			{
				T var = *List[i];
				*List[i] = *List[i + 1];
				*List[i + 1] = var;
				unsorted = true;
			}
	} while (unsorted);
}
template<class T>
inline int Array<T>::BinarySearch(const T & elem)
{
	int l = 0;
	int r = Size-1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (*List[m] == elem)
			return m;
		if (*List[m] < elem)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
template<class T>
inline ArrayIterator<T> Array<T>::begin()
{

	ArrayIterator<T> Iterator;
	Iterator.Current = &List[0];
	return Iterator;
}

template<class T>
inline ArrayIterator<T> Array<T>::end()
{
		ArrayIterator<T> Iterator;
		Iterator.Current = &List[Size - 1];
		return Iterator;
}
template<class T>
inline bool Array<T>::operator=(const Array<T>& otherArray)
{
	Size = otherArray.getSize();
	Capacity = otherArray.GetCapacity();
	List = otherArray.List;
}
template<class T>
inline bool Array<T>::operator==(const Array<T>& otherArray)
{
	if (Size != otherArray.GetSize())
		return false;
	else
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] != otherArray[i])
				return false;
		return true;
	}
}
template<class T>
inline int Array<T>::BinarySearch(const T & elem, int(*compare)(const T &, const T &))
{
	int l = 0;
	int r = Size - 1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (compare(*List[m],elem)==0)
			return m;
		if (compare(*List[m], elem) ==-1)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
template<class T>
inline int Array<T>::BinarySearch(const T & elem, Compare * comparator)
{
	int l = 0;
	int r = Size - 1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (comparator->CompareElements(List[m], (T*)&elem) == 0)
			return m;
		if (comparator->CompareElements(List[m], (T*)&elem) == -1)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
template<class T>
inline int Array<T>::GetSize()
{
	return Size;
}
template<class T>
inline int Array<T>::Find(const T & elem)
{
	for (int i = 0; i < Size; i++)
		if (*List[i] == elem)
			return i;
	return -1;
}
template<class T>
inline int Array<T>::Find(const T & elem, int(*compare)(const T &, const T &))
{
	for (int i = 0; i < Size; i++)
		if (compare(*List[i],elem)==0)
			return i;
	return -1;
}
template<class T>
inline int Array<T>::Find(const T & elem, Compare * comparator)
{
	for (int i = 0; i < Size; i++)
		if (comparator->CompareElements(List[i], (T*)&elem) == 0)
			return i;
	return -1;
}
template<class T>
inline bool Array<T>::isEmpty()
{
	return Size == 0;
}

template<class T>
inline int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
inline void Array<T>::printArray()
{
	for (int index = 0; index < Size; index++)
		cout << *(List[index]) << " ";
	cout << endl;
}

template<class T>
inline void Array<T>::Sort()
{
	bool unsorted = true;
	do
	{
		unsorted = false;
		for(int i=0;i<Size-1;i++)
			if (*List[i] > *List[i + 1])
			{
				T var = *List[i];
				*List[i] = *List[i + 1];
				*List[i + 1] = var;
				unsorted = true;
			}
	} while (unsorted);
}


