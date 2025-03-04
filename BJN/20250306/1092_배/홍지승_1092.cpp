#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
multiset<int> boxList;

void move_closest_box(int weight)
{

    for (auto itr = boxList.begin(); itr != boxList.end(); itr++)
    {
        if (itr == boxList.begin())
        {
            if (*itr > weight)
            {
                return; // 무게 제한에 맞는 박스가 없음
            }
        }
        else
        {
            if (*itr > weight)
            {
                boxList.erase(prev(itr));
                return;
            }
        }
    }
    boxList.erase(prev(boxList.end()));
    // auto itr = boxList.upper_bound(weight);
    // if (itr == boxList.begin()) return; // 무게 제한에 맞는 박스가 없음
    // boxList.erase(prev(itr)); // 가장 적절한 박스 제거
}

int main()
{
    int N, M, weight;
    int max_crain = -1;
    int max_box = -1;

    vector<int> crain;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> weight;
        max_crain = max(max_crain, weight);
        crain.push_back(weight);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> weight;
        max_box = max(max_box, weight);
        boxList.insert(weight);
    }

    // 박스를 옮길 수 없는 경우
    if (max_crain < max_box)
    {
        cout << "-1";
        return 0;
    }

    // 크레인 무게 제한 내림차순 정렬
    sort(crain.rbegin(), crain.rend());

    int result = 0;
    while (!boxList.empty())
    {
        for (int i = 0; i < N; i++)
        {
            if (boxList.empty())
                break; // 더 이상 처리할 박스가 없으면 종료
            move_closest_box(crain[i]);
        }
        result++;
    }

    cout << result;
    return 0;
}
