#include <iostream>
#include <stack>
#include <vector>

using namespace std;
void print_vec(vector<int>& vec) {
    for (auto itr = vec.begin(); itr != vec.end(); itr++) {
        cout << *itr << " ";
    }
}

int main(void) {
    int N, val;
    vector<int> result;
    stack<pair<int, int>> stack_input;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val;

        // 스택이 비어 있거나 현재 값보다 작은 값을 모두 제거
        while (!stack_input.empty() && stack_input.top().first < val) {
            stack_input.pop();
        }

        if (stack_input.empty()) {
            result.push_back(0);
        }
        else {
            result.push_back(stack_input.top().second);
        }

        // 현재 값을 스택에 추가
        stack_input.push({ val,i + 1 });
    }

    print_vec(result);

    return 0;
}
