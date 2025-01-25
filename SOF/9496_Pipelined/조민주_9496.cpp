#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    // �Է�
    int N;
    cin >> N;
    vector<int> stages(N);
    for (int i = 0; i < N; ++i) {
        cin >> stages[i];
    }

    // ���� �ܰ� ���� ������������ ����
    sort(stages.begin(), stages.end());

    // �켱���� ť (�ּ� ��) ����Ͽ� ���� �۾� ������ �� ��ġ�� ����
    priority_queue<int, vector<int>, greater<int>> pq;

    // �ùķ��̼� ����
    int time = 0;
    for (int s : stages) {
        // �۾� ���Կ��� ���� �ռ� �� ��ġ�� Ȯ��
        if (!pq.empty() && pq.top() <= time) {
            // ���� ���Կ��� �۾��� ���� ��� ���� ����
            pq.pop();
        }

        // ���ο� ���� ���μ����� ���Կ� �߰�
        pq.push(time + s);

        // �ð� ������Ʈ
        time++;
    }

    // ��� �۾� ������ ����� �������� ���� �ð� ���
    while (!pq.empty()) {
        time = max(time, pq.top());
        pq.pop();
    }

    // ���
    cout << time << endl;
    return 0;
}
