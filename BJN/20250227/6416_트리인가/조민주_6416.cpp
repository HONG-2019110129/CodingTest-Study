#include <iostream>
#include <map>
#include <set>

using namespace std;

bool isTree(map<int, int>& inDegree, set<int>& nodes) {
    int rootCount = 0;
    int root = -1;
    
    for (int node : nodes) {
        if (inDegree[node] == 0) {
            rootCount++;
            root = node;
        }
        if (rootCount > 1) return false; // 루트 노드는 유일해야 함
    }
    
    if (rootCount == 0) return false; // 루트가 없는 경우
    
    // 노드 개수와 간선 개수 비교 (트리 특성 확인)
    int edgeCount = 0;
    for (auto& [_, count] : inDegree) {
        edgeCount += count;
    }
    
    return edgeCount == nodes.size() - 1;
}

int main() {
    int u, v, caseNum = 1;
    while (true) {
        map<int, int> inDegree;    // [노드번호, 간선수]
        set<int> nodes;    // [노드번호]
        bool isEmpty = true;
        
        while (cin >> u >> v && (u >= 0 && v >= 0)) {
            if (u == 0 && v == 0) break;
            isEmpty = false;
            inDegree[v]++;
            nodes.insert(u);
            nodes.insert(v);
            if (inDegree[v] > 1) isEmpty = false; // 들어오는 간선이 2개 이상이면 트리 아님
        }
        
        if (u < 0 && v < 0) break;
        
        cout << "Case " << caseNum++ << " is ";
        if (isEmpty || isTree(inDegree, nodes)) {
            cout << "a tree.\n";
        } else {
            cout << "not a tree.\n";
        }
    }
    return 0;
}

