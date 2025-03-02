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

    // ��Ʈ �Է�
    cin >> root;
    tree[root] = { 0, 0 }; // ��Ʈ ��� �ʱ�ȭ

    // Ʈ�� ����
    while (true) {
        if (!(cin >> new_node)) break;  // EOF ó��

        temp = root;
        while (true) {
            if (new_node < temp) {
                if (tree[temp][0]) {
                    temp = tree[temp][0]; // ���� �ڽ��� ������ �̵�
                }
                else {
                    tree[temp][0] = new_node;  // ���� �ڽĿ� �߰�
                    tree[new_node] = { 0, 0 };  // ���ο� ��� �ʱ�ȭ
                    break;
                }
            }
            else {
                if (tree[temp][1]) {
                    temp = tree[temp][1]; // ������ �ڽ��� ������ �̵�
                }
                else {
                    tree[temp][1] = new_node;  // ������ �ڽĿ� �߰�
                    tree[new_node] = { 0, 0 };  // ���ο� ��� �ʱ�ȭ
                    break;
                }
            }
        }
    }

    // ���� ��ȸ 2���� ���� ���
    stack<int> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        int node = s1.top();
        s1.pop();
        s2.push(node);

        if (tree[node][0]) s1.push(tree[node][0]); // ���� �ڽ� ����
        if (tree[node][1]) s1.push(tree[node][1]); // ������ �ڽ� ����
    }


    while (!s2.empty()) {
        cout << s2.top() << "\n";
        s2.pop();
    }

    return 0;
}
