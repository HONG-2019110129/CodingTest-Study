#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* 풀이법
   1. 입력값을 벡터에 저장한다.
   2. 맨 처음 값이 부모이고, 부모보다 작은 그룹과 큰 그룹을 나눈다.
   3. 각 그룹에서 가장 먼저 나오는 값이 그 그룹의 부모가 된다.
   4. 그룹이 0개가 될 때까지 재귀로 반복하여 트리를 구성한다.
   5. 구성한 트리를 **후위 순회로 출력**한다.
*/

map<int,vector<int>> adj; 

// 이진 탐색 트리를 구성하는 함수
void make_tree(vector<int>& inputlist, int parent) {
	int minparent = -1, maxparent = -1;
	vector<int> min_list, max_list;

	// 입력 리스트를 순회하며 작은 그룹과 큰 그룹을 나눔
	for (auto itr : inputlist) {
		if (itr < parent) {  // 부모보다 작은 값
			if (minparent == -1) {
				minparent = itr;
			}
			else {
				min_list.push_back(itr);
			}
		}
		else {  // 부모보다 큰 값
			if (maxparent == -1) {
				maxparent = itr;
			}
			else {
				max_list.push_back(itr);
			}
		}
	}

	// 부모 노드의 자식 노드 저장 (유효한 값만 추가)
	if (minparent != -1) {
		adj[parent].push_back(minparent);
		make_tree(min_list, minparent);
	}
	if (maxparent != -1) {
		adj[parent].push_back(maxparent);
		make_tree(max_list, maxparent);
	}
}

// 후위 순회 (Postorder Traversal) - 왼쪽 -> 오른쪽 -> 루트
void postorder(int node) {
	for (auto child : adj[node]) {
		postorder(child);
	}
	cout << node << "\n";
}
void print_adj() {
	for (int i = 0; i < adj.size(); i++) {
		if (!adj[i].empty()) {  // 자식 노드가 있는 경우만 출력
			cout << i << ": ";
			for (int child : adj[i]) {
				cout << child << " ";
			}
			cout << "\n";  // 줄바꿈 추가
		}
	}
}


int main(void) {
	vector<int> inputlist;
	int data, parent;

	cin >> parent; 
	while (cin >> data) {  
		inputlist.push_back(data);
	}
	make_tree(inputlist, parent);
	postorder(parent); 

	return 0;
}
