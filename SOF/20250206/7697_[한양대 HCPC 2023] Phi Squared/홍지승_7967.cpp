#include <iostream>

using namespace std;

struct Node {
    long long size;   // 미생물 크기
    int index;  // 초기 위치 (1-based index)
    Node* prev;
    Node* next;

    Node(int s, int i) : size(s), index(i), prev(nullptr), next(nullptr) {}
};

// 노드 삭제 함수
void deletionNode(Node* node, Node*& head, Node*& tail) {
    if (node == head || node == tail) return; // 헤드와 테일은 삭제하지 않음

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

// 미생물을 흡수하는 함수
void solution(Node* head, Node* tail) {
    while (head->next->next != tail) { // 리스트에 하나만 남을 때까지 반복
        Node* curr = head->next;
       

        while (curr != tail) {
            if (curr->size >= curr->next->size && curr->size >= curr->prev->size) {
                curr->size = curr->size + curr->next->size + curr->prev->size;
                deletionNode(curr->next, head, tail);
                deletionNode(curr->prev, head, tail);
            }
            else if (curr->size >= curr->next->size) {
                curr->size += curr->next->size;
                deletionNode(curr->next, head, tail);
            }
            else if (curr->size >= curr->prev->size) {
                curr->size += curr->prev->size;
                deletionNode(curr->prev, head, tail);
            }
            curr = curr->next;
        }
    }
    // 마지막 남은 미생물 출
    cout << head->next->size << "\n" << head->next->index << endl;
}

int main() {
    int N;
    cin >> N;

    Node* head = new Node(0, 0); // 가상의 헤드
    Node* tail = new Node(0, 0); // 가상의 테일
    head->next = tail;
    tail->prev = head;

    Node* prev = head;
    for (int i = 1; i <= N; i++) {
        int size;
        cin >> size;
        Node* newNode = new Node(size, i);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
    }
    prev->next = tail;
    tail->prev = prev;

    solution(head, tail);

    return 0;
}