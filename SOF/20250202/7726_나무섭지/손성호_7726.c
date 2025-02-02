#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000
#define MAX 1000

typedef struct {
    int x, y;
} Point;

int n, m;
char grid[MAX][MAX + 1]; // +1 for null terminator
int namuDist[MAX][MAX], ghostDist[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Queue 구조체
typedef struct {
    Point data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

void push(Queue *q, int x, int y) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->rear++;
}

Point pop(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// BFS 실행 함수
void bfs(Queue *q, int dist[MAX][MAX], int ignoreWalls) {
    while (!isEmpty(q)) {
        Point cur = pop(q);
        int x = cur.x, y = cur.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!ignoreWalls && grid[nx][ny] == '#') continue; // 남우는 벽을 통과 못함
            if (dist[nx][ny] != INF) continue; // 이미 방문한 곳

            dist[nx][ny] = dist[x][y] + 1;
            push(q, nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    Queue namuQ, ghostQ;
    initQueue(&namuQ);
    initQueue(&ghostQ);

    Point namu, exit;
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    // 거리 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            namuDist[i][j] = INF;
            ghostDist[i][j] = INF;

            if (grid[i][j] == 'N') {
                namu = (Point){i, j};
                namuDist[i][j] = 0;
                push(&namuQ, i, j);
            } else if (grid[i][j] == 'D') {
                exit = (Point){i, j};
            } else if (grid[i][j] == 'G') {
                ghostDist[i][j] = 0;
                push(&ghostQ, i, j);
            }
        }
    }

    // BFS 실행 (남우의 이동 경로)
    bfs(&namuQ, namuDist, 0);
    // BFS 실행 (유령의 이동 경로, 벽 무시)
    bfs(&ghostQ, ghostDist, 1);

    // 남우가 출구에 도달할 수 없는 경우
    if (namuDist[exit.x][exit.y] == INF) {
        printf("No\n");
        return 0;
    }

    // 남우가 출구까지 가는 거리와 유령이 출구까지 가는 거리 비교
    if (namuDist[exit.x][exit.y] < ghostDist[exit.x][exit.y]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
