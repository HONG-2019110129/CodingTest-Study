#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x;
vector<int> v;

// 전위순회: 50 30 24 5 28 45 98 52 60      =>NLR
//         루트 l l  l  l  l r  r  r
// 후위순회                                 =>LRN
void postOrder(int st, int en){
	if(st >= en) return; // 더 크면 오른쪽 서브트리이므로 return
	if(st == en-1){    // 오른쪽 서브트리가 되기 직전이므로 원소 출력후 return
		cout << v[st] << '\n';
		return;
	}
	int idx = st + 1;
	while(idx < en){
		if(v[st] < v[idx]) break;
		idx++;
	}
	postOrder(st+1, idx); //왼쪽 서브트리
	postOrder(idx, en); //오른쪽 서브트리
	cout << v[st] << '\n'; //마지막으로 루트 노드 출력
	return;
}

int main(void) {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    
	while(cin >> x){    //엔터가 두번 들어오면 종료
		v.push_back(x);
	}
    
	postOrder(0, v.size());    // 최초에는 모든 전위순회를 넣는다.
	return 0;
}