#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int order;
    int data;
    Node() : order(0), data(0){};
    Node(int o, int d)
    {
        order = o;
        data = d;
    }
};
int main(void)
{
    stack<Node> dataStack;
    queue<int> answer;
    int count;
    cin>>count;
    for(int i = 0; i<count; i++)
    {
        int temp;
        cin>>temp;
        while(!dataStack.empty() && dataStack.top().data<temp)
        {
            dataStack.pop();
        }
        if(dataStack.empty())
        {
            answer.push(0);
        }
        else
        {
            answer.push(dataStack.top().order);
        }
        dataStack.push({i+1, temp});
    }
    while(!answer.empty())
    {
        cout<<answer.front()<<" ";
        answer.pop();
    }
    cout<<"\n";
    return 0;
}