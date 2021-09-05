#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperand(char x)
{
return (x >= 'a' && x <= 'z') ||
		(x >= 'A' && x <= 'Z')||
  		(x >= '0' && x <= '9');
}

string postToInfix(string exp)
{
	stack<string> s;
	for (char i:exp)
	{
		// Push operands
		if (isOperand(i))
		{
			string op(1, i);
			s.push(op);
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push("(" + op2 + i +
				op1 + ")");
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

int calcInfix(string exp)
{
	stack<int> s;
	for (char i:exp)
	{
		// Push operands
		if (isOperand(i))
		{
			s.push(i-'0');
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			int op1=s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			if(i=='+')
				s.push(op1+op2);
			if(i=='*')
				s.push(op1*op2);
			if(i=='-')
				s.push(op2-op1);
			if(i=='/')
				s.push(op2/op1);
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

string preToInfix(string exp)
{
	stack<string> s;
	for (char i:exp)
	{
		// Push operands
		if (isOperand(i))
		{
			string op(1, i);
			s.push(op);
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push("(" + op1 + i +
				op2 + ")");
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

int calcPrefix(string exp)
{
	stack<int> s;
	for (char i:exp)
	{
		// Push operands
		if (isOperand(i))
		{
			s.push(i-'0');
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			int op1=s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			if(i=='+')
				s.push(op1+op2);
			if(i=='*')
				s.push(op1*op2);
			if(i=='-')
				s.push(op1-op2);
			if(i=='/')
				s.push(op1/op2);
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

//Actual todo: infix to prefix
//Todo: prefix to postfix and vice versa

int main()
{
	//string exp = "ab/cd%∗ef−+ ";
	//string exp = "ab/cd%*ef-+";
	string exp = "+-a*bc--de+fg";
	//+−a∗bc−−de+fg
	// cout << getPrefix(exp)<<endl;
	// cout << calcPrefix(exp);
	reverse(exp.begin(),exp.end());
	cout << preToInfix(exp)<<endl;
	// cout << calcPrefix(exp);
	return 0;
}