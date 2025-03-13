#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    vector<pair<int, int>> arr;
    for (int i = 0; i < cnt; i++) {
        int s, e;
        cin >> s >> e;
        arr.push_back({ s, e });
    }

    // 정렬: 종료 시간이 빠른 순서, 같다면 시작 시간이 빠른 순서
    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {   
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int end_time = 0;
    int meeting_cnt = 0;

    for (int i = 0; i < cnt; i++) {
        if (arr[i].first >= end_time) {  // 다음 회의의 시작 시간이 현재 종료 시간 이후라면 선택 가능
            meeting_cnt++;
            end_time = arr[i].second;
        }
    }

    cout << meeting_cnt << "\n";
    return 0;
}
