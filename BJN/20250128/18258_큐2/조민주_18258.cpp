#include<iostream>
#define ARRMAX 2000000
using namespace std;

int arr[2'000'000];  // N�� 1~2000000 ������ ���̹Ƿ� 2000000�� ũ�� �Ҵ�
int vf = 0, vb = 0;    //���� ť�� ��, �� ��ġ�� ǥ���ϴ� �ε���

void solution(string cmd);
void q_push(int x);
int q_pop();
int q_empty();
int q_size();
int q_front();
int q_back();

int main() {
    //����ȭ ��� �ӵ� ���
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    //��ɾ� �� �Է¹���
    int N;
    cin >> N;

    //N��ŭ ��ɾ� �Է¹ޱ�
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
    vb = (vb + 1) % ARRMAX;  // �迭�� ũ�⸦ �ʰ����� �ʵ��� ��ȯ
}

int q_pop() {
    if (q_empty()) return -1;
    int res = arr[vf];
    vf = (vf + 1) % ARRMAX;  // �� ������ �̵�
    return res;
}

int q_empty() {
    return vf == vb;  // front�� back�� ������ ��� ����
}

int q_size() {
    return (vb - vf + ARRMAX) % ARRMAX;  // ��ȯ ť ũ�� ���
}

int q_front() {
    if (q_empty()) return -1;
    return arr[vf];
}

int q_back() {
    if (q_empty()) return -1;
    return arr[(vb - 1 + ARRMAX) % ARRMAX];
}