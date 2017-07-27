#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

struct ICPC
{
	string univ;
	string name;
	int score;
	int penalty;
};


class mycomp //��
{
public:
	bool operator()(ICPC *d1, ICPC *d2) const
	{
		if (d1->score < d2->score) return true; //���ھ ��
		else if (d1->score == d2->score && d1->penalty > d2->penalty) return true;
		//���ھ�� ������� �г�Ƽ���� ������츦 ����
		else return false;
	}
};

int N, K;
priority_queue <ICPC*, vector<ICPC*>, mycomp> pq; //�켱����ť
set <string> s; //�ߺ�Ȯ���� ���� ��
set <string>::iterator it; //����ġ ����

int main(void)
{
	cin >> N >> K;
	ICPC *team;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		team = new ICPC;
		cin >> team->univ;
		cin >> team->name;
		cin >> team->score;
		cin >> team->penalty;
		pq.push(team);
	}
	while (cnt != K)
	{
		it = s.find(pq.top()->univ);
		if (it == s.end())
		{
			cout << pq.top()->name << endl;
			s.insert(pq.top()->univ);
			cnt++;
		}
		pq.pop();
	}
}