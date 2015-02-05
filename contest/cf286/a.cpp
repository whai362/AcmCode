#include<iostream>
#include<cstdio>
using namespace std;
const int N=30000;
int mp[N];
struct data{
	int v,n;
}d[N];
int maxa,c[N];
bool cmp(data a,data b){
	return a.v<b.v;
}
int lowbit(int x){ return x&-x; }
int _sum(int x){
	int s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x,int t){
	while(x<=maxa){
		c[x]+=t;
		x+=lowbit(x);
	}
}

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		++mp[a];
	}
	maxa=a;
	int ans=0,tmp;
	for(int i=d;i<=a;++i){
		if(mp[i])
			update(i,mp[i]);
		tmp=_sum(i);
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}
