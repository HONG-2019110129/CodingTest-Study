#include <stdio.h>
#include <string.h>

#define MAX_N 5001
#define MAX_M 500

typedef struct {
    int to;
    char c;
} Edge;

Edge adj[MAX_N][MAX_N]; // 인접 리스트
int edgeCount[MAX_N];   // 각 노드의 간선 개수
char S[MAX_M];          // 주어진 문자열 S
int maxLCS = 0;         // 최대 행복 지수 저장
int lcsTable[MAX_M][MAX_M]; // LCS 결과를 저장할 테이블

// LCS 계산 (미리 S에 대한 LCS 테이블 계산)
void precomputeLCS(char* S) {
    int lenS = strlen(S);
    for (int i = 0; i <= lenS; i++) {
        for (int j = 0; j <= lenS; j++) {
            lcsTable[i][j] = 0;
        }
    }
}

// DFS 탐색 (경로 문자열을 인덱스로 관리)
void dfs(int node, char T[], int depth, int visited[]) {
    visited[node] = 1; // 방문 체크
    int isLeaf = 1; // 리프 노드 판별

    for (int i = 0; i < edgeCount[node]; i++) {
        int next = adj[node][i].to;
        char edgeChar = adj[node][i].c;

        if (!visited[next]) {
            isLeaf = 0;
            T[depth] = edgeChar;
            T[depth + 1] = '\0';

            dfs(next, T, depth + 1, visited);
        }
    }

    if (isLeaf) { // 리프 노드 도착 시 LCS 계산
        int lcs = 0;
        int lenS = strlen(S);
        int lenT = depth;
        int dp[MAX_M][MAX_M] = { 0 };

        for (int i = 1; i <= lenT; i++) {
            for (int j = 1; j <= lenS; j++) {
                if (T[i - 1] == S[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        lcs = dp[lenT][lenS];
        if (lcs > maxLCS) maxLCS = lcs;
    }

    visited[node] = 0; // 백트래킹
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    scanf("%s", S);

    precomputeLCS(S); // LCS 테이블 초기화

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);

        adj[u][edgeCount[u]].to = v;
        adj[u][edgeCount[u]].c = c;
        edgeCount[u]++;

        adj[v][edgeCount[v]].to = u;
        adj[v][edgeCount[v]].c = c;
        edgeCount[v]++;
    }

    int visited[MAX_N] = { 0 };
    char T[MAX_N] = ""; // 처음에는 빈 문자열

    dfs(1, T, 0, visited);

    printf("%d\n", maxLCS);
    return 0;
}