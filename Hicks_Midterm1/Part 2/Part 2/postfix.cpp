#include <iostream>
#include "stack.h"
#include <string>
using namespace std;
/*
	Citations:
	https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
	https://www.geeksforgeeks.org/stack-a-4-evaluation-postfix-expression/
	https://www.geeksforgeeks.org/c-program-to-convert-string-to-integer/
	https://gist.github.com/mycodeschool/7702441
*/

/* Questions:
		What does stack/input precedence mean??
		How to properly cite code
		Clarify instructions
*/

// Postfix Expression Evaluation
int postfix(char input);
// Converts
void convert(char input);
// Finds operator precendce (Modified code from geeksforgeeks.org)
int prec(char input);

int main()
{
	// Equation
	string equ;

	cout << "Enter mathematical expression: " << endl;
	getline(cin, equ);
		
	for (int i = 0; i < equ.length(); i++)	// For as long as the string. from geeksforgeeks.org
	{
		convert(equ[i]);
	}

	return 0;
}

void convert(char input)
{
	Stack stack;
	string output;

	if (isdigit(input))
	{
		output += input; // Add numbers to the output

		// While stack prec >= input's
		while (prec(stack.top()) >= prec(input))
		{
			output += stack.top(); // Readying the output
			stack.pop();		   // Poping the stack
		}
		stack.push(input);			// Pushing input onto the stack
	}

	// While the top isn't a left parentheses
	while (stack.top() != '(')
	{
		output += stack.top();	// Add the top of the stack to output
		stack.pop();			// Pop the stack
	}
	cout << output << endl;
}

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
