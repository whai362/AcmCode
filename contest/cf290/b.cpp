#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define LL __int64
#define MP make_pair
const LL INF=(LL)0x3f3f3f3f*10000;
const int N=305;
int a[N],c[N];
map<int,LL> mp;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;++i){
		scanf("%d",&c[i]);
	}
	LL ans=INF;
	queue< pair<int,LL> > que;
	for(int i=0;i<n;++i){
		LL tmp=mp[a[i]];
		if(!tmp || tmp>c[i]){
			mp[a[i]]=c[i];
			que.push(MP(a[i],(LL)c[i]));
			if(a[i]==1) ans=min(ans,(LL)c[i]);
		}
	}
	while(!que.empty()){
		pair<int,int> now=que.front();
		que.pop();
		for(int i=0;i<n;++i){
			int d=__gcd(now.first,a[i]);
			LL tmp=mp[d];
			if(!tmp || tmp>now.second+c[i]){
				tmp=now.second+c[i];
				mp[d]=tmp;
				que.push(MP(d,tmp));
				if(d==1) ans=min(ans,tmp);
			}
		}
	}
	if(ans==INF) puts("-1");
	else printf("%I64d\n",ans);
	return 0;
}
