#include <iostream>

using namespace std;

// ���� Ž�� Ʈ���� ��� ����ü ����
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// ���� Ž�� Ʈ���� ��� ����
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

// ���� ��ȸ
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;

    postOrderTraversal(root->left);  // ���� ����Ʈ�� �湮
    postOrderTraversal(root->right); // ������ ����Ʈ�� �湮
    cout << root->value << "\n";     // ��Ʈ ��� ���
}

int main() {
    int root_value, new_node;
    Node* root = nullptr;

    // ù ��° �Է��� ��Ʈ ���� ����
    if (!(cin >> root_value)) return 0;
    root = new Node(root_value);

    // �Է��� ���� ������ ��� �߰�
    while (cin >> new_node) {
        insert(root, new_node);
    }

    // ���� ��ȸ ����
    postOrderTraversal(root);

    return 0;
}
