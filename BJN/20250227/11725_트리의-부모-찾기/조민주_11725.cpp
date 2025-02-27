#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    for (int child : tree[node]) {
        if (!visited[child]) {
            parent[child] = node;
            dfs(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1);
    
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    
    return 0;
}