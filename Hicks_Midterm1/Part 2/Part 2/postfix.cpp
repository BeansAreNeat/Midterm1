#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include "stack.h"
using namespace std;

/* Questions:
*		What does stack/input precedence mean??
*		
*/

bool isOperator(char input);
void postfix();

int main()
{
	char next;
	int i = 0; // For void push();
	Stack operandStack;

	cout << "Enter mathematical expression: " << endl;
	cin.get(next);

	// Postfix Expression Evaluation
	while (next != 'n/')
	{
		if (isdigit(next))
		{
			operandStack.push(i);
		}
		else if (isOperator(next))
		{
			// Get the right operand stack???
			operandStack.Top();
			operandStack.pop();
			// Then the left?

		}
	}

	return 0;
}

void postfix() {

}

bool isOperator(char input)
{
	if (input == '+' || input == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}