#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
const int N=200005;
int a[N];
int h[1000005];
bool vis[1000005];
int mp[1000005];
void predo(int x){
	//int lim=sqrt(x);
	//cout<<x<<':'<<endl;

	memset(vis,0,sizeof(vis));
	for(int i=0;a[i]<x;++i){
		if(vis[a[i]]) continue;
		int t1=x/a[i];
		int t2=x%a[i];
		int t3=x%t1;
		//cout<<a[i]<<' '<<t2<<endl;
		//cout<<t1<<' '<<t3<<endl;
		mp[a[i]]=max(mp[a[i]],t2);
		if(h[t1]) mp[t1]=max(mp[t1],t3);
		vis[a[i]]=1;
		vis[t1]=1;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(h,0,sizeof(h));
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			h[a[i]]=1;
		}
		sort(a,a+n);
		for(int i=0;i<n;++i){
			predo(a[i]);
		}
		int ans=0;
		for(int i=0;i<n;++i){
			ans=max(ans,mp[a[i]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
