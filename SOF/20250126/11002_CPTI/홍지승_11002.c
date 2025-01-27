#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 시간복잡도 문제를 해결해야될것같음..*/
int main(void)
{
	int N, M;
	int result = 0;
	char **arr;
	scanf("%d %d", &N, &M);
	/* 동적할당해주고*/
	arr = (char **)malloc(sizeof(char *) * N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = (char *)malloc(sizeof(char) * M);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}
	/* 하나씩 다 비교하는 방식으로 하였음 배열 2개를*/
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int cnt = 0;
			for (int k = 0; k < M; k++)
			{
				/* 다른거 count 하고 */
				if (arr[i][k] != arr[j][k])
				{
					cnt++;
				}
				/*3개 이상나오면 break로 빠져나감*/
				if (cnt >= 3)
					break;
			}
			if (cnt < 3)
			{
				result += 1;
			}
		}
	}
	printf("%d", result);

	return 0;
}