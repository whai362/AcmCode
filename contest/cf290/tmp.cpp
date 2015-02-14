#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct cash{
	int w;
	int v;
}a[100];

int findM(int c,int n)
{
	double maxValue=0;
	int i;
	for(i=0;a[i].w<c;i++)
	{
		maxValue+=a[i].v;
		c-=a[i].w;
	}
	maxValue+=1.0*c/a[i].w*a[i].v;
	return maxValue;
}

bool cmp(cash m,cash n)
{
	return 1.0*m.v/m.w>1.0*n.v/n.w;
}

int main()
{
	int n,c;  //其中n为块个数（一种一个），c为背包容量 
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].w,&a[i].v);
	}
	sort(a,a+n,cmp);
	cout<<findM(c,n)<<endl; 
	return 0;
}
/*测试数据：
3 50
20 60
30 120
10 50
*/ 

