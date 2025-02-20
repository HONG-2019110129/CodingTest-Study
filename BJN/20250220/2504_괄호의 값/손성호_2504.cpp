#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

class Data {
public:
    int num;
    char ch;
    Data() : num(0), ch(' ') {}

    Data(int n, char c) {
        num = n;
        ch = c;
    }
};

int main() {
    stack<Data> dataStack;
    char* str = new char[31];  

    cin >> str;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(')
            dataStack.push({0, '('});
        else if (str[i] == '[')
            dataStack.push({0, '['});
        else if (str[i] == ')') {
            if (dataStack.empty()) {
                cout << "0" << endl;
                delete[] str;
                return 0;
            }

            Data temp = dataStack.top();
            dataStack.pop();
            int tempSum = 0;

            while (temp.ch != '(') {
                if (dataStack.empty()) {
                    cout << "0" << endl;
                    delete[] str;
                    return 0;
                }

                int tempNum = temp.num;
                if (tempNum) {
                    tempSum += tempNum;
                    temp = dataStack.top();
                    dataStack.pop();
                } else {
                    cout << "0" << endl;
                    delete[] str;
                    return 0;
                }
            }
            if (tempSum)
                dataStack.push({tempSum * 2, ' '});
            else
                dataStack.push({2, ' '});
        }
        else if (str[i] == ']') {
            if (dataStack.empty()) {
                cout << "0" << endl;
                delete[] str;
                return 0;
            }

            Data temp = dataStack.top();
            dataStack.pop();
            int tempSum = 0;

            while (temp.ch != '[') {
                if (dataStack.empty()) {  
                    cout << "0" << endl;
                    delete[] str;
                    return 0;
                }

                int tempNum = temp.num;
                if (tempNum) {
                    tempSum += tempNum;
                    temp = dataStack.top();
                    dataStack.pop();
                } else {
                    cout << "0" << endl;
                    delete[] str;
                    return 0;
                }
            }
            if (tempSum)
                dataStack.push({tempSum * 3, ' '});
            else
                dataStack.push({3, ' '});
        }
    }

    int sum = 0;
    while (!dataStack.empty()) {
        Data res = dataStack.top();
        dataStack.pop();
        if (res.num)
            sum += res.num;
        else {
            cout << "0" << endl;
            delete[] str;
            return 0;
        }
    }

    cout << sum << "\n";
    
    delete[] str;  
    return 0;
}
