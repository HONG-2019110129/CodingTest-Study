#include <iostream>

using namespace std;

// 이진 탐색 트리의 노드 구조체 정의
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 이진 탐색 트리에 노드 삽입
void insert(Node*& root, int new_node) {
    if (root == nullptr) {
        root = new Node(new_node);
        return;
    }

    if (new_node < root->value) {
        insert(root->left, new_node);
    }
    else {
        insert(root->right, new_node);
    }
}

// 후위 순회
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;

    postOrderTraversal(root->left);  // 왼쪽 서브트리 방문
    postOrderTraversal(root->right); // 오른쪽 서브트리 방문
    cout << root->value << "\n";     // 루트 노드 출력
}

int main() {
    int root_value, new_node;
    Node* root = nullptr;

    // 첫 번째 입력을 루트 노드로 설정
    if (!(cin >> root_value)) return 0;
    root = new Node(root_value);

    // 입력이 끝날 때까지 노드 추가
    while (cin >> new_node) {
        insert(root, new_node);
    }

    // 후위 순회 실행
    postOrderTraversal(root);

    return 0;
}
