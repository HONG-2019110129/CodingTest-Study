#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N, popularity = 0;
    cin >> N;

    vector<int> Pi(N), Ci(N);

    for (int index = 0; index < N; ++index) {
        cin >> Pi[index] >> Ci[index];
    }

    // 인기도 계산
    for (int index = 0; index < N; ++index) {
        if (abs(Pi[index] - popularity) <= Ci[index]) {
            ++popularity;
        }
    }

    cout << popularity << '\n';

    return 0;
}