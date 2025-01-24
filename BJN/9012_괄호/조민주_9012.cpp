#include<iostream>
#include<queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;    // �տ��� ���� �ڿ� �����ϱ� ť
    for (int i = 1; i <= N; i++) {    // ť�� 1~N������ ������� push
        q.push(i);
    }

    while (q.size() > 1) {    // ť�� ���Ұ� �ϳ� ���� ������
        q.pop();    //�� �� ���� ����
        int qf = q.front();    // �� ���� ���Ҹ� ���� �ڷκ����� �ݺ�
        q.pop();
        q.push(qf);
    }
    cout << q.front();    // �� �ϳ� ���� ���� ���
}