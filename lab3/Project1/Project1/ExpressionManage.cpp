#include "ExpressionManage.h"


ExpressionManage::ExpressionManage()
{
}


ExpressionManage::~ExpressionManage()
{
}
bool ExpressionManage::checkMatch(string punc,stack<string>& exstack)
{
	if (exstack.size() >= 1)
	{
		if (punc == ")")
		{
			if (exstack.top() == "(")
				return true;
		}
		if (punc == "}")
		{
			if (exstack.top() == "{")
				return true;
		}
		if (punc == "]")
		{
			if (exstack.top() == "[")
				return true;
		}
		return false;
	}
	else
		return false;
}
bool ExpressionManage::BracketCheck(string check)
{
	
		if (check == "(" || check == "[" || check == "{" || check == ")" || check == "}" || check == "]")
		{
			return true;
		}
		return false;
	
}
bool ExpressionManage::OperatorCheck(string check)
{
	string input;
	istringstream iss(check);
	stringstream ss;
	int count = 0;
	while (iss >> input)
	{
		
		if (input == "+" || input == "-" || input == "/" || input == "%" || input == "*")
		{
			count--;
		}
		else if (BracketCheck(input) == false)
		{
			if (!isNumber(input))
			{
				return false;
			}
			else
			count++;
		}
		if (count < 0)
		{
			return false;
		}
	}
	if (count == 1)
	{
		return true;
	}
	else
		return false;
}
bool ExpressionManage::calcPrep(string op,int left,int right,int &result)
{
	if (op == "+")
	{
		result = left + right;
		return true;
	}
	else if (op == "-")
	{
		result = left - right;
		return true;
	}
	else if (op == "/"  && right != 0)
	{
		result = left / right;
		return true;
	}
	else if (op == "%" && right != 0)
	{
		result = left % right;
		return true;
	}
	else if (op == "*")
	{
		result = left * right;
		return true;
	}
	if (right == 0)
	{
		return false;
	}
}
string ExpressionManage::addParenthesis(string op, string right, string left)
{
	string result;
	if (op == "+")
	{
		result = "( " + left + " + " + right + " )";
	}
	else if (op == "-")
	{
		result = "( " + left + " - " + right + " )";
	}
	else if (op == "/")
	{
		result = "( " + left + " / " + right + " )";
	}
	else if (op == "%")
	{
		result = "( " + left + " % " + right + " )";
	}
	else if (op == "*")
	{
		result = "( " + left + " * " + right + " )";
	}
	return result;
}
string ExpressionManage::IntToString(int pre)
{
	stringstream ss;
	ss << pre;
	return ss.str();
}
int ExpressionManage::calc(string infixExpression)
{
	istringstream is(infixExpression);
	int exp;
	is >> exp;
	
	return exp;
}
int ExpressionManage::Presedence(string input)
{
		int a = 0;
		if (input == "*")
		{
			a = 2;
		}
		else if (input == "/")
		{
			a = 2;
		}
		else if (input == "%")
		{
			a = 2;
		}
		else if (input == "+")
		{
			a = 1;
		}
		else if (input == "-")
		{
			a = 1;
		}
		else if (input == ")")
		{
			a = 3;
		}
		else if (input == "]")
		{
			a = 3;
		}
		else if (input == "}")
		{
			a = 3;
		}
		else 
		{
			a = 0;
		}
		return a;
}
bool ExpressionManage::isNumber(string num)
{
    for(int i = 0; i < num.size(); i++)
    {
        if(!isdigit(num[i]))
        {
            return false;
        }
		
    }
	return true;

}


bool ExpressionManage::isBalanced(string expression)
{
	stack<string> exstack;

	string input;
	istringstream iss(expression);

	while (iss >> input)
	{
		if (input == "(" || input == "{" || input == "[")
		{
			exstack.push(input);
		}
		if (input == ")" || input == "}" || input == "]")
		{
			if (checkMatch(input, exstack)) {
				exstack.pop();
			} 
			else {
				return false;
			}
		}
	}
	if (!exstack.empty())
	{
		return false;
	}
	else
		return true;

}


