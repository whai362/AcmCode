#include <iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int st;
	int ed;
}a[25005];
bool cmp(node a,node b)
{
	if(a.st!=b.st)
		return a.st<b.st;
	else
		return a.ed<b.ed;
}
int main()
{
	int n,t,tt=0,ans;
	scanf("%d%d",&n,&t);
	ans=1;
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].st,&a[i].ed);
	sort(a,a+n,cmp);
	/* for(int i=0;i<n;i++)
	   printf("%d %d\n",a[i].st,a[i].ed);*/

	if(a[0].st>1)
		printf("-1\n");
	else
	{   tt=a[0].ed;
		for(int i=1;i<n;i++)
			if(a[i].st<=tt+1&&a[i].ed>a[i-1].ed)
			{

				//cout<<i<<endl;
				if(tt>=t)
					break;
				tt=a[i].ed;
				ans++;
			}
		if(tt>=t)
			printf("%d\n",ans);
		else
			printf("-1\n");

	}
	return 0;
}
