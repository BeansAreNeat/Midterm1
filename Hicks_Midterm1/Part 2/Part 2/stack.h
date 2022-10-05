#pragma once
#define MAX_STACK 3

class Stack
{
public:
	Stack();
	void push(int x);	// Add element to stack
	void pop();			// Remove element from stack
	int top();			// Return to top of stack
	bool isFull();		// Checks if full
	bool isEmpty();		// Checks if empty
private:
	int stack[MAX_STACK] = { 0, };
	int Top = 0;
};