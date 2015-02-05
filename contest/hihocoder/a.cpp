#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 1000005
int n,m,cnt;
int h1[N],h2[N],type1[N],type2[N];
bool ok(int x){
	int i;
	for(i=2*x-1;i<=n;++i){
		if(type1[i]) return true;
	}
	return false;
}
int main(){
	int a,b,cas=0,t;
	int i;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	cnt=0;
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	memset(type1,0,sizeof(type1));
	memset(type2,0,sizeof(type2));
	for(i=0;i<n-1;++i){
		scanf("%d%d",&a,&b);
		++h1[a];
		++h1[b];
	}
	for(i=1;i<=n;++i)
		++type1[h1[i]];
	scanf("%d",&m);
	for(i=0;i<m-1;++i){
		scanf("%d%d",&a,&b);
		++h2[a];
		++h2[b];
	}
	if(m<=2) printf("Case %d: NO\n",++cas);
	else{
		for(i=1;i<=m;++i)
			++type2[h2[i]];
		for(i=1;i<=m;++i)
			if(type2[i]) ++cnt;
		if(cnt==2 && (type2[1] && type2[m-1]==1) && ok(m-1))
			printf("Case %d: NO\n",++cas);
		else printf("Case %d: YES\n",++cas);
	}
	}
	return 0;
}
