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
    int value = 1;    // ��ȣ ���� ��
    int idx = 0;      // ���� ������ �ε���

    for (char ch : input) 
    {
        // '('�� ������ value�� 2 ��
        if (ch == '(') 
        {
            value *= 2;
            _stack.push(ch);        // '(' push
        }
        // '['�� ������ value�� 3 ��
        else if (ch == '[') 
        {
            value *= 3;
            _stack.push(ch);            // '[' push
        }
        else if (ch == ')') {
            // �� �ȵǴ� ���̽� 1. ���ۺ��� �ݴ°� 2. �ٷ� ���� ���ڰ� '(' �ƴѰ�
            if (_stack.empty() || _stack.top() != '(')
            {
                cout << 0;
                return 0;
            }
            
            // ¦�� �´� ���
            if (input[idx - 1] == '(')
            {
                result += value;
            }                
            _stack.pop();       // ���� ¦ ����
            value /= 2;         // () ��ȣ �� ����
        }
        else if (ch == ']') 
        {
            // �� �ȵǴ� ���̽� 1. ���ۺ��� �ݴ°� 2. �ٷ� ���� ���ڰ� '[' �ƴѰ�
            if (_stack.empty() || _stack.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (input[idx - 1] == '[')
            {
                result += value;
            }                
            _stack.pop();       // ���� ¦ ����
            value /= 3;         // () ��ȣ �� ����
        }
        ++idx;  // ���� ���ڷ� �̵�
    }

    // ¦ �� �ȸ´°�
    if (!_stack.empty()) 
    {
        cout << 0;
        return 0;
    }

    cout << result;

    return 0;
}