# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
//int n;
int total = 0;
int n;
int * p = (int *)malloc(n * sizeof(int));
//int p[1024]={0};
void chf (int a, int m);
int main (void)
{
	//int n;
	//int * p = (int *)malloc(n * sizeof(int));
	printf ("请输入数:");
	scanf("%d", &n);
	chf (n, 1);
	printf("共%d种式拆%d\n", total, n);
	return 0;
}
void chf (int a, int m)
{
	int rest, j, i;
	for (i = 1; i <= a; i++)//i <= a;否则rest==0永远立;
	{
		if (i >= p[m -1])
		{
			p[m] = i;
			rest = a - i;
			if (rest == 0 && m > 1)
			{
				total++;
				printf("第%d种:", total);
				for (j = 1; j < m; j++)
				{
					printf("%d+", p[j]);
				}
				printf("%d\n", p[m]);
			}
			else
			{
				chf(rest, m +1);
			}
			p[m] = 0;
		}
	}
}
