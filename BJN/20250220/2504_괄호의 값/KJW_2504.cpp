// ( ) [ ] : +
// ( ) : 2
// [ ] : 3

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    stack<char> _stack;
    int result = 0;
    int value = 1;    // 괄호 내부 값
    int idx = 0;      // 현재 문자의 인덱스

    for (char ch : input) 
    {
        // '('를 만나면 value에 2 곱
        if (ch == '(') 
        {
            value *= 2;
            _stack.push(ch);        // '(' push
        }
        // '['를 만나면 value에 3 곱
        else if (ch == '[') 
        {
            value *= 3;
            _stack.push(ch);            // '[' push
        }
        else if (ch == ')') {
            // 말 안되는 케이스 1. 시작부터 닫는거 2. 바로 이전 문자가 '(' 아닌거
            if (_stack.empty() || _stack.top() != '(')
            {
                cout << 0;
                return 0;
            }
            
            // 짝꿍 맞는 경우
            if (input[idx - 1] == '(')
            {
                result += value;
            }                
            _stack.pop();       // 맞춘 짝 제거
            value /= 2;         // () 괄호 값 제거
        }
        else if (ch == ']') 
        {
            // 말 안되는 케이스 1. 시작부터 닫는거 2. 바로 이전 문자가 '[' 아닌거
            if (_stack.empty() || _stack.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (input[idx - 1] == '[')
            {
                result += value;
            }                
            _stack.pop();       // 맞춘 짝 제거
            value /= 3;         // () 괄호 값 제거
        }
        ++idx;  // 다음 문자로 이동
    }

    // 짝 수 안맞는거
    if (!_stack.empty()) 
    {
        cout << 0;
        return 0;
    }

    cout << result;

    return 0;
}