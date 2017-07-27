//1st trial with mergesort
//하지만 잘 안된다... 틀렸습니다가 나오는걸 보니 timeout 혹은 sort가 잘못된거 같다.
/*
#include <stdio.h>
int time[100000][2];
int temp[100000][2];

void mergesort(int start, int end)
{
	if (end - start == 0)
	{
		temp[start][0] = time[start][0];
		temp[start][1] = time[start][1];
		return;
	}
	else if (end - start == 1)
	{
		if (time[start][1] > time[end][1])
		{
			temp[start][0] = time[end][0];
			temp[start][1] = time[end][1];
			temp[end][0] = time[start][0];
			temp[end][1] = time[start][1];
		}
		else
		{
			temp[start][0] = time[start][0];
			temp[start][1] = time[start][1];
			temp[end][0] = time[end][0];
			temp[end][1] = time[end][1];
		}
	}
	else
	{
		mergesort(start, (start + end) / 2);
		mergesort((start + end) / 2 + 1, end);
		int i = start, j = (start + end) / 2 + 1;
		int index = start;
		while (index != end + 1)
		{
			if (i > (start + end) / 2 && j <= end)
			{
				temp[index][0] = time[j][0];
				temp[index][1] = time[j][1];
				j++;
			}
			else if (j > end && i <= (start + end) / 2)
			{
				temp[index][0] = time[i][0];
				temp[index][1] = time[i][1];
				i++;
			}
			else
			{
				if (time[i][1] < time[j][1])
				{
					temp[index][0] = time[i][0];
					temp[index][1] = time[i][1];
					i++;
				}
				else
				{
					temp[index][0] = time[j][0];
					temp[index][1] = time[j][1];
					j++;
				}
			}
			index++;
		}
	}
	int k;
	for (k = start; k <= end; k++)
	{
		time[k][0] = temp[k][0];
		time[k][1] = temp[k][1];
	}
}


int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &time[i][0], &time[i][1]);
	}
	mergesort(0, n - 1);
	int cnt = 0, end = -1;
	for (i = 0; i < n; i++)
	{
		if (time[i][0] == time[i][1])
			cnt++;
		else
		{
			if (end <= time[i][0])
			{
				cnt++;
				end = time[i][1];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/

//2nd trial with quicksort
/*
algorithm의 sort는 기본적으로 qsort로 nlogn을 보장해준다.
문제의 조건중에
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
이 있기 때문에 단순히 interval scheduling algorithm을 적용시키는 것이아니라 end time이 같을 때 start time을 고려해주어야한다.

*/
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

static struct plan
{
	int start;
	int end;
};

static vector<plan> input;

bool comp(const plan& a, const plan& b)
{
	if (a.end < b.end)
		return true;
	else if (a.end == b.end)
	{
		return a.start < b.start;
	}
	else
		return false;
}

int sol_1931()
{
	plan t;
	int n, i, s, e;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &s, &e);
		t.start = s;
		t.end = e;
		input.push_back(t);
	}
	sort(input.begin(), input.end(), comp);
	int cnt = 0, end = 0;
	for (auto iter = input.begin(); iter != input.end(); iter++)
	{
		if (iter->start == iter->end)
		{
			end = iter->end;
			cnt++;
		}
		else if (iter->start >= end)
		{
			cnt++;
			end = iter->end;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
/*
int main()
{
	sol_1931();
}*/