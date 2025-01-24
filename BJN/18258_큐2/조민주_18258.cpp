#include<iostream>
#define ARRMAX 2000000
using namespace std;

int arr[2'000'000];  // N이 1~2000000 사이의 값이므로 2000000의 크기 할당
int vf = 0, vb = 0;    //각자 큐의 앞, 뒤 위치를 표시하는 인덱스

void solution(string cmd);
void q_push(int x);
int q_pop();
int q_empty();
int q_size();
int q_front();
int q_back();

int main() {
    //동기화 끊어서 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    //명령어 수 입력받음
    int N;
    cin >> N;

    //N만큼 명령어 입력받기
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        solution(cmd);
    }
}

void solution(string cmd) {
    if (cmd == "push") {
        int x;
        cin >> x;
        q_push(x);
    }
    else if (cmd == "pop") cout << q_pop() << '\n';
    else if (cmd == "size") cout << q_size() << '\n';
    else if (cmd == "empty") cout << q_empty() << '\n';
    else if (cmd == "front") cout << q_front() << '\n';
    else if (cmd == "back") cout << q_back() << '\n';
}

void q_push(int x) {
    arr[vb] = x;
    vb = (vb + 1) % ARRMAX;  // 배열의 크기를 초과하지 않도록 순환
}

int q_pop() {
    if (q_empty()) return -1;
    int res = arr[vf];
    vf = (vf + 1) % ARRMAX;  // 앞 포인터 이동
    return res;
}

int q_empty() {
    return vf == vb;  // front와 back이 같으면 비어 있음
}

int q_size() {
    return (vb - vf + ARRMAX) % ARRMAX;  // 순환 큐 크기 계산
}

int q_front() {
    if (q_empty()) return -1;
    return arr[vf];
}

int q_back() {
    if (q_empty()) return -1;
    return arr[(vb - 1 + ARRMAX) % ARRMAX];
}