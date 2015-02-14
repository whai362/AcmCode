#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;
#define LL __int64
const int INT=2147483647;
int a[1005];
map<LL,int> mp;
int main(){
	int n;
	int ans;
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		mp.clear();
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i]);
			++mp[a[i]];
		}
		sort(a,a+n);
		n=unique(a,a+n)-a;
		ans=0;
		//cout<<n<<endl;
		//cout<<INT_MAX<<endl;
		for(int i=0;i<n;++i){
			if((a[i]+a[(i-1+n)%n])%INT==a[(i+1)%n]) ans+=mp[a[i]];
		}
		if(n==1) ans=-1;
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
