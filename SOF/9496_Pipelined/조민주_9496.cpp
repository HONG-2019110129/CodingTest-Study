#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    // 입력
    int N;
    cin >> N;
    vector<int> stages(N);
    for (int i = 0; i < N; ++i) {
        cin >> stages[i];
    }

    // 생산 단계 수를 오름차순으로 정렬
    sort(stages.begin(), stages.end());

    // 우선순위 큐 (최소 힙) 사용하여 현재 작업 슬롯의 끝 위치를 관리
    priority_queue<int, vector<int>, greater<int>> pq;

    // 시뮬레이션 진행
    int time = 0;
    for (int s : stages) {
        // 작업 슬롯에서 가장 앞선 끝 위치를 확인
        if (!pq.empty() && pq.top() <= time) {
            // 기존 슬롯에서 작업이 끝난 경우 슬롯 갱신
            pq.pop();
        }

        // 새로운 생산 프로세스를 슬롯에 추가
        pq.push(time + s);

        // 시간 업데이트
        time++;
    }

    // 모든 작업 슬롯이 비워질 때까지의 최종 시간 계산
    while (!pq.empty()) {
        time = max(time, pq.top());
        pq.pop();
    }

    // 출력
    cout << time << endl;
    return 0;
}
