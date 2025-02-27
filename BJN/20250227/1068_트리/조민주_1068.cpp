#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;
vector<int> tree[MAX];
bool removed[MAX];
int root;

int countLeafNodes(int node) {
    if (removed[node]) return 0;
    
    int childCount = 0;
    int leafCount = 0;
    
    for (int child : tree[node]) {
        if (!removed[child]) {
            leafCount += countLeafNodes(child);
            childCount++;
        }
    }
    
    return (childCount == 0) ? 1 : leafCount;
}

int main() {
    int n;
    cin >> n;
    
    int parent[MAX];
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p == -1) {
            root = i;
        } else {
            tree[p].push_back(i);
        }
    }
    
    int deleteNode;
    cin >> deleteNode;
    removed[deleteNode] = true;
    
    if (deleteNode == root) {
        cout << 0 << '\n';
    } else {
        cout << countLeafNodes(root) << '\n';
    }
    
    return 0;
}
