#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    stack<char> st;
    int temp = 1, result = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == '(') {
            st.push(c);
            temp *= 2;
        }
        else if (c == '[') {
            st.push(c);
            temp *= 3;
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0 << endl;
                return 0;
            }
            if (input[i - 1] == '(') result += temp;
            st.pop();
            temp /= 2;
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0 << endl;
                return 0;
            }
            if (input[i - 1] == '[') result += temp;
            st.pop();
            temp /= 3;
        }
    }

    cout << (st.empty() ? result : 0) << endl;
    return 0;
}
