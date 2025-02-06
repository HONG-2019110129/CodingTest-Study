#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int arr[50000][2];
	long long int sum = 0;
	int para = 0, before = 2100000000, idx = 0, cnt = n;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		sum = sum + temp;
		if (para)
		{
			if (before <= temp)
			{
				if (arr[idx - 1][1] > temp)
				{
					arr[idx][0] = i;
					arr[idx][1] = temp;
					before = temp;
					idx++;
					para = 1;
				}
				else {
					arr[idx - 1][0] = i;
					arr[idx - 1][1] += temp;
					before = temp;
					cnt--;
				}
			}
			else
			{
				before = arr[idx-1][1]+temp;
				arr[idx - 1][1]=before;
				para = 0;
				cnt--;
			}
		}
		else if (before <= temp)
		{
			arr[idx - 1][0] = i;
			arr[idx - 1][1] += temp;
			before = temp;
			para = 1;
			cnt--;
		}
		else
		{
			arr[idx][0] = i;
			arr[idx][1] = temp;
			before = temp;
			idx++;
			para = 1;
		}
	}
	int gap = idx;
	while (cnt>1)
	{
		para = 0;
		int new_idx = idx;
		before = 2100000000;

		for (int j = 0; j < gap; j++)
		{
			int temp_data = arr[idx - gap+j][1];
			int index = arr[idx - gap + j][0];
			if (para)
			{
				if (before <= temp_data)
				{
					if (arr[new_idx - 1][1] > temp_data)
					{
						arr[new_idx][0] = index;
						arr[new_idx][1] = temp_data;
						before = temp_data;
						new_idx++;
						para = 1;
					}
					else {
						arr[new_idx - 1][0] = index;
						arr[new_idx - 1][1] += temp_data;
						before = temp_data;
						cnt--;
					}
				}
				else
				{
					before = arr[new_idx-1][1] + temp_data;
					arr[new_idx - 1][1] = before;
					para = 0;
					cnt--;
				}
			}
			else if (before <= temp_data) {
				arr[new_idx - 1][1] += temp_data;
				arr[new_idx - 1][0] = index;
				before = temp_data;
				para = 1;
				cnt--;
			}
			else
			{
				arr[new_idx][0] = index;
				arr[new_idx][1] = temp_data;
				before = temp_data;
				new_idx++;
				para = 1;
			}
		}
		gap = new_idx - idx;
		idx = new_idx;
	}
	printf("%lld\n%d\n", sum, arr[idx-gap][0]);
	return 0;
}