
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ������ �ٽ� >> �ɸ��� �ð��� ª���ź��� �־ ��ġ�� �κ��� ������ */
int main(void) {

	int N;
	int *si;
	scanf("%d", &N);
	si = (int*)malloc(sizeof(int)*N);

	int max = 0;
	/* �Ҵ� �ڵ��� �ܰ��� ���� �� �ܰ踦 ã�� ����*/
	for (int i = 0; i < N; i++) {
		scanf("%d", si + i);
		if (max < *(si + i)) max = *(si + i);
	}

	/* ����� ���� + �ڵ��� ���� - 1 �� ����*/
	printf("%d", max + N - 1);

	return 0;
}
