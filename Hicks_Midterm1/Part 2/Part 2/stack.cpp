#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{

}

bool Stack::isEmpty()
{
	// If the top of the stack is less the 0, it must be empty
	return (Top == -1);
}

bool Stack::isFull()
{
	// If the top is the max - 1, then is must be full
	return (Top == MAX_STACK - 1);
}

int Stack::top()
{
	if (isEmpty() == true)
	{
		cout << "Error: Stack is empty" << endl;
		exit(3);
	}
	else
	{
		// Sets the stacks current element to the top value
		return stack[Top];
	}
}

void Stack::pop()
{
	if (isEmpty())
	{
		cout << "The stack is empty" << endl;
		exit(2);
	}
	else
	{
		stack[Top--];
	}
}

void Stack::push(int x)
{
	if (isFull())
	{
		cout << "The stack is full" << endl;
		exit(1);
	}
	else
	{
		stack[++Top] = x;
	}
}