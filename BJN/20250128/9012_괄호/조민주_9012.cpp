#include<iostream>
#include<queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;    // 앞에서 빼고 뒤에 넣으니까 큐
    for (int i = 1; i <= N; i++) {    // 큐에 1~N까지를 순서대로 push
        q.push(i);
    }

    while (q.size() > 1) {    // 큐에 원소가 하나 남을 때까지
        q.pop();    //맨 앞 원소 빼고
        int qf = q.front();    // 그 다음 원소를 빼서 뒤로보내기 반복
        q.pop();
        q.push(qf);
    }
    cout << q.front();    // 단 하나 남은 원소 출력
}