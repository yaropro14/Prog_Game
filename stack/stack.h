#ifndef STACK_H_
#define STACK_H_


#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

 
template <typename T>
class Stack
{
private:
	T _canary_begin;
	T* _data; // stack pointer
	T _canary_end;
	int _size; // size of stack
	int _n_elem; // number of elemnts
	void resize(int size);
	void OK();
public:
	Stack(int n); // constructor
	~Stack(); // destructor
	bool Push(const T  );
	T Pop();
	void Print();
};


const int CANARY = 0xBEDABEDA;


template <typename T>
Stack<T>::Stack(int n)
{
	_canary_begin = CANARY;
	
	_size = n;
	if(_size == 0)	_size = 10;
	
	_size += 2;
	
	_data = new T [_size];
	_data[0] = CANARY;
	_data[_size - 1] = CANARY;
	_n_elem = 1;
	
	_canary_end = CANARY;
	OK();
}


template <typename T>
Stack<T>::~Stack()
{
	delete [] _data;
	_data = nullptr;
}


template <typename T>
bool Stack<T>::Push(const T val)
{
	OK();
	if (_n_elem == 0 || _size == 0)
		return false;
	
	if (_n_elem  == _size - 1)
	{
		_size += 10;
		resize(_size);
	}	
	
	_data[_n_elem ++] = val;
	
	return true;
	OK();
}


template <typename T>
T Stack<T>::Pop()
{
	OK();
	T data = 0;
	data = _data[--_n_elem];
	_data[_n_elem + 1] = 0;
		if (_n_elem  == _size - 13)
	{
		_size -= 10;
		resize(_size);
	}
	OK();
	return data;
}

template <typename T>
void Stack<T>::resize(int size)
{
	OK();
	
	T* new_data = new T [size];
	new_data[0] = CANARY;
	new_data[size - 1] = CANARY;
	
	for(int i = 0; i <_n_elem + 1; i++)
	{
		new_data[i] = _data[i];
	}
	
	delete [] _data;
	_data = new_data;
	OK();
}


template <typename T>
void Stack<T>::OK()
{
	assert(_data);
	
	int err = 0;
	
	if(_data == NULL)
	{
		cerr << "STACK_NULL"<< endl;
		return;
	}
		
	if(_canary_begin != CANARY || _canary_end != CANARY)
	{
		cerr << "CANARY_ERROR" << endl;
		return;
	}
		
	if(_data[0] != CANARY || _data[_size - 1] != CANARY)
	{
		cerr << "CANARY_DATA_ERROR" << endl;
		return;
	}
	
		
	if(_size <= 0)
	{
		cerr << "SIZE_ERROR" << endl;
		return;
	}
		
	if(_n_elem < 0)
	{
		cerr << "DATA_ERROR" << endl;
		return;
	}
}


template <typename T>
void Stack<T>::Print()
{
	OK();
	
	cout << "Print stack\n" << endl;	
	T i;
	
	if (_n_elem == 0)
	{
		printf("Empty stack\n");
		return;
	}
		
	else
	{
		for (i = 1; i < _n_elem; i ++)
		{
			printf("data[%d] = %d\n", i, _data[i]);
		}
	}
	
}


#endif
