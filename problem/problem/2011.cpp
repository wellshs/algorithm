/*
전형적인 DP문제인듯
조심해야할것
TC
input
20
output
1

input
10
output
1

input
29
output
1

input
25
output
2
*/
#include <stdio.h>
#include <string.h>

void sol_2011()
{
	char arr[5001];
	int ans[5001];
	scanf("%s", arr);
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			if (arr[i] == '0')
				ans[i] = 0;
			else
				ans[i] = 1;
		}
		else if (i == 1)
		{
			if (arr[0] > '2' || (arr[0] == '2' && arr[1] > '6') || arr[1] == '0')
			{
				ans[i] = 1;
			}
			else
				ans[i] = 2;
		}
		else
		{
			if (arr[i - 1] > '2' || (arr[i - 1] == '2' && arr[i] > '6') || arr[i-1] == '0')
			{
				ans[i] = ans[i - 1];
			}
			else if (arr[i] == '0')
			{
				ans[i] = ans[i - 2];
			}
			else
			{
				ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000;
			}
		}
	}
	printf("%d\n", ans[len - 1]);
}
/*
int main()
{
	sol_2011();
	return 0;
}*/