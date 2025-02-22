#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Circle
{
	int idx;					//원 인덱스
	int x;						//원 x 좌표
	bool leftBoundary;			//왼쪽 경계=true, 오른쪽 경계=false
};

//오른차순 정렬 ㅎ마수
bool up(const Circle& a, const Circle& b)
{
	return a.x < b.x;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N;			//N개의 원
	cin >> N;
	vector<Circle> v;

	for (int i = 0; i < N; ++i)
	{
		int x, r;
		cin >> x >> r;

		v.push_back({ i, x - r, true });
		v.push_back({ i, x + r, false });
	}

	sort(v.begin(), v.end(), up);		//정렬
	
	stack<int> stk;
	for (const auto& c : v) 
	{
		//왼쪽 원 경계->넣기
		if (c.leftBoundary) 
		{
			stk.push(c.idx);
		}

		//오른쪽 원 경계->조건 검사
		else 
		{
			// 스택 비어잇거나 스택 맨 위 원 번호와 현재 원 번호 다르면 이상함(=다른 원 오른쪽 경계면)
			if (stk.empty() || stk.top() != c.idx) 
			{
				cout << "NO";
				return 0;
			}
			stk.pop();
		}
	}

	cout << "YES";
	
	return 0;
}