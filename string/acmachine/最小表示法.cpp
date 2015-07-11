/*
ID: usaasu2
PROG:hidden
LANG: C++11
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int L;
char str[100009];
int get_min(char *s)
{
	int i = 0, j = 1;
	int len = strlen(s);
	while (i < len && j < len)
	{
		// printf("i=%4d,j=%4d\n",i,j);
		if (s[i] < s[j % len])
			j++;
		else if (s[i] > s[j % len])
		{
			i = j;
			j = i + 1;
		}
		else
		{
			int k;	//i=0 j=1
			for (k = 1; k < len && s[(i + k) % len] ==  s[(j + k) % len]; k++);
			if (k == len) //出现循环节
				return i;
			cout<<i<<' '<<j<<' '<<k<<endl;
			if (s[(i + k) % len] > s[(j + k) % len])
			{
				i = j;
				j = i + 1;
			}
			else
			{
				j = j + k + 1; // i .. j - 1 和 j 开头的都不是最小表示,
			}
		}
	}
	return i;
}
int main()
{
	//freopen("hidden.in", "r", stdin);
	//freopen("hidden.out", "w", stdout);
	//scanf("%d", &L);
	//for (int i = 0; i < (L + 71) / 72; i++)
	//	scanf("%s", str + i *  72);
	scanf("%s",str);
	printf("%d\n", get_min(str));
	return 0;
}

/*
* @Author: Comzyh
* @Date:   2015-07-11 16:44:47
* @Last Modified by:   Comzyh
* @Last Modified time: 2015-07-11 16:55:23
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
int min_p(const char *s)
{
	int len = strlen(s);
	int i = 0, j = 1, k;
	while (i < len && j < len)
	{
		for (k = 0; k < len && s[(i + k) % len] == s[(j + k) % len]; k++);
		if (k == len)
			return i;
		if (s[(i + k) % len] > s[(j + k) % len])
			i = j++; // i = j; j = i + 1;
		else
			j = j + k + 1;
	}
	return i;
}
int main()
{
	static char str[10009];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &str);
		printf("%d\n", min_p(str) + 1);
	}
	return 0;
}
