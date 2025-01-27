#define _CRT_SECURE_NO_WARNINGS;

#include <stdio.h>

int main(void)
{
	int N, si; // N: 생산할 자동차 수, si: 각각의 프로세스 단계 수
	int MAX = 1; // 가장 긴 프로세스 단계 수(가장 긴 si)
	(void)scanf("%d", &N);

	// 가장 긴 si 찾기
	// 가장 짧은 것 부터 배치가 가능하다는 전재를 기반으로 코들를 짠건데, 맞는 판단인지는 모르겠음
	// 작업 슬롯이 큰(= si가 작은) 자동차부터 배치가 가능하다는 것?

	// 그래서 마지막 자동차가 슬롯이 할당되는 시점: N-1초
	// 아래는 마지막 자동차가 작업이 완료되는 데 걸리는 시간

	int least_time = N - 1;

	for (int i = 0; i < N; ++i)
	{
		(void)scanf("%d", &si);
		if (si > MAX)
		{
			MAX = si;
		}
	}
	// 이러면 겹칠 일이 없어서 그냥 가장 작업 슬롯이 짧은 자동차가 (0, 1] 구간 마지막에 도달하는 시간만 계산하면 됨 = (MAX)

	least_time += MAX;
	printf("%d", least_time);

	return 0;
}