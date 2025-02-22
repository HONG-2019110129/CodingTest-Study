#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Circle
{
	int idx;					//�� �ε���
	int x;						//�� x ��ǥ
	bool leftBoundary;			//���� ���=true, ������ ���=false
};

//�������� ���� ������
bool up(const Circle& a, const Circle& b)
{
	return a.x < b.x;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N;			//N���� ��
	cin >> N;
	vector<Circle> v;

	for (int i = 0; i < N; ++i)
	{
		int x, r;
		cin >> x >> r;

		v.push_back({ i, x - r, true });
		v.push_back({ i, x + r, false });
	}

	sort(v.begin(), v.end(), up);		//����
	
	stack<int> stk;
	for (const auto& c : v) 
	{
		//���� �� ���->�ֱ�
		if (c.leftBoundary) 
		{
			stk.push(c.idx);
		}

		//������ �� ���->���� �˻�
		else 
		{
			// ���� ����հų� ���� �� �� �� ��ȣ�� ���� �� ��ȣ �ٸ��� �̻���(=�ٸ� �� ������ ����)
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