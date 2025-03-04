#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// ���� -> leaf ��忡 �� ����, Ȯ�� ��


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

	int N;		// Ʈ���� ����� ��
	long long W;		// ���� ���� �ǹ��ϴ� ����

	cin >> N >> W;

	vector<vector<int>>tree(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> water(N + 1, 0);

	for (int i = 1; i < N; ++i)		// ���� u, v �Է�
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