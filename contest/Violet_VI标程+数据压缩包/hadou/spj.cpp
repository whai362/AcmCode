#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[])
{
	int mxs; sscanf(argv[1], "%d", &mxs);
	mxs /= 5;
	FILE *us = fopen(argv[3], "r"), *st = fopen(argv[4], "r");
	int f1 = -1, f2 = -1, x0, y0, x1, y1, ln = 0;
	while (fscanf(us, "%d %d", &x0, &y0) == 2)
	{
		++ln;
		if (fscanf(st, "%d %d", &x1, &y1) == -1)
		{
			f1 = -2;
			break;
		}
		if (x0 != x1)
		{
			if (f1 == -1) f1 = ln;
		}
		if (y0 != y1)
		{
			if (f2 == -1) f2 = ln;
		}
	}
	if (fscanf(st, "%d %d", &x1, &y1) == 2)
	{
		f1 = -3;
	}
	if (f1 == -2)
	{
		printf("0");
	}
	else if (f1 == -3)
	{
		printf("0");
	}
	else
	{
		int ans = 0;
		if (f1 != -1)
		{
		}
		else ans += mxs * 2;
		if (f2 != -1)
		{
		}
		else ans += mxs * 3;
		printf("%d", ans);
	}
	fclose(us), fclose(st);
	return 0;
}
