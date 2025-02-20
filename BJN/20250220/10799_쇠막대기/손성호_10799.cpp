#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    int sum = 0, temp = 0;
    char* word = new char[100001];
    cin>>word;
    int i;
    for(i = 0; i<strlen(word)-1; i++)
    {
        if(word[i] == '(' && word[i+1] == ')')
        {
            sum+=temp;
            i+=1;
        }
        else if(word[i] == '(')
        {
            temp++;
        }
        else
        {
            temp--;
            sum++;
        }
    }
    if(i==strlen(word)-1 && word[i]==')') sum++;
    cout<<sum<<"\n";
    return 0;
}