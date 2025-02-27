#define MAX 100001
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <queue>

using namespace std;
vector<int> adj[MAX];
bool visited[MAX];
int result[MAX];


void dfs(int node, int parent) {
	result[node] = parent; // parent 값 저장
	visited[node] = 1;
	for (int i = 0; i < adj[node].size(); i++) {
		if (visited[adj[node][i]] != 1) {
			dfs(adj[node][i], node);
		}
	}
}
void bfs(int start) {
	queue<int> que;
	que.push(start);
	visited[start] = 1;

	while (!que.empty()) {
		int next_node = que.front();
		que.pop();

		// 인접한 노드 탐색
		for (int itr : adj[next_node]) {
			if (visited[itr] == 0) {
				visited[itr] = 1;
				result[itr] = next_node;
				que.push(itr);
			}
		}
	}
}

void print_result(int N) {
	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}
}

int main(void) {

	int N;
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
	print_result(N);

	return 0;
}
