#pragma once
#define MAX_STACK 5

class Stack
{
public:
	Stack();
	void push(int x);	// Add element
	void pop();			// Remove element
	int Top();			// Return to top of stack
	bool isFull();		// Checks if full
	bool isEmpty();		// Checks if empty
private:
	int stack[MAX_STACK] = { 0, };
	int top = -1;
};