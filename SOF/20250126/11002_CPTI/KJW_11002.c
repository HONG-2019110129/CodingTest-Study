#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void)
{
    int N, M;
    (void)scanf("%d %d", &N, &M); // N��, CPTI ���� M

    // �޸� �Ҵ�
    char** CPTI = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; ++i) 
    {
        *(CPTI + i) = (char*)malloc(sizeof(char) * (M + 1)); // NULL ��� M + 1
    }
    
    // ������ �Է�
    for (int i = 0; i < N; ++i) 
    {
        (void)scanf("%s", *(CPTI + i));
    }

    // ģ�а� ���
    int couple_cnt = 0;    
    int i, j, k;
    for (k = 0; k < N - 1; ++k) //������ ��
    {
        for (i = k + 1; i < N; ++i) //�ռ� ��
        {
            int diff_cnt = 0;

            char* A = *(CPTI + k);
            char* B = *(CPTI + i);

            for (j = 0; j < M; ++j) // ���ڿ� ���̸�ŭ ��
            {
                //if (*(*(CPTI + k) + j) != *(*(CPTI + i) + j)) // �ٸ��� ī���� ����
                if (*(A + j) != *(B + j)) // �ٸ��� ī���� ����
                {
                    ++diff_cnt;
                    if (diff_cnt > 2) // �� ���� �� 2���� Ŀ���� �ڵ� �ȵ��ƺ��� OUT
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