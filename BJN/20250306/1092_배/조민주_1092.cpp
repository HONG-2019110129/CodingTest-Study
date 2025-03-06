#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    
    vector<int> cranes(N);
    for (int i = 0; i < N; i++) {
        cin >> cranes[i];
    }
    
    cin >> M;
    vector<int> boxes(M);
    for (int i = 0; i < M; i++) {
        cin >> boxes[i];
    }

    // 내림차순 정렬 (큰 크레인이 먼저 배정받음)
    sort(cranes.rbegin(), cranes.rend());
    sort(boxes.rbegin(), boxes.rend());

    // 불가능한 경우 확인
    if (boxes[0] > cranes[0]) {
        cout << -1;
        return 0;
    }

    int time = 0;
    while (!boxes.empty()) {
        int idx = 0;  // 크레인 인덱스
        for (int i = 0; i < N;) {
            if (idx >= boxes.size()) break;  // 더 이상 남은 박스가 없으면 종료
            if (cranes[i] >= boxes[idx]) {   // 크레인이 박스를 옮길 수 있으면
                boxes.erase(boxes.begin() + idx);
                i++;  // 다음 크레인으로 이동
            } else {
                idx++;  // 현재 크레인이 못 들면 다음 박스를 확인
            }
        }
        time++;
    }

    cout << time;
    return 0;
}
