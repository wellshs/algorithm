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

int sol_1111()
{
	int arr[50];
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
		bool flag=false;
		if (arr[0] == arr[1])
		{
			for (i = 2; i < n; i++)
			{
				if (arr[i] != arr[0])
					flag = true;
			}

			if (flag)
				printf("B\n");
			else
				printf("%d\n", arr[0]);
		}
		else
		{
			if (arr[1] == arr[2])
			{
				a = 0;
				b = arr[1];
			}
			else
			{
				if ((arr[1] - arr[2]) % (arr[0] - arr[1]) != 0)
					flag = true;
				else
				{
					a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
					b = arr[1] - a*arr[0];
				}
			}
			if (flag == false)
			{
				for (i = 3; i < n; i++)
				{
					if (arr[i] != arr[i - 1] * a + b)
						flag = true;
				}
			}
			if (flag)
				printf("B\n");
			else
				printf("%d\n", a*arr[n - 1] + b);
		}
	}
	return 0;
}
/*
int main()
{
	sol_1111();
	return 0;
}
*/