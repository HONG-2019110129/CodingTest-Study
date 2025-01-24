#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q; // n���� ����� ����
    for (int i = 1; i <= n; i++) {    // 1~n���� ��ȣ ����
        q.push(i);
    }

    cout << "<";
    while (q.size() > 1) {    // ť�� �� ����� ���� ������ �ݺ�
        for (int i = 0; i < k - 1; i++) {    // ���� �ջ���� �ڷ� ������ k-1�� �ݺ�
            int qf = q.front();
            q.pop();
            q.push(qf);
        }
        cout << q.front() << ", ";    // ���� ���� �տ� �ִ� ����� �����
        q.pop();    // ť���� ����
    }
    //������ �� ���� ���ŵ��� ���� ����� �� �Ѹ� ������ �� ó��
    cout << q.front() << ">";    // �� ����� ��ȣ ��� ��
    q.pop();    // ���� ���ŵ��� ���� ������� ��� ����
}