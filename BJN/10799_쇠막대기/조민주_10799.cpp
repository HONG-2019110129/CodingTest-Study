#include<iostream>
#include<stack>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    string str;
    cin >> str;

    stack<char> st;
    int res = 0;

    //주어진 정보를 탐색
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') { // '('면
            st.push('(');   //  푸시
        } 
        else {  ')'면
            st.pop(); // 가장 최근에 푸시된된 '(' 제거

            if (str[i - 1] == '(') { // 레이저일 경우
                res += st.size();
            } 
            else { // 쇠막대기 끝날 경우
                res += 1;
            }
        }
    }
    cout << res;
}
