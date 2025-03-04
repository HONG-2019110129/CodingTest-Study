// 실패

#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int leaf_count = 0;
unordered_map<int, float> trees_water;    // [노드번호, 갖고 있는 물]    
unordered_map<int, unordered_set<int>> trees; //[노드번호, 연결된 노드번호]

void dfs(int node) {
    if (trees[node].size() == 1) {
        leaf_count++;
        return;
    }
    else {
        double distribute = trees_water[node] / (trees[node].size() - 1);
        for (auto& son_node : trees[node]) {
            if (trees_water.find(son_node) == trees_water.end()) {
                trees_water[son_node] = distribute;
                dfs(son_node);
            }

        }
    }
}

using namespace std;
int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int n;
    double w;
    cin >> n >> w;

    trees_water[1] = w;    // 1번 노드가 최초로 갖고 있는 물 양을 기록

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        trees[u].insert(v);
        trees[v].insert(u);
    }

    dfs(1);

    printf("%.10lf", w / (double)leaf_count);
}