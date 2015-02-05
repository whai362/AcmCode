#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int p[100001];
queue<int>q;

int main()
{
	int n,k,t;
	scanf("%d%d",&n,&k);
	if(n>=k){
		printf("%d\n",n-k);
		return 0;
	}
	memset(p,0,sizeof(p));
	q.push(n);
	p[n]=0;
	while(1)
	{
		t=q.front();
		q.pop();
		if(t==k)
		{
			printf("%d\n",p[t]);
			break;
		}
		if(t-1>=0&&!p[t-1])
		{
			p[t-1]=p[t]+1;
			q.push(t-1);
		}
		if(t+1<=100000&&!p[t+1])
		{
			p[t+1]=p[t]+1;
			q.push(t+1);
		}
		if(t*2<=100000&&!p[t*2])
		{
			p[t*2]=p[t]+1;
			q.push(t*2);
		}
	}
	return 0;
}
