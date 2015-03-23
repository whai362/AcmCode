#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=5005;
const int M=200000000;
int a[N];
map<int,int> mp;
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		mp.clear();
		mp[0]=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			for(int j=1;j<=k && j*a[i]<=M;++j){
				if(mp.find(a[i]*j)==mp.end())
					mp[a[i]*j]=j;
				else
					mp[a[i]*j]=min(j,mp[a[i]*j]);
			}
		}
		int q;
		int x;
		scanf("%d",&q);
		while(q--){
			scanf("%d",&x);
			int ans=k+1;
			for(int i=0;i<n;++i){
				for(int j=1;j<=k && j*a[i]<=x;++j){
					int val=x-j*a[i];
					if(mp.find(val)==mp.end()) continue;
					ans=min(ans,j+mp[val]);
				}
			}
			if(ans>k) ans=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}
