#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

stack<int> stck;
unordered_map<string, int> m;    // 명령어를 숫자로 처리해줄 map(switch문으로 코드 작성하기 위함)

void init();    // map 초기화 함수

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string cmd;    // 명령어 개수
    init();
    while (n--) {
        cin >> cmd;
        switch (m[cmd]) {
        case 1:    //push
            int x;    // 정수 입력받고
            cin >> x;
            stck.push(x);    // 정수를 스택에 푸쉬
            break;
        case 2:    // pop
            if (!stck.empty()) {    // 스택이 비어있지 않을 때
                cout << stck.top() << '\n';    // 스택 가장 윗부분 요소를 출력후
                stck.pop();// 해당 요소 팝
            }
            else {    //스택이 비어있으면
                cout << "-1\n";    // -1 출력
            }
            break;
        case 3:    // size
            cout << stck.size() << '\n';    // 스택 요소 개수 출력
            break;
        case 4:    //empty
            if (!stck.empty()) cout << "0\n";    // 스택이 비어있지 않으면 0
            else cout << "1\n";    // 스택이 비어있으면 1
            break;
        case 5:    //top
            if (!stck.empty()) cout << stck.top() << "\n";    // 스택 가장 윗부분 요소 출력
            else cout << "-1\n";    // 비어있는 스택일 경우 -1 출력
            break;
        }

    }
    return 0;
}

void init() {
    m.insert(make_pair("push", 1));
    m.insert(make_pair("pop", 2));
    m.insert(make_pair("size", 3));
    m.insert(make_pair("empty", 4));
    m.insert(make_pair("top", 5));
}