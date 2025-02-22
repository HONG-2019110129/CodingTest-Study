#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>

using namespace std;

set<string> result;

string removeBracket(const string &str, vector<pair<int, int>> &brackets)
{
	string temp_str = str;
	for (auto &p : brackets)
	{
		temp_str[p.first] = ' ';
		temp_str[p.second] = ' ';
	}

	string final_str;
	for (char c : temp_str)
	{
		if (c != ' ')
			final_str += c;
	}
	return final_str;
}

void dfs(int node_idx, vector<pair<int, int>> &vec, vector<pair<int, int>> &temp, int last_idx, string &str)
{
	if (node_idx == last_idx)
	{
		if (!temp.empty())
		{
			string modified_str = removeBracket(str, temp);
			result.insert(modified_str);
		}
		return;
	}

	// ���� ��ȣ ���� �������� �ʴ� ���
	dfs(node_idx + 1, vec, temp, last_idx, str);

	// ���� ��ȣ ���� �����ϴ� ���
	temp.push_back(vec[node_idx]);
	dfs(node_idx + 1, vec, temp, last_idx, str);
	temp.pop_back(); // ��Ʈ��ŷ
}

void print_set()
{
	for (const auto &res : result)
	{
		cout << res << endl;
	}
}

int main()
{
	string str;
	cin >> str;

	stack<int> temp_stack;
	vector<pair<int, int>> index_pair; // ��ȣ �� ����

	// r��ȣ���� ã�� �����ϱ�
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			temp_stack.push(i);
		}
		else if (str[i] == ')')
		{
			if (!temp_stack.empty())
			{
				index_pair.push_back({temp_stack.top(), i});
				temp_stack.pop();
			}
		}
	}

	vector<pair<int, int>> temp;
	dfs(0, index_pair, temp, index_pair.size(), str);

	print_set();

	return 0;
}
