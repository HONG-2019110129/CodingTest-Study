#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* Ǯ�̹�
   1. �Է°��� ���Ϳ� �����Ѵ�.
   2. �� ó�� ���� �θ��̰�, �θ𺸴� ���� �׷�� ū �׷��� ������.
   3. �� �׷쿡�� ���� ���� ������ ���� �� �׷��� �θ� �ȴ�.
   4. �׷��� 0���� �� ������ ��ͷ� �ݺ��Ͽ� Ʈ���� �����Ѵ�.
   5. ������ Ʈ���� **���� ��ȸ�� ���**�Ѵ�.
*/

map<int,vector<int>> adj; 

// ���� Ž�� Ʈ���� �����ϴ� �Լ�
void make_tree(vector<int>& inputlist, int parent) {
	int minparent = -1, maxparent = -1;
	vector<int> min_list, max_list;

	// �Է� ����Ʈ�� ��ȸ�ϸ� ���� �׷�� ū �׷��� ����
	for (auto itr : inputlist) {
		if (itr < parent) {  // �θ𺸴� ���� ��
			if (minparent == -1) {
				minparent = itr;
			}
			else {
				min_list.push_back(itr);
			}
		}
		else {  // �θ𺸴� ū ��
			if (maxparent == -1) {
				maxparent = itr;
			}
			else {
				max_list.push_back(itr);
			}
		}
	}

	// �θ� ����� �ڽ� ��� ���� (��ȿ�� ���� �߰�)
	if (minparent != -1) {
		adj[parent].push_back(minparent);
		make_tree(min_list, minparent);
	}
	if (maxparent != -1) {
		adj[parent].push_back(maxparent);
		make_tree(max_list, maxparent);
	}
}

// ���� ��ȸ (Postorder Traversal) - ���� -> ������ -> ��Ʈ
void postorder(int node) {
	for (auto child : adj[node]) {
		postorder(child);
	}
	cout << node << "\n";
}
void print_adj() {
	for (int i = 0; i < adj.size(); i++) {
		if (!adj[i].empty()) {  // �ڽ� ��尡 �ִ� ��츸 ���
			cout << i << ": ";
			for (int child : adj[i]) {
				cout << child << " ";
			}
			cout << "\n";  // �ٹٲ� �߰�
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
