#include <iostream>
#include <cstdlib>

#include "stack.h"

int main()
{
	std::cout << "hello!" << std::endl;
	
	Stack <int> myStack(0);

	int ct = 0;
	while (ct++ != 6)
	{
		int temp;
		cin >> temp;
		myStack.Push(temp);
	}
	
	ct = 0;
	
	myStack.Print();
	
	while (ct++ != 6)
	{
		cout << myStack.Pop();
	}
	
	return 0;
}
