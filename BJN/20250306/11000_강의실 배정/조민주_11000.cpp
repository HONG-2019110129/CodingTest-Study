#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pair<int, int>> classes(N);
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        classes[i] = {start, end};
    }

    // 시작 시간 기준 오름차순 정렬
    sort(classes.begin(), classes.end());

    // 최소 힙 (수업이 끝나는 시간을 저장)
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(classes[0].second); // 첫 번째 강의의 종료 시간을 넣음

    for (int i = 1; i < N; i++) {
        int start = classes[i].first;
        int end = classes[i].second;

        // 가장 빨리 끝나는 수업보다 현재 수업이 늦게 시작하면 같은 강의실 사용 가능
        if (pq.top() <= start) {
            pq.pop();
        }

        // 새로운 종료 시간 추가
        pq.push(end);
    }

    cout << pq.size();
    return 0;
}
