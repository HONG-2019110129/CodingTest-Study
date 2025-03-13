#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int cnt;
    cin >> cnt;
    vector<pair<int, int>> arr;
    for (int i = 0; i < cnt; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({ s, e });
    }
    sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {   
        if (a.second == b.second) {
            return a.first > b.first;
        } 
        return a.second < b.second;
    });
    int end_time = 0;
    int meeting_cnt = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i].second > end_time)
        {
            if (arr[i].first >= end_time)
            {
                meeting_cnt++;
                end_time = arr[i].second;
            }
        }
    }
    cout << meeting_cnt << "\n";
    return 0;
}