string ExpressionManage::postfixToInfix(string postfixExpression)
{
	stack<string> stringstack;

	if (OperatorCheck(postfixExpression) == false)
	{
		return "invalid";
	}
	if (isBalanced(postfixExpression) == false)
	{
		return "invalid";
	}
	string input;
	string preconversion1;
	string preconversion2;
	int left = 0;
	int right = 0;
	int result = 0;
	string calculated;
	istringstream iss(postfixExpression);

	while (iss >> input)
	{
		
		if (input == "+" || input == "-" || input == "/" || input == "%" || input == "*")
		{
			if (stringstack.size() > 1)
			{

				preconversion1 = stringstack.top();
				stringstack.pop();
				preconversion2 = stringstack.top();
				stringstack.pop();
				calculated = addParenthesis(input, preconversion1, preconversion2);
				stringstack.push(calculated);
			}
		}
		else if (BracketCheck(input) == false)
		{
			if (isNumber(input) == false)
			{
				return "invalid";
			}
			stringstack.push(input);
		}
	}
	if (stringstack.size() == 1)
	{
		return calculated;
	}
	return "invalid";
}


string ExpressionManage::infixToPostfix(string infixExpression)
{
	stack<string> stringstack;

	if (OperatorCheck(infixExpression) == false)
	{
		return "invalid";
	}
	if (isBalanced(infixExpression) == false)
	{
		return "invalid";
	}
	string input;
	string calculated;
	int count = 0;
	int conversion = 0;
	int presedence = 0;
	int stackpres = 0;
	int length = 0;
	istringstream lss(infixExpression);
	while (lss >> input)
	{
		
		if (input == "+" || input == "-" || input == "/" || input == "%" || input == "*" || BracketCheck(input) == true)
		{
			presedence = Presedence(input);
			if (presedence == 0)
			{
				stringstack.push(input);
			}
			if (!stringstack.empty())
			{
				stackpres = Presedence(stringstack.top());
			}
			if (presedence == 3)
			{
				while (checkMatch(input, stringstack) == false && !stringstack.empty())
				{
					calculated += " " + stringstack.top();
					stringstack.pop();
				}
				if (checkMatch(input, stringstack) == true && !stringstack.empty())
				{
					stringstack.pop();
				}
			}
			while (stackpres >= presedence && !stringstack.empty() && presedence != 0)
			{
					calculated += " " + stringstack.top();
					stringstack.pop();
				
				if (!stringstack.empty())
				{
					stackpres = Presedence(stringstack.top());
				}
				else
				{
					stackpres = 0;
				}
			}
			if (presedence >= stackpres)
			{
				if (presedence == 1)
				{
					if (stackpres == 0 || stringstack.empty())
					{
						stringstack.push(input);
					}
				}
				else if (presedence == 2)
				{
					if (stringstack.empty() || presedence > stackpres)
					{
						stringstack.push(input);
					}
				}
			}
		}
		else if (BracketCheck(input) == false)
		{
			if (isNumber(input) == false)
			{
				return "invalid";
			}
			if (calculated.empty())
			{
				calculated = input;
			}
			else
			{
				calculated += " " + input;
			}
			
		}
		count++;
	}
	while (!stringstack.empty())
	{
		calculated += " " + stringstack.top();
		stringstack.pop();
	}
	return calculated;
}

string ExpressionManage::postfixEvaluate(string postfixExpression)
{
	stack<string> stringstack;
	
	if (OperatorCheck(postfixExpression) == false)
	{
		return "invalid";
	}
	if (isBalanced(postfixExpression) == false)
	{
		return "invalid";
	}
	string input;
	string preconversion1;
	string preconversion2;
	int left = 0;
	int right = 0;
	int result = 0;
	int cnt = 0;
	string calculated;
	istringstream lss(postfixExpression);
	input = "";
	while (lss >> input)
	{
		cnt++;
		if (input == "+" || input == "-" || input == "/" || input == "%" || input == "*")
		{
		
			if (stringstack.size() >= 1)
			{
				preconversion1 = stringstack.top();
				stringstack.pop();
				preconversion2 = stringstack.top();
				stringstack.pop();
				right = stoi(preconversion1);
				left = stoi(preconversion2);
				if (calcPrep(input, left, right, result) == false)
				{
					return "invalid";
				}
				stringstack.push(IntToString(result));
			}
		}
		else if (BracketCheck(input) == false)
		{
			stringstack.push(input);
		}
	}
		if (stringstack.size() == 1)
		{
			calculated = stringstack.top();
			return calculated;
		}
		else
		{
			return "invalid";
		}

}


