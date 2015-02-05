#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1005],b[1005];
bool vis[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<n;++i){
		scanf("%d",&b[i]);
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	int p1=0,p2=n-1,ans=0;
	for(int i=0;i<n;++i){
		if(a[p1]>b[i]){
			ans+=200;
			++p1;
		}
		else if(a[p1]==b[i]){
			if(a[p2]<=b[n-1]){
				if(a[p2]<b[i])
					ans-=200;
				++p2;
			}
		}
		else{
			if(a[p2]<b[i])
				ans-=200;
			++p2;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
