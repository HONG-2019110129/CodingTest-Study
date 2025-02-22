#include <iostream>
#include <vector>
#include <cmath>  // abs �Լ� ���

using namespace std;

bool check_IsCross(const vector<pair<int, int>>& vec, vector<pair<int, int>>::iterator itr) {
	int xpos = itr->first;
	int r1 = itr->second;
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		if (it == itr) continue;  // �ڱ� �ڽ� ����
		int x2 = it->first;
		int r2 = it->second;
		int distance = abs(xpos - x2);

		// ���� ���� ��ġ�� �ʴ� ����
		if (distance > r1 + r2 || distance < abs(r1 - r2)) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int N, xpos, r;
	vector<pair<int, int>> vec;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> xpos >> r;
		vec.push_back({ xpos, r });
	}

	for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
		if (!check_IsCross(vec, itr)) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}
