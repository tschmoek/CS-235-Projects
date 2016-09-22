#pragma once
#include "ExpressionManagerInterface.h"
#include <sstream>
class ExpressionManage :
	public ExpressionManagerInterface
{
protected:

public:
	ExpressionManage();
	~ExpressionManage();
	string IntToString(int pre);
	bool isNumber(string num);
	bool calcPrep(string op, int postconversion1,int postconversion2, int &result);
	int calc(string expression);
	string StringFlip(string reversed);
	int Presedence(string input);
	string addParenthesis(string op, string left, string right);
	bool BracketCheck(string check);
	bool OperatorCheck(string check);
	bool checkMatch(string punc, stack<string> &exstack);
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

};

