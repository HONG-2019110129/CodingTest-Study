#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void)
{
    int N, M;
    (void)scanf("%d %d", &N, &M); // N명, CPTI 길이 M

    // 메모리 할당
    char** CPTI = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; ++i) 
    {
        *(CPTI + i) = (char*)malloc(sizeof(char) * (M + 1)); // NULL 고려 M + 1
    }
    
    // 데이터 입력
    for (int i = 0; i < N; ++i) 
    {
        (void)scanf("%s", *(CPTI + i));
    }

    // 친밀감 계산
    int couple_cnt = 0;    
    int i, j, k;
    for (k = 0; k < N - 1; ++k) //뒤쳐진 줄
    {
        for (i = k + 1; i < N; ++i) //앞선 줄
        {
            int diff_cnt = 0;

            char* A = *(CPTI + k);
            char* B = *(CPTI + i);

            for (j = 0; j < M; ++j) // 문자열 길이만큼 비교
            {
                //if (*(*(CPTI + k) + j) != *(*(CPTI + i) + j)) // 다르면 카운터 증가
                if (*(A + j) != *(B + j)) // 다르면 카운터 증가
                {
                    ++diff_cnt;
                    if (diff_cnt > 2) // 비교 연산 중 2보다 커지면 뒤도 안돌아보고 OUT
                    {
                        break;
                    }
                }
            }

            if (diff_cnt <= 2)
            {
                ++couple_cnt;
            }
        }
    }

    printf("%d\n", couple_cnt);
    
    /*for (int i = 0; i < N; ++i) 
    {
        free(*(CPTI + i));
    }
    free(CPTI);*/

    return 0;
}
#endif

#if 01

int popcount(int x) 
{
    int count = 0;
    while (x) 
    {
        count += x & 1; // 마지막 비트가 1이면 카운트
        x >>= 1;        // 오른쪽으로 비트 이동
    }
    return count;
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    // 사전 처리: 문자열을 정수로 변환하여 저장
    int* CPTI = (int*)malloc(sizeof(int) * N);
    char* input = (char*)malloc(sizeof(char) * (M + 1));
    for (int i = 0; i < N; ++i) 
    {
        scanf("%s", input);

        int mask = 0;
        for (int j = 0; j < M; ++j) 
        {
            if (input[j] == '1') {
                mask |= (1 << j); // 비트마스크 생성
            }
        }
        *(CPTI+i) = mask; // 변환된 비트마스크 저장
    }

    // 친밀감 계산
    int couple_cnt = 0;

    for (int k = 0; k < N - 1; ++k) 
    {
        for (int i = k + 1; i < N; ++i) 
        {
            int diff = CPTI[k] ^ CPTI[i]; // XOR 연산으로 차이 계산
            if (popcount(diff) <= 2) // 차이가 2 이하인지 확인
            {    
                ++couple_cnt;
            }
        }
    }

    printf("%d\n", couple_cnt);

    free(CPTI);
    return 0;
}

#endif