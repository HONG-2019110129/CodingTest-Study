#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double F[4];            // 루돌프 힘
double PROB = 0.0;      // 확률

// Red vs Blue
// 1번 루돌 vs 2번 | 1번 루돌 vs 3번 | 1번 루돌 vs 4번 | 2번 루돌 vs 3번 | 2번 루돌 vs 4번 | 3번 루돌 vs 4번
int R[6] = { 0, 0, 0, 1, 1, 2 }; // Red 팀
int B[6] = { 1, 2, 3, 2, 3, 3 }; // Blude 팀

void dfs(int matchIndex, int points[4], double prob) 
{    
    if (matchIndex == 6) // 모든 경기를 진행
    {
        int cnt = 0;
        for (int i = 1; i < 4; ++i) 
        {
            if (points[i] > points[0])
            {
                ++cnt; // 1번 루돌프보다 커 => cnt 증간
            }
            else if (points[i] == points[0]) // 동점 -> 1번 루돌프가 무조건 이김
            {
                continue;
            }
        }
        if (cnt < 2) // 2등 안에 조건 cnt 1이면 2등
        {
            PROB += prob;
        }
        return;
    }

    int red = R[matchIndex];        // 현재 매치 red 팀 힘
    int blue = B[matchIndex];       // 현재 매치 blue 팀 힘

    printf("\n=================\n");
    // red 팀 승리 => red point 3점 추가 => 모든 경기 진행 되면 다시 point 초기화
    double win = ((4 * F[red]) / (5 * F[red] + 5 * F[blue]));    
    points[red] += 3;       // red 팀 i 번호 루돌프 포인트 증가    
    printf("win matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * win);
    printf("win matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[red] -= 3;    
    printf("\n=================\n");

    printf("\n=================\n");
    // blue 팀 승리
    double lose = ((4 * F[blue]) / (5 * F[red] + 5 * F[blue]));    
    points[blue] += 3;
    printf("lose matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * lose);
    printf("lose matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[blue] -= 3;
    printf("\n=================\n");

    printf("\n=================\n");
    // 무승부
    double draw = ((F[red] + F[blue]) / (5 * F[red] + 5 * F[blue]));    
    points[red] += 1;
    points[blue] += 1;
    printf("draw matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * draw);
    printf("draw matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[red] -= 1;
    points[blue] -= 1;    
    printf("\n=================\n");
}

int main()
{
    // 루돌프 힘 입력
    (void)scanf("%lf %lf %lf %lf", &F[0], &F[1], &F[2], &F[3]);

    int points[4] = {0, 0, 0, 0};   // 루돌프 점수
    dfs(0, points, 1.0);            // dfs 시작

    double result = PROB * 100.0;   // 확률 계산
    printf("%.3f\n", result);

    return 0;
}