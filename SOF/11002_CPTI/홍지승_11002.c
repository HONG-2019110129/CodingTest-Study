#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* �ð����⵵ ������ �ذ��ؾߵɰͰ���..*/
int main(void)
{
	int N, M;
	int result = 0;
	char **arr;
	scanf("%d %d", &N, &M);
	/* �����Ҵ����ְ�*/
	arr = (char **)malloc(sizeof(char *) * N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = (char *)malloc(sizeof(char) * M);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}
	/* �ϳ��� �� ���ϴ� ������� �Ͽ��� �迭 2����*/
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int cnt = 0;
			for (int k = 0; k < M; k++)
			{
				/* �ٸ��� count �ϰ� */
				if (arr[i][k] != arr[j][k])
				{
					cnt++;
				}
				/*3�� �̻󳪿��� break�� ��������*/
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