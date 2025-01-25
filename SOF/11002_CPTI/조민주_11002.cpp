#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Hamming �Ÿ� 2 ������ �� ��� �Լ�
long long calculateClosePairs(int N, int M, const vector<string>& cptiList) {
    // ���ڿ� �󵵸� �����ϱ� ���� �ؽø�
    unordered_map<string, int> freq;
    for (const string& cpti : cptiList) {
        freq[cpti]++;
    }

    // ģ�а��� ������ �� ���
    long long totalPairs = 0;

    for (auto& [cpti, count] : freq) {
        // ���� CPTI ������ ���� ����
        totalPairs += 1LL * count * (count - 1) / 2;

        // ���� CPTI���� Hamming �Ÿ� 1 �Ǵ� 2�� ��츦 ã��
        string current = cpti;
        for (int i = 0; i < M; ++i) {
            // �� �ڸ��� �ٲ� ���
            current[i] = (current[i] == '0' ? '1' : '0');
            if (freq.find(current) != freq.end() && current > cpti) {
                totalPairs += 1LL * count * freq[current];
            }

            // �� �ڸ��� �ٲ� ���
            for (int j = i + 1; j < M; ++j) {
                current[j] = (current[j] == '0' ? '1' : '0');
                if (freq.find(current) != freq.end() && current > cpti) {
                    totalPairs += 1LL * count * freq[current];
                }
                // ���󺹱�
                current[j] = (current[j] == '0' ? '1' : '0');
            }

            // ���󺹱�
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
