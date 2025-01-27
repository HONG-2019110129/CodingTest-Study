#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int N;
	int popularity = 0;
	(void)scanf("%d", &N);

	int* Pi = (int*)malloc(sizeof(int) * N);
	int* Ci = (int*)malloc(sizeof(int) * N);
	int index;
	for (int index = 0; index < N; ++index) 
	{
		(void)scanf("%d %d", Pi + index, Ci + index);
	}

	// 인기도 계산
	for (index = 0; index < N; ++index) // 사람 수 만큼 반복
	{
		if (abs(*(Pi + index) - popularity) <= *(Ci + index)) // ∣Pi​−X≤Ci​∣ 조건
		{
			++popularity;
		}
	}

	printf("%d\n", popularity);

	free(Pi);
	free(Ci);

	return 0;
}