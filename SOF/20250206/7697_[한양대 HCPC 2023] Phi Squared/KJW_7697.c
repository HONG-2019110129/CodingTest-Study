#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{
    int pos;              // 초기 위치
    long long size;       // 현재 크기
    struct Node* prev;
    struct Node* next;
} Node;

// Node 생성
Node* createNode(int pos, int size) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->pos = pos;
    node->size = size;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() 
{
    int N;
    (void)scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * (N + 1));       // size 입력 배열
    for (int i = 1; i <= N; ++i) 
    {
        (void)scanf("%d", arr + i);
    }
 
    // deque 돌릴거
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 1; i <= N; ++i)
    {
        Node* node = createNode(i, *(arr + i));     // 0번 ~ N번 노드 공간 만들기
        if (head == NULL) 
        {
            head = tail = node;
        }
        else 
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    //      지금 head: node 처음
    //           tail: node 마지막
    while (head != tail) 
    { 
        for (Node* cur = head; cur != NULL; cur = cur->next) 
        {
            // 이번 turn의 기준 크기 (당일 turn 시작 전 크기)
            long long currSize = cur->size;

            if (cur->prev && cur->prev->size <= currSize)       // 왼쪽 비교
            {                
                cur->size += cur->prev->size;               // 크기 증가
                
                Node* removeNode = cur->prev;                 // 왼쪽 노드 제거
                if (removeNode->prev)                         // 제거할 노드의 prev가 존재하면 화살표 다시 이어주기
                {
                    removeNode->prev->next = cur;
                    cur->prev = removeNode->prev;
                }
                else                                        // 첫 노드라는 뜻
                {
                    head = cur;
                    cur->prev = NULL;
                }
                free(removeNode);
            }

            if (cur->next && cur->next->size <= currSize)       // 오른쪽 비교
            {
                cur->size += cur->next->size;
                Node* removeNode = cur->next;
                if (removeNode->next)
                {
                    removeNode->next->prev = cur;
                    cur->next = removeNode->next;
                }
                else 
                {
                    tail = cur;
                    cur->next = NULL;
                }
                free(removeNode);
            }
        }
    }

    printf("%lld\n%d\n", head->size, head->pos);
    return 0;
}