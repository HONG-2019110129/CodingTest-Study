#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// 정점 -> leaf 노드에 물 전달, 확률 똑


void bfs(int root, vector<vector<int>>& tree, vector<bool>& visited, vector<int>& water)
{
	queue<int>q;
	visited[root] = true;
	q.push(root);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : tree[cur])
		{
			if (!visited[nx])
			{
				visited[nx] = true;
				++water[cur];
				q.push(nx);
			}
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;		// 트리의 노드의 수
	long long W;		// 물의 양을 의미하는 정수

	cin >> N >> W;

	vector<vector<int>>tree(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> water(N + 1, 0);

	for (int i = 1; i < N; ++i)		// 간선 u, v 입력
	{
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	bfs(1, tree, visited, water);

	int leafNum = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (!water[i])
		{
			++leafNum;
		}
	}

	double P = (double)W / leafNum;
	//cout << P;
	cout << setprecision(10) << P;

	return 0;
}