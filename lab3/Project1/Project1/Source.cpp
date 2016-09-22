#include "Factory.h"
#include "ExpressionManagerInterface.h"
#include "ExpressionManage.h"


using namespace std;

int main()
{
	string exp = "40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %";
	string exp1 = "}";
	string exp2 = "4 5 2 + * 2 /";
	string exp3 = "1 2 * 3 - 2 * 5 +";
	string exp4 = "40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6";
	string exp5 = "1 + ( 2 * 3 - 1 ) - 2";
	string exp6 = "} 78 97 + 6 / 5 +";
	string exp7 = "100 50 6 10 - 10 * / /";

	ExpressionManage test;
	/*cout << test.isBalanced(exp1) << endl;*/
	
	/*cout << test.postfixEvaluate(exp7);
	cout << endl;*/
	/*cout << test.postfixToInfix(exp);
	cout << endl;*/
	/*cout << test.postfixToInfix(exp4);
	cout << endl;*/
	cout << test.postfixEvaluate("34 90 / 4 - 65 3 * /");
	cout << endl;
	//cout << test.infixToPostfix(exp4);
	//cout << endl;

	
	system("pause");
	return 0;
}