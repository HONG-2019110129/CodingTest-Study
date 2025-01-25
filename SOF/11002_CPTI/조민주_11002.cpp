#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Hamming 거리 2 이하의 쌍 계산 함수
long long calculateClosePairs(int N, int M, const vector<string>& cptiList) {
    // 문자열 빈도를 저장하기 위한 해시맵
    unordered_map<string, int> freq;
    for (const string& cpti : cptiList) {
        freq[cpti]++;
    }

    // 친밀감을 느끼는 쌍 계산
    long long totalPairs = 0;

    for (auto& [cpti, count] : freq) {
        // 같은 CPTI 내에서 쌍의 개수
        totalPairs += 1LL * count * (count - 1) / 2;

        // 현재 CPTI에서 Hamming 거리 1 또는 2인 경우를 찾음
        string current = cpti;
        for (int i = 0; i < M; ++i) {
            // 한 자리만 바꾼 경우
            current[i] = (current[i] == '0' ? '1' : '0');
            if (freq.find(current) != freq.end() && current > cpti) {
                totalPairs += 1LL * count * freq[current];
            }

            // 두 자리를 바꾼 경우
            for (int j = i + 1; j < M; ++j) {
                current[j] = (current[j] == '0' ? '1' : '0');
                if (freq.find(current) != freq.end() && current > cpti) {
                    totalPairs += 1LL * count * freq[current];
                }
                // 원상복구
                current[j] = (current[j] == '0' ? '1' : '0');
            }

            // 원상복구
            current[i] = (current[i] == '0' ? '1' : '0');
        }
    }

    return totalPairs;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cptiList(N);
    for (int i = 0; i < N; ++i) {
        cin >> cptiList[i];
    }

    long long result = calculateClosePairs(N, M, cptiList);
    cout << result << endl;

    return 0;
}
