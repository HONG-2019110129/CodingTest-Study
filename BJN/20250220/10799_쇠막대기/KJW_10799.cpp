#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	int result = 0;
	stack<char>_stack;
	int idx = 0;
	for (auto c : input)
	{		
		if (c == '(')
		{
			_stack.push(c);
		}
		else
		{
			_stack.pop();
			if (input[idx - 1] == '(')		// 레이저 조건문
			{
				result += _stack.size();
			}
			else
			{
				++result;
			}
		}
		++idx;
	}

	cout << result << "\n";

	return 0;
}