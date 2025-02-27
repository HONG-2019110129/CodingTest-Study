#define MAX 51
#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> adj[MAX];
bool visited[MAX];
set<int> deletedNode;

// dfs�� ���鼭 �� ��忡�� ���� �ڽĳ�带 deleteNode ���Ϳ� ������
void dfs(int node) {
	deletedNode.insert(node);
	visited[node] = true;
	for (auto itr : adj[node]) {
		if (!visited[itr]) { // �湮�� ���� ���� ��
			visited[itr] = true;
			dfs(itr);
		}
	}
}
// ��ü ����� ������ ����
int count_leaf_node(int N) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (deletedNode.count(i) > 0) continue; // ������ ���� ����

		bool isLeaf = true;
		for (int child : adj[i]) {
			if (deletedNode.count(child) == 0) {  // �������� ���� �ڽ��� �ϳ��� ������ ������ �ƴ�
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
		adj[parent].push_back(i); //0�� ����Ʈ���� �����Ͽ� ��������Ʈ�� �������
	}
	int M;
	cin >> M;
	dfs(M);
	int result = count_leaf_node(N);

	cout << result;

	return 0;

}