#include <stdio.h>

#define NUM_RUDOLPHS 4
#define MATCHES 6
#define EPSILON 1e-9

typedef struct {
    int score[NUM_RUDOLPHS];
    double probability;
} State;

double F[NUM_RUDOLPHS]; // 루돌프들의 힘
int match_pairs[MATCHES][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
double success_probability = 0.0;

// 경기별 결과 시뮬레이션
void simulate(int match_index, State state) {
    if (match_index == MATCHES) {
        // 경기 종료 후 1번 루돌프가 상위 2등 안에 있는 경우 체크
        int rank[NUM_RUDOLPHS] = {0, 1, 2, 3};

        // 정렬 (승점 기준, 승점이 같으면 번호가 작은 순서)
        for (int i = 0; i < NUM_RUDOLPHS - 1; i++) {
            for (int j = i + 1; j < NUM_RUDOLPHS; j++) {
                if (state.score[rank[i]] < state.score[rank[j]] ||
                    (state.score[rank[i]] == state.score[rank[j]] && rank[i] > rank[j])) {
                    int temp = rank[i];
                    rank[i] = rank[j];
                    rank[j] = temp;
                }
            }
        }

        // 1번 루돌프가 상위 2등 안에 있는 경우 확률 추가
        for (int i = 0; i < 2; i++) {
            if (rank[i] == 0) {
                success_probability += state.probability;
                break;
            }
        }
        return;
    }

    int i = match_pairs[match_index][0], j = match_pairs[match_index][1];

    double total_strength = 5 * F[i] + 5 * F[j];
    double win_prob = (4 * F[i]) / total_strength;
    double lose_prob = (4 * F[j]) / total_strength;
    double draw_prob = (F[i] + F[j]) / total_strength;

    // i가 승리
    State win_state = state;
    win_state.score[i] += 3;
    win_state.probability *= win_prob;
    simulate(match_index + 1, win_state);

    // j가 승리
    State lose_state = state;
    lose_state.score[j] += 3;
    lose_state.probability *= lose_prob;
    simulate(match_index + 1, lose_state);

    // 무승부
    State draw_state = state;
    draw_state.score[i] += 1;
    draw_state.score[j] += 1;
    draw_state.probability *= draw_prob;
    simulate(match_index + 1, draw_state);
}

int main() {
    // 입력 받기
    for (int i = 0; i < NUM_RUDOLPHS; i++) {
        scanf("%lf", &F[i]);
    }

    // 초기 상태 설정
    State initial_state = {{0, 0, 0, 0}, 1.0};
    success_probability = 0.0;

    // 시뮬레이션 실행
    simulate(0, initial_state);

    // 결과 출력 (소수점 셋째 자리 반올림)
    printf("%.3lf\n", success_probability * 100);

    return 0;
}
