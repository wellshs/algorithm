/*
TC
input
4
4 5 5 5 
output
5

input
2
5 5
output
5

input
2
4 5
output
A

input
3
3 5 7
output
9

input
10
1 2 3 3 4 5 6 7 8 9
output
B

input
4
1 4 13 40
output
121

input
1
0
output
A
*/


#include <stdio.h>

int arr[50];
int main()
{
	int i, n, a, b, cura, curb;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (n == 1)
	{
		printf("A\n");
	}
	else if (n == 2)
	{
		if (arr[0] == arr[1])
			printf("%d\n", arr[0]);
		else
			printf("A\n");
	}
	else
	{
		for (i = 0; i < n - 2; i++)
		{
			if (arr[i] == arr[i + 1])
			{
				cura = -999999;
				curb = -999999;
			}
			else
			{
				cura = (arr[i + 1] - arr[i + 2]) / (arr[i] - arr[i + 1]);
				curb = arr[i + 1] - cura*arr[i];
			}
			if (i == 0)
			{
				a = cura;
				b = curb;
			}
			else
			{
				if (a != cura || b != curb)
				{
					if (cura == -999999 && a == 0)
					{
						continue;
					}
					printf("B\n");
					return 0;
				}
			}
		}
		if (a == -999999 && b == -999999)
		{
			printf("%d\n", arr[0]);
		}
		else
		{
			printf("%d\n", a*arr[n - 1] + b);
		}
	}
	return 0;
}