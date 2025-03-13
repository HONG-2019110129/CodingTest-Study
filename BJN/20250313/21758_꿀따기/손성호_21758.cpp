#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int cnt;
    cin >> cnt;
    vector<int> arr;
    vector<long long int> sum_l;
    vector<long long int> sum_r;
    long long int sum = 0;
    int first;
    cin >> first;
    arr.push_back(first);
    sum_r.push_back(0);
    for (int i = 1; i < cnt - 1; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        sum += temp;
        sum_l.push_back(sum);
        sum_r.push_back(sum * -1);
    }
    sum_r.pop_back();
    int last;
    cin >> last;
    arr.push_back(last);
    long long int max = -1;
    for (int i = 0; i < cnt - 2; i++)
    {
        sum_r[i] += (sum);
        int temp_sum = sum_l[i] + sum_r[i];
        if (max < temp_sum)
            max = temp_sum;
    }
    long long int num1 = (sum_l[cnt - 3] + last);
    long long int num2 = (sum_r[0] + first);

    for (int i = 1; i < cnt-1; i++) {
        int tm = arr[i];
        int temp_num1 = num1 - tm + (sum - sum_l[i - 1] + last);
        int temp_num2 = num2 - tm + (sum - sum_r[i - 1] + first);
        if (max < temp_num1)
            max = temp_num1;
        if (max < temp_num2)
            max = temp_num2;
    }

    cout << max << "\n";
    return 0;
}