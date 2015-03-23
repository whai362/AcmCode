#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL __int64
const int INF=1000005;
int a[105],b[105];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int ans=INF;
		for(int i=0;i<m;++i){
			scanf("%d%d",&a[i],&b[i]);
			int t=n/a[i];
			if(n%a[i]) ++t;
			ans=min(ans,t*b[i]);
		}
		printf("%d\n",ans);

	}
	return 0;
}
