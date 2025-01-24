#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

stack<int> stck;
unordered_map<string, int> m;    // ��ɾ ���ڷ� ó������ map(switch������ �ڵ� �ۼ��ϱ� ����)

void init();    // map �ʱ�ȭ �Լ�

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string cmd;    // ��ɾ� ����
    init();
    while (n--) {
        cin >> cmd;
        switch (m[cmd]) {
        case 1:    //push
            int x;    // ���� �Է¹ް�
            cin >> x;
            stck.push(x);    // ������ ���ÿ� Ǫ��
            break;
        case 2:    // pop
            if (!stck.empty()) {    // ������ ������� ���� ��
                cout << stck.top() << '\n';    // ���� ���� ���κ� ��Ҹ� �����
                stck.pop();// �ش� ��� ��
            }
            else {    //������ ���������
                cout << "-1\n";    // -1 ���
            }
            break;
        case 3:    // size
            cout << stck.size() << '\n';    // ���� ��� ���� ���
            break;
        case 4:    //empty
            if (!stck.empty()) cout << "0\n";    // ������ ������� ������ 0
            else cout << "1\n";    // ������ ��������� 1
            break;
        case 5:    //top
            if (!stck.empty()) cout << stck.top() << "\n";    // ���� ���� ���κ� ��� ���
            else cout << "-1\n";    // ����ִ� ������ ��� -1 ���
            break;
        }

    }
    return 0;
}

void init() {
    m.insert(make_pair("push", 1));
    m.insert(make_pair("pop", 2));
    m.insert(make_pair("size", 3));
    m.insert(make_pair("empty", 4));
    m.insert(make_pair("top", 5));
}