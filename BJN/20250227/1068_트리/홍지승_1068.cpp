#define MAX 51
#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> adj[MAX];
bool visited[MAX];
set<int> deletedNode;

// dfs를 돌면서 그 노드에서 부터 자식노드를 deleteNode 벡터에 저장함
void dfs(int node) {
	deletedNode.insert(node);
	visited[node] = true;
	for (auto itr : adj[node]) {
		if (!visited[itr]) { // 방문한 적이 없을 때
			visited[itr] = true;
			dfs(itr);
		}
	}
}
// 전체 노드의 개수를 받음
int count_leaf_node(int N) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (deletedNode.count(i) > 0) continue; // 삭제된 노드는 무시

		bool isLeaf = true;
		for (int child : adj[i]) {
			if (deletedNode.count(child) == 0) {  // 삭제되지 않은 자식이 하나라도 있으면 리프가 아님
				isLeaf = false;
				break;
			}
		}
		if (isLeaf) result++;
	}
	return result;
}

int main(void) {

	int N;
	int parent;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1) {
			continue;
		}
		adj[parent].push_back(i); //0번 리스트부터 시작하여 인접리스트를 만들어줌
	}
	int M;
	cin >> M;
	dfs(M);
	int result = count_leaf_node(N);

	cout << result;

	return 0;

}