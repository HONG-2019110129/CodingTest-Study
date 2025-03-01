#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, W;
	cin >> N >> W;

	vector<vector<int>> adj(N + 1); // 인접 리스트
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// BFS
	queue<int> q;
	vector<bool> visited(N + 1, false);
	int leafCount = 0;

	q.push(1); // 루트 노드부터 시작
	visited[1] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		bool isLeaf = true;
		for (int neighbor : adj[current]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
				isLeaf = false;
			}
		}

		if (isLeaf && current != 1) { 
			leafCount++;
		}
	}

	// 리프 노드가 없는 경우 (트리가 루트 노드만 있는 경우)
	if (leafCount == 0) {
		cout << W << "\n";
	}
	else {
		cout.precision(10); // 소수점 10자리까지 출력
		cout << fixed << (double)W / leafCount << "\n";
	}

	return 0;
}