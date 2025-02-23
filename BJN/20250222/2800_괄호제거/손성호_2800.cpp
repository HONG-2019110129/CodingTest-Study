#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

class Symbol {
public:
    int index;
    int open;
    int close;
    Symbol(int index, int open, int close) : index(index), open(open), close(close) {};
    Symbol() : index(0), open(0), close(0) {};
};

int main(void) {
    char word[201];
    int word_index[201] = { 0 };
    cin >> word;

    stack<Symbol> dataStack;
    Symbol symbolArr[201] = { {0, 0, 0} };
    int cont_index[201] = { 0 };

    int index = 0;
    int i;
    int cont = 0;  // 연속된 '(' 개수 카운트
    int last_open_idx = -2;  // 마지막 '('의 위치 저장

    for (i = 0; i < strlen(word); i++) {
        if (word[i] == '(') {
            if (last_open_idx == i - 1) {
                // 이전에도 '('가 있었으면, index를 역순으로 조정
                dataStack.push({ index - cont, i, 0 });
            }
            else {
                dataStack.push({ index, i, 0 });
            }
            last_open_idx = i; // 마지막 열린 괄호 위치 업데이트
            cont++;
            index++;
        }
        else if (word[i] == ')') {
            cont = 0;  // 연속된 '('가 끊겼으므로 초기화

            Symbol data = dataStack.top();
            dataStack.pop();
            data.close = i;
            int data_index = data.index;
            if (cont_index[data_index])
            {
                data.index += cont_index[data_index];
            }
            cont_index[data_index]++;
            symbolArr[data.index] = data;
        }
        else {
            cont = 0;  // 연속된 '(' 카운트 초기화
        }
        word_index[i] = 1;
    }

    set<string> resultSet;  // 중복 방지를 위한 set

    for (int j = 1; j <= pow(2, index) - 1; j++) {
        int temp = j;
        int temp_idx = 1;
        while (temp) {
            if (temp % 2) {
                Symbol temp_sym = symbolArr[index - temp_idx];
                dataStack.push(temp_sym);
                word_index[temp_sym.open] = 0;
                word_index[temp_sym.close] = 0;
            }
            temp /= 2;
            temp_idx++;
        }

        string result = "";
        for (int k = 0; k < i; k++) {
            if (word_index[k]) {
                result += word[k];
            }
        }

        if (!resultSet.count(result)) {  // 중복된 결과 방지
            resultSet.insert(result);
            cout << result << "\n";
        }

        // 원래 상태로 복구
        while (!dataStack.empty()) {
            Symbol recov = dataStack.top();
            word_index[recov.open] = 1;
            word_index[recov.close] = 1;
            dataStack.pop();
        }
    }

    return 0;
}
