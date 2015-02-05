//Author:Comzyh
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,M;
int f[200000],dis[100000];
int getf(int x)
{
	if (f[x]==x)return x;
	getf(f[x]);
	dis[x]^=dis[f[x]];
	return f[x]=f[f[x]];
}
inline int add(int x,int y,int d)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)
		return (dis[x]^dis[y])==d;
	dis[fx]=d^dis[x]^dis[y];
	f[fx]=fy;
	return 1;
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			f[i]=i;
			dis[i]=0;
		}
		while (M--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			switch(c)
			{
				case 0:
				case 1:
					if (!add(a,b,c))
						printf("da pian zi\n");
					break;
				case 2:
					int fx=getf(a),fy=getf(b);
					if (fx==fy)
					{
						if (dis[a]==dis[b])
							printf("we are a team\n");
						else
							printf("we are not a team\n");
					}
					else
						printf("not sure yet\n");
					break;
			}
		}
	}
	return 0;
}