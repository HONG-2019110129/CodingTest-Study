
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 문제의 핵심 >> 걸리는 시간이 짧은거부터 넣어서 겹치는 부분이 없게함 */
int main(void) {

	int N;
	int *si;
	scanf("%d", &N);
	si = (int*)malloc(sizeof(int)*N);

	int max = 0;
	/* 할당 자동차 단계중 가장 긴 단계를 찾는 과정*/
	for (int i = 0; i < N; i++) {
		scanf("%d", si + i);
		if (max < *(si + i)) max = *(si + i);
	}

	/* 가장긴 과정 + 자동자 개수 - 1 이 정답*/
	printf("%d", max + N - 1);

	return 0;
}
