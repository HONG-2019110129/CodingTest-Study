#include <iostream>
#include <vector>

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
	vector<vector<int>> players(N+1, 0);	// (1~N번)
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			cin >> players[i][j];
		}
	}

	return 0;
}