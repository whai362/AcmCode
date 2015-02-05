#include<cstdio>
#include<iostream>
using namespace std;
#define LL long long
#define N 100005
struct stack{
	int id;
	int v;
}s[N];
int top=-1;
struct node{
	int l,r;
	int h;
}a[N];
int main(){
	int i,j,n;
	int ans,tmp;
	scanf("%d",&n);
	ans=0;
	top=-1;
	s[++top].v=-1;
	s[top].id=0;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i].h);
		for(j=top;j>=0;--j){
			if(a[i].h>=s[j].v) break;
			else a[s[j].id].r=i-1;
		}
		if(a[i].h>s[j].v) a[i].l=s[j].id;
		else a[i].l=a[s[j].id].l;
		top=j;
		s[++top].v=a[i].h;
		s[top].id=i;
	}
	for(i=0;i<=top;++i){
		a[s[i].id].r=n;
	}
	for(i=1;i<=n;++i){
		tmp=(a[i].r-a[i].l)*a[i].h;
		if(tmp>ans) ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}

