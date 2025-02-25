#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	// tree root = 1
	// node ���� N
	// 1�� node ���� ����

	int N;		// node ����
	cin >> N;

	vector<vector<int>>tree(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int u, v;
		cin >> u >> v;

		// tree �� �̾��ֱ�
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector<int>parentNode(N + 1);			// �θ� ��� ���� ����
	vector<bool>Visited(N + 1, false);		// �湮 ����
	queue<int>q;

	q.push(1);		// root ������ ����
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
	
	// �θ� ��� ��ȣ ���
	for (int i = 2; i <= N; ++i)
	{
		cout << parentNode[i] << "\n";
	}

	return 0;
}