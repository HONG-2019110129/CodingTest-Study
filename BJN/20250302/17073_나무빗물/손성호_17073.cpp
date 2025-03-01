#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int cnt, t_water;
    cin >> cnt >> t_water;

    vector<vector<int>> tree(cnt + 1);
    vector<int> degree(cnt + 1, 0);

    for (int i = 0; i < cnt - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // 리프 노드 개수 세기
    int leaf_cnt = 0;
    for (int i = 2; i <= cnt; i++) {
        if (degree[i] == 1) {
            leaf_cnt++;
        }
    }

    // 평균 계산
    cout << fixed << setprecision(10) << (double)t_water / leaf_cnt << "\n";

    return 0;
}