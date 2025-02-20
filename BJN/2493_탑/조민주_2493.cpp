#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<int> castles(n, 0), res(n, 0);
    stack<pair<int, int>> stck; 
    for(int i=0;i<n;i++){
        cin>>castles[i];
        // 자신보다 더 큰 원소를 찾기위해 서칭
        while(!stck.empty()){
            if(stck.top().first>=castles[i]){
                res[i] = stck.top().second + 1;
                stck.push(make_pair(castles[i], i));
                break;
            }
            else{
                stck.pop();
            }
        }
        if(res[i] == 0) stck.push(make_pair(castles[i], i));
    }

    for(int i =0;i<res.size();i++){
        cout<< res[i]<<" ";
    }
}