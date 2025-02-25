#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	// tree root = 1
	// node 개수 N
	// 1번 node 부터 시작

	int N;		// node 개수
	cin >> N;

	vector<vector<int>>tree(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int u, v;
		cin >> u >> v;

		// tree 선 이어주기
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector<int>parentNode(N + 1);			// 부모 노드 저장 벡터
	vector<bool>Visited(N + 1, false);		// 방문 여부
	queue<int>q;

	q.push(1);		// root 노드부터 시작
	Visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : tree[cur])
		{
			if (!Visited[next])
			{
				Visited[next] = true;
				parentNode[next] = cur;
				q.push(next);
			}
		}
	}
	
	// 부모 노드 번호 출력
	for (int i = 2; i <= N; ++i)
	{
		cout << parentNode[i] << "\n";
	}

	return 0;
}