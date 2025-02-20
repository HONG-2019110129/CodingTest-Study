#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> tower(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> tower[i];
	}

	vector<int>result(N, 0);
	stack<int>big;
	for (int i = 0; i < N; ++i)
	{
		// 현재 탑 vs 이전 탑
		while (!big.empty() && tower[big.top()] < tower[i])	// 현재 탑이 더 큼
		{
			big.pop();
		}
		// => 나와 가장 가까운 곳의 타워 번호가 최상단

		
		if (big.empty())	// 비어있다 = 모두 나보다 작았따
		{
			result[i] = 0;
		}
		else				// 뭔가 들어있다 = 나보다 큰게 있었다 = 카운트 증가
		{
			result[i] = big.top() + 1;
		}

		big.push(i);
	}

	for (int i = 0; i < N; ++i) 
	{
		cout << result[i] << " ";
	}

	return 0;
}