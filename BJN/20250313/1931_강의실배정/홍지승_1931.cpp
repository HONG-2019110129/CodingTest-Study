#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
// 나의 착각 multimap 에서는 key값이 같은 놈에대해 value를 자동 정렬 해주지 않음
// 그래서 vector<int,int>를 이용해서 정렬이 필요하다

bool second_ascend(pair<int, int>& a, pair<int, int>& b) {
    return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}

int main(void) {
    int N;
    int start, end;
    int result = 0;
    int last_end_time = 0;

    cin >> N;
    vector<pair<int, int>> plan;

    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        plan.push_back({start, end});
    }
    sort(plan.begin(), plan.end(),second_ascend);
    
    //for (auto itr = plan.begin();itr != plan.end();itr++) {
    //    cout << (*itr).first << "," << (*itr).second << "\n";
    //}

    for (auto itr = plan.begin(); itr != plan.end(); ++itr) {

        if (itr->first >= last_end_time) {
            result++;
            last_end_time = itr->second;
        }
    }

    cout << result;

    return 0;
}
