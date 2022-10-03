#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{

}

bool Stack::isEmpty()
{
	// If the top of the stack is less the 0, it must be empty
	return (top == -1);
}

bool Stack::isFull()
{
	// If the top is the max - 1, then is must be full
	return (top == MAX_STACK - 1);
}

int Stack::Top()
{
	if (isEmpty() == true)
	{
		cout << "Error: Stack is empty" << endl;
		exit(2);
	}
	else
	{
		// Sets the stacks current element to the top value
		return stack[top];
	}
}

void Stack::pop()
{
	if (isEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		stack[top--];
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
		stack[++top] = x;
	}
}