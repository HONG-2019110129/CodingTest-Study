#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	//	축구 하려고 모인 사람 N명 (1번 ~ N번)
	//	스타트 팀 vs 링크 팀
	//	각 팀 인원 수는 같지 않아도 되지만 1명 이상이어야 함
	//	능력치 S_ij: i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치
	//	팀 틍력치 = 팀에 속한 모든 쌍의 능력치 S_ij의 합
	//	S_ij 는 S_ji와 다를 수 있음
	//	i번 사람과 j번 사람이 같은 팀에 속해있을 때, 팀에 더해지는 능력치: S_ij, S_ji

	//	목표: 스타트 팀과 링크 팀 능력치 차이 최소화

	int N;	// 총 인원
	cin >> N;
	vector<vector<int>> players(N + 1, vector<int>(N + 1, 0));	// (1~N번)
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			cin >> players[i][j];
		}
	}

	int start_team_value = 0;
	int link_team_value = 0;
	// 조합
	// 4명 -> (1, 2) (1, 3) (1, 4) (2, 1) (2, 3) (2, 4) (3, 1) (3, 2) (3, 4) (4, 1) (4, 2) (4, 3) 12
	// 5명 -> 5, 1|5, 2|5, 3| N * (N-1) 경우의 수
	
	// 인당 선택할 수 있는 팀: 2가지
	// N명 => 2^N
	// 근데 모두 한쪽을 선택할 경우: 2가지
	// 총 경우의 수 2^N -2

	int totalCase = 1 << N;
	for (int _case = 0; _case < totalCase; ++_case)
	{
		int startTeam = 0;
		int linkTeam = 0;

		if(_case&1)

		if(_case == )

		for (int i = 1; i <= N; ++i)
		{
			for (int j = i + 1; j <= N; ++j)
			{
				bool A = _case & (1 << (i - 1));
				bool B = _case & (1 << (j - 1));


			}
		}
	}


	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			cout << players[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}