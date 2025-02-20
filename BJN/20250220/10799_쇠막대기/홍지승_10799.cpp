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
            // ������ �϶��� ���� ������� ������ �߰�����
            if (str[i - 1] == '(') {
                st.pop();
                res += st.size();
            }
            // �������� �ƴϰ� ���밡 ���ΰ��� 1���߰�
            else {
                res += 1;
                st.pop();
            }
        }
    }
    cout << res;

    return 0;
}