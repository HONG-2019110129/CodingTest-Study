#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q; // n명의 사람들 집합
    for (int i = 1; i <= n; i++) {    // 1~n까지 번호 삽입
        q.push(i);
    }

    cout << "<";
    while (q.size() > 1) {    // 큐에 한 사람만 남을 때까지 반복
        for (int i = 0; i < k - 1; i++) {    // 제일 앞사람을 뒤로 보내길 k-1번 반복
            int qf = q.front();
            q.pop();
            q.push(qf);
        }
        cout << q.front() << ", ";    // 현재 제일 앞에 있는 사람을 출력후
        q.pop();    // 큐에서 제거
    }
    //루프를 다 돌고 제거되지 않은 사람이 단 한명 남았을 때 처리
    cout << q.front() << ">";    // 그 사람의 번호 출력 후
    q.pop();    // 아직 제거되지 않은 사람까지 모두 제거
}