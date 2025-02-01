/*
1. dfs인자중 distance를 넣어주는데 +1 을 안하고 함수내에서 값을 증가시켜줌
2. backtracking으로 만약 정답을 찾지 못했을때 visted를 다시 0으로 돌려주는거 생각
3. ghost dfs1 내부에 재귀도 dfs1로 필요
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int visited[MAX][MAX] = {0};
char maze[MAX][MAX] = {0};
int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int min = 1000;

typedef struct pos
{
    int x;
    int y;
} pos;

pos ghost[5];

void initialize_visit(int x, int y)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
        }
    }
    visited[x][y] = 1;
}

/* 남우 포지션을 시작점을 한다*/
void dfs(int x, int y, int distance)
{
    int ny, nx;

    if (maze[x][y] == 'D')
    {
        if (distance < min)
        {
            min = distance; // 최단 거리 갱신
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {

        nx = x + dx[i];
        ny = y + dy[i];
        /*벽이없고 범위를 벗어나지 않는경우 이동이 가능하다*/
        if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && maze[nx][ny] != '#' && visited[nx][ny] == 0)
        {
            visited[nx][ny] = 1;
            dfs(nx, ny, distance + 1);
            visited[nx][ny] = 0; // 도착지점이 아니라서 backtracking해주는 부분
        }
    }
}
void dfs1(int x, int y, int distance)
{
    int ny, nx;

    if (maze[x][y] == 'D')
    {
        if (distance < min)
        {
            min = distance; // 최단 거리 갱신
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {

        nx = x + dx[i];
        ny = y + dy[i];
        /*벽이없고 범위를 벗어나지 않는경우 이동이 가능하다*/
        if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && visited[nx][ny] == 0)
        {
            visited[nx][ny] = 1;
            dfs1(nx, ny, distance + 1);
            visited[nx][ny] = 0; // 도착지점이 아니라서 backtracking해주는 부분
        }
    }
}

void print_data(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", maze[i]);
    }
}
/* scanf 할때는 개행도 입력된다고 생각하면 된다.*/
int main(void)
{

    int people_min = 19999;
    int dis = 0;
    int x, y;
    int cnt = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", maze[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == 'N')
            {
                x = i;
                y = j;
            }
            else if (maze[i][j] == 'G')
            {
                ghost[cnt].x = i;
                ghost[cnt].y = j;
                cnt++;
            }
        }
    };
    /* dfs를 여러번 돌려서 ghost와 남우의 거리를 비교하는 과정이 필요*/
    visited[x][y] = 1;
    dfs(x, y, dis);
    people_min = min;
    min = 10000;
    for (int i = 0; i < cnt; i++)
    {
        initialize_visit(ghost[i].x, ghost[i].y);
        dfs1(ghost[i].x, ghost[i].y, dis);
    }
    if (people_min < min)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}