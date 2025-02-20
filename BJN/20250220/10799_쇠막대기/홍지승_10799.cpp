#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

    int res = 0;
    string str;
    cin >> str;
    stack<char> st;

    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] == '(') {
            st.push('(');
        }
        else if (str[i] == ')') {
            // 레이져 일때는 현재 막대길이 개수를 추가해줌
            if (str[i - 1] == '(') {
                st.pop();
                res += st.size();
            }
            // 레이져가 아니고 막대가 끝인경우는 1만추가
            else {
                res += 1;
                st.pop();
            }
        }
    }
    cout << res;

    return 0;
}