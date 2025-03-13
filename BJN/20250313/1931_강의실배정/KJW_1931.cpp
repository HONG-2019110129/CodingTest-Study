#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;		// 회의 개수
	cin >> N;

	vector<pair<int, int>>conference(N);	// <startTime, endTime>
	for (int i = 0; i < N; ++i)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		conference[i] = { startTime, endTime };
	}

    sort(conference.begin(), conference.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
        });

    int cnt = 0;
    int prev_end_time = 0;
    for (int i = 0; i < N; i++) 
    {
        // 현재 회의의 시작 시간이 마지막 회의의 종료 시간보다 크거나 같으면 선택
        if (conference[i].first >= prev_end_time) 
        {
            ++cnt;
            prev_end_time = conference[i].second;
        }
    }

    cout << cnt << "\n";

	return 0;
}