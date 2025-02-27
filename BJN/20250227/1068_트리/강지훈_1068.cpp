#include <iostream>
#include <vector>

#define ROOT -1

using namespace std;

vector<vector<int>>tree;
vector<int>parent;
int deleteNode;
int rootNode = -1;
int totalLeaf;

int leafNum(int node)
{
	if (node == deleteNode)
	{
		return 0;
	}

	int isLeaf = 0;
	for (int child : tree[node])
	{
		if (child == deleteNode)
		{
			continue;
		}
	}
	return totalLeaf;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;		//50���� �ڿ���
	
	tree.resize(N);
	parent.resize(N);

	for (int nodeIdx = 0; nodeIdx < N; ++nodeIdx)
	{
		//i�� node�� parent �Է�
		cin >> parent[nodeIdx];
		if (parent[nodeIdx] == ROOT)		// root node
		{
			rootNode = nodeIdx;
		}
		else							// nodeIdx�� node�� parent�� child ���� �ִ��� ����
		{
			tree[parent[nodeIdx]].push_back(nodeIdx);
		}
	}
	
	cin >> deleteNode;

	if (deleteNode == rootNode)
	{
		cout << 0 << "\n";
		return 0;
	}
	cout << leafNum(rootNode) << "\n";
	return 0;
}