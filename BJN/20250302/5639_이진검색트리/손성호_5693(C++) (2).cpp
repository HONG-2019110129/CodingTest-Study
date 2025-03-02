#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

int main() {
    unordered_map<int, vector<int>> tree;
    unordered_map<int, int> visited;
    stack<int> st;

    int root, new_node, temp;

    // 루트 입력
    cin >> root;
    tree[root] = { 0, 0 }; // 루트 노드 초기화

    // 트리 생성
    while (true) {
        if (!(cin >> new_node)) break;  // EOF 처리

        temp = root;
        while (true) {
            if (new_node < temp) {
                if (tree[temp][0]) {
                    temp = tree[temp][0]; // 왼쪽 자식이 있으면 이동
                }
                else {
                    tree[temp][0] = new_node;  // 왼쪽 자식에 추가
                    tree[new_node] = { 0, 0 };  // 새로운 노드 초기화
                    break;
                }
            }
            else {
                if (tree[temp][1]) {
                    temp = tree[temp][1]; // 오른쪽 자식이 있으면 이동
                }
                else {
                    tree[temp][1] = new_node;  // 오른쪽 자식에 추가
                    tree[new_node] = { 0, 0 };  // 새로운 노드 초기화
                    break;
                }
            }
        }
    }

    // 후위 순회 2개의 스택 사용
    stack<int> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        int node = s1.top();
        s1.pop();
        s2.push(node);

        if (tree[node][0]) s1.push(tree[node][0]); // 왼쪽 자식 먼저
        if (tree[node][1]) s1.push(tree[node][1]); // 오른쪽 자식 다음
    }


    while (!s2.empty()) {
        cout << s2.top() << "\n";
        s2.pop();
    }

    return 0;
}
