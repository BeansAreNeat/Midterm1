#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
	Citations:
	https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
	https://www.geeksforgeeks.org/stack-a-4-evaluation-postfix-expression/
	https://gist.github.com/mycodeschool/7702441
*/

/* Questions:
		What does stack/input precedence mean??
		How to properly cite code
		Clarify instructions
*/

int postfix(char input);	// Postfix Expression Evaluation
void convert(char input);	// Converts Infix to postfix (First link in citation)
int prec(char input);		// Finds operator precendce (Modified code from geeksforgeeks.org)

int main()
{
	
	string equ;	// Equation
	cout << "Enter mathematical expression: " << endl;
	getline(cin, equ);
		
	for (int i = 0; i < equ.length(); i++)	// For as long as the string. from geeksforgeeks.org
	{
		char c1;
		c1 = equ[i];
		convert(c1);
	}

	return 0;
}

void convert(char c)
{
	stack<int> stack;
	string output;					// Postfix output

	if (c >= '0' && c <= '9')		// If the operand is valid
	{
		output += c;				// Set it to output
	}

	// The two else if statements are for dealing with brackets
	else if (c == '(')				// If char is left bracket
	{
		stack.push('(');			// Put left bracket in stack

	}

	else if (c == ')')				// If the char is right bracket
	{
		while (stack.top() != '(')	// and while the top of the stack is not the left bracket
		{
			output += stack.top();	// Set the output to whatever is the top of the stack
			stack.pop();			// and pop it from the stack
		}
		stack.pop();				// If the top of the stack IS '(' then pop it
	}

	// Part of the alorithm given on the PDF below
	else
	{
		// If the stack is not empty and while the stack precedence >= input precedence
		while (!stack.empty() && prec(c) <= prec(stack.top()))	
		{
			output += stack.top();	// Add the top of the stack to the output
			stack.pop();			// Pop the stack
		}
		stack.push(c);				// Push input on to stack
	}
	// While stack is not empty AND the top of the stack is not the left bracket
	if (!stack.empty()) {
		while (stack.top() != '(')
		{
			output += stack.top();	// Set the output to whatever is the top of the stack
			stack.pop();			// and pop it from the stack
		}
	}

	if (stack.top() == '(')		// If the top of the stack IS '('
	{
		stack.pop();			// then pop it
	}

	// Pop all the remaining elements from the stack and add it to output
	while (!stack.empty())		// While the stack isn't empty
	{
		output += stack.top();		// Add the stack to the output
		stack.pop();				// Pop remaining elements
	}
	cout << output << " ";
}
/*
int postfix(char c)
{
	//operatorStack
	Stack stack;

	// Is char is is a digit, convert to int and store it.
	if (isdigit(c))
	{
		int num = 0;
		num = (num * 10) + (c - '0');	// Converts char to int, from geeksforgeeks
		stack.push(num);				// Pushes number, not c since c is the wrong value
	}
	// If its an operator perform operation
	else
	{
		// Get the right operand stack

		int op1;
		op1 = stack.top();
		stack.pop();

		// Get the left operand stack
		int op2 = stack.top();
		stack.pop();

		int result = 0;
		// Performing operation
		if (c == '+')
			result = op2 + op1;
		else if (c == '-')
			result = op2 - op1;
		else if (c == '-')
			result = op2 * op1;
		else if (c == '/')
			result = op2 / op1;

		stack.push(result);
	}
	return stack.top();
}
*/
int prec(char input)
{
	// If input is /,*, or %, then return highest precedence
	if (input == '/' || input == '*' || input == '%')
	{
		return 2;
	}
	// If input is + or -, then return 1 for precendce
	else if (input == '+' || input == '-')
	{
		return 1;
	}
	// Otherwise, return lowest precedence
	else
		return -1;
}
