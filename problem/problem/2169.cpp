/*
DP로 풀면될거 같다.
방향성까지 기록하게 하면 효과적이다.

TC
input
5 5
10 25 7 8 13
68 24 -78 63 32
12 -69 100 -29 -25
-16 -22 -57 -33 99
7 -76 -11 77 15
output
319

input
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1 
output
25
*/
#include <stdio.h>
static int input[1000][1000];
static int re[1000][1000][3];
static int max(int a, int b)
{
	return a>b ? a : b;
}
int sol_2169()
{
	int i, n, m, j, k, l, ret, temp;
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	re[0][0][0] = input[0][0];
	for (i = 1; i < m; i++)
	{
		re[0][i][0] = re[0][i - 1][0] + input[0][i];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			re[i][j][0] = re[i - 1][j][0] + input[i][j];
			if (j == 0)
				re[i][j][1] = re[i][j][0];
			else
				re[i][j][1] = max(re[i][j - 1][1] + input[i][j], re[i][j][0]);
		}
		for (j = m - 1; j >= 0; j--)
		{
			if (j == m - 1)
				re[i][j][2] = re[i][j][0];
			else
				re[i][j][2] = max(re[i][j + 1][2] + input[i][j], re[i][j][0]);
		}
		for (j = 0; j < m; j++)
		{
			re[i][j][0] = max(re[i][j][0], max(re[i][j][1], re[i][j][2]));
		}
	}
	printf("%d\n", re[n - 1][m - 1][0]);
	/*
	2차원 배열로 풀려고 했으나, 이 경우 N^3의 시간복잡도가 나오게 되므로 timeout에 걸린다 ㅠㅠ
	방향성을 줌으로써 N^2로 바꾸는 방법을 시도해야한다.
	re[0][0] = input[0][0];
	for (i = 1; i<m; i++)
		re[0][i] = re[0][i - 1] + input[0][i];
	for (i = 1; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			ret = re[i - 1][j] + input[i][j];
			for (k = 0; k<j; k++)
			{
				temp = re[i - 1][k];
				for (l = k; l <= j; l++)
				{
					temp += input[i][l];
				}
				ret = max(ret, temp);
			}
			for (k = j + 1; k<m; k++)
			{
				temp = re[i - 1][k];
				for (l = j; l <= k; l++)
				{
					temp += input[i][l];
				}
				ret = max(ret, temp);
			}
			re[i][j] = ret;
		}
	}
	printf("%d", re[n - 1][m - 1]);*/
	return 0;
}