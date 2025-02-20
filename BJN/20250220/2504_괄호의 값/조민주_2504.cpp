#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculateValue(const string &s) {
    stack<char> stk;
    stack<int> valStack;
    int temp = 1, result = 0;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(') {
            stk.push(ch);
            temp *= 2;
        } else if (ch == '[') {
            stk.push(ch);
            temp *= 3;
        } else if (ch == ')') {
            if (stk.empty() || stk.top() != '(') return 0; // 올바르지 않은 경우
            if (s[i - 1] == '(') result += temp; // 바로 이전이 '('면 temp를 더함
            stk.pop();
            temp /= 2;
        } else if (ch == ']') {
            if (stk.empty() || stk.top() != '[') return 0; // 올바르지 않은 경우
            if (s[i - 1] == '[') result += temp; // 바로 이전이 '['면 temp를 더함
            stk.pop();
            temp /= 3;
        }
    }

    return stk.empty() ? result : 0; // 스택이 비어 있어야 올바른 괄호 문자열
}

int main() {
    string s;
    cin >> s;

    cout << calculateValue(s) << endl;
    return 0;
}
