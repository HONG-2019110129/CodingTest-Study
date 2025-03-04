#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
multimap<int, int> mymap;

int main(void)
{
    int N, key, value;
    int result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> key >> value;
        mymap.insert({key, value});
    }
    while (!mymap.empty())
    {
        multimap<int, int>::iterator itr = mymap.begin();
        while (itr != mymap.end())
        {
            auto temp_itr = itr;
            itr = mymap.lower_bound(itr->second);
            mymap.erase(temp_itr);
        }
        result += 1;
    }

    cout << result;

    return 0;
}