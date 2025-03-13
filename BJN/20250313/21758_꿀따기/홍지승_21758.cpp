#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int answer = -1;
	int sum = 0;
	vector<int> honey(N+1, 0);

	for (int i = 1;i <= N;i++) {
		cin >> honey[i];
	}
	//꿀통이 가장 왼쪽에 위치
	int loc_max = -1;

	for (int j = N-1;j >= 1;j--) {
		for (int k = j - 1;k >= 1;k--) sum += honey[k];
		for (int l = N-1;l >= 1;l--) {
			if (l != j) sum += honey[l];
		}
		loc_max = max(loc_max, sum);
		sum = 0;
	}
	answer = max(answer, loc_max);
	
	// 꿀통이 중앙에 위치할 때
	int middle_max = -1;
	for (int i = 2;i <= N-1;i++) {
		middle_max = max(middle_max, honey[i]);
		sum += honey[i];
	}
	sum += middle_max;
	answer = max(answer, sum);
	sum = 0;
	
	// 꿀통이 가장 오른쪽에 위치
	loc_max = -1;

	for (int j = 2;j <= N;j++) {
		for (int k = j + 1;k <= N;k++) sum += honey[k];
		for (int l = 2;l <= N;l++) {
			if (l != j) sum += honey[l];
		}
		loc_max = max(loc_max, sum);
		sum = 0;
	}
	answer = max(answer, loc_max);

	cout << answer;

	return 0;
}
