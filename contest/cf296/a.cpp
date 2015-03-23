#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=2*1e5+5;
struct Dt{
	LL x;
	int id;
}a[N],b[N];
int tt[N];
int c[N];
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
int lowbit(int x){ return x&-x; }
int sum(int x){
	int s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x){
	while(x<N){
		++c[x];
		x+=lowbit(x);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	LL u,v;
	for(int i=0;i<n;++i){
		scanf("%I64d%I64d",&u,&v);
		a[i].x=u+v; a[i].id=i;
		b[i].x=u-v; b[i].id=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;++i)
		cout<<a[i].x<<' ';
	cout<<endl;
	tt[a[0].id]=1;
	for(int i=1;i<n;++i){
		tt[a[i].id]=tt[a[i-1].id];
		if(a[i].x!=a[i-1].x){
			++tt[a[i].id];
		}
	}
	for(int i=0;i<n;++i){
		cout<<i<<' '<<tt[i]<<endl;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;++i){
		cout<<b[i].x<<' ';
	}
	cout<<endl;
	int p=0,q=0;
	int ans=0,tmp=0;
	while(p<n && b[q].x>=a[p].x){
		++tmp;
		++p;
	}
	cout<<tmp<<endl;
	ans=max(ans,tmp+1);
	update(tt[b[q].id]);
	++q;
	while(q<n){
		while(p<n && b[q].x>=a[p].x){
			++tmp;
			++p;
		}
		cout<<"sum"<<q<<' '<<b[q].id<<' '<<tt[b[q].id]<<' '<<sum(tt[b[q].id]-1)<<endl;
		ans=max(ans,tmp-sum(tt[b[q].id]-1)+1);
		update(tt[b[q].id]);
		++q;
	}
	printf("%d\n",ans);
	return 0;
}
