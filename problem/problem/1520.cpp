/*
TC
input
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
output
3

input
1 10
10 9 8 7 6 5 4 3 2 1
output
1

input
2 5
10 8 6 4 2
9 8 7 6 1
output
4
*/

#include <stdio.h>

static int arr[501][501];
static int num[501][501];
static int N, M;

int dp(int n, int m)
{
	if (num[n][m] != -1)
	{
		return num[n][m];
	}
	num[n][m]=0;
	if (n<N - 1 && arr[n][m]<arr[n + 1][m])
	{
		num[n][m] += dp(n + 1, m);
	}
	if (n>0 && arr[n][m]<arr[n - 1][m])
	{
		num[n][m] += dp(n - 1, m);
	}
	if (m<M - 1 && arr[n][m]<arr[n][m + 1])
	{
		num[n][m] += dp(n, m + 1);
	}
	if (m>0 && arr[n][m]<arr[n][m - 1])
	{
		num[n][m] += dp(n, m -1);
	}
	return num[n][m];
}


void sol_1520() {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			num[i][j] = -1;
		}
	}
	num[0][0] = 1;
	printf("%d\n", dp(N - 1, M - 1));
}
/*
int main()
{
	sol_1520();
	return 0;
}*/