#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	// 연한 회색: 벌이 있는 장소
	// 진한 회색: 벌통이 있는 장소
	// 벌통으로 날아가면서 지나가는 모든 칸에 꿀 수집
	// 칸에 있는 숫자는 꿀을 수집할 수 있는 양(벌통 포함)
	// 시작 장소는 불가

    int N;              // N개의 장소
    cin >> N;

    vector<long long>Honey(N);
    for (int i = 0;i < N;++i)
    {
        cin >> Honey[i];
    }

    long long totalHoney = 0;     // 전체 꿀 합

    for (int i = 0;i < N;++i)
    {
        totalHoney += Honey[i];
    }

    vector<long long>func(N + 1, 0);
    // for (int i = 0;i < N;++i)
    // {
    //     for (int j = 0;j <= i;++j)
    //     {
    //         func[i + 1] += Honey[i];
    //     }        
    // }
    for (int i = 0; i < N; ++i) 
    {
        func[i + 1] = func[i] + Honey[i];
    }

    long long max_honey = 0;

    //모두 벌통 왼쪽(벌통 오른쪽 맨 끝)
    //왼쪽 벌: (totalHoney - Honey[0] - Honey[i])
    //오른쪽 벌(i 위치): (totalHoney - (0 ~ i번 까지 벌꿀))
    for (int i = 1;i < N - 1; ++i)
    {
        long long tmp_honey = (totalHoney - Honey[0] - Honey[i]) + (totalHoney - func[i + 1]);
        max_honey = max(max_honey, tmp_honey);
    }

    //벌통 양옆
    //왼쪽 벌: (totalHoney - (0 ~ i까지의 벌꿀))
    //오른쪽 벌: (totalHoney - (0 ~ i 까지의 벌꿀) - (0 ~ 벌통 까지의 벌꿀))
    //근데 양 끝에 위치해야 최대임
    //근데 벌통 위치가 가장 큰 값인 곳으로 하면 2번 먹으니까 여기 해야함
    long long maxPositionHoney = 0;
    for(int i = 1; i < N - 1; ++i)
    {
        maxPositionHoney = max(maxPositionHoney, Honey[i]);
    }
    //int _tmp_honey = (func[i + 1] - Honey[0]) + (totalHoney - func[i + 1] + Honey[i] - Honey[N - 1]);
    long long _tmp_honey = (-Honey[0]) + (totalHoney + maxPositionHoney - Honey[N - 1]);
    max_honey = max(max_honey, _tmp_honey);

    //모두 벌통 오른쪽(벌통 맨 왼쪽)
    //왼쪽 벌(i 위치): (Honey[i])(0 ~ i번 까지 벌꿀)
    //오른쪽 벌: (totalHoney - Honey[N - 1] - Honey[i])
    for(int i = 1; i < N - 1; ++i)
    {
        long long tmp_honey = (totalHoney - Honey[N - 1] - Honey[i]) + (func[i]);
        max_honey = max(max_honey, tmp_honey);
    }

    cout << max_honey << "\n";

	return 0;
}