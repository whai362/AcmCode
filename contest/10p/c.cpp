#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 100005
int n,b,pos;
int a[N];
long long g[N],l[N];
long long gh[N],lh[N];
int main(){
	long long ans;
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&b);
	ans=0;
	memset(g,0,sizeof(g));
	memset(l,0,sizeof(l));
	memset(gh,0,sizeof(gh));
	memset(lh,0,sizeof(lh));
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(a[i]==b){
			pos=i;
		}
	}
	if(a[0]>b){
		++g[0];
	}
	else if(a[0]<b){
		++l[0];
	}
	for(int i=1;i<n;++i){
		if(a[i]>b){
			g[i]=g[i-1]+1;
			l[i]=l[i-1];
		}
		else if(a[i]<b){
			g[i]=g[i-1];
			l[i]=l[i-1]+1;
		}
		else{
			g[i]=g[i-1];
			l[i]=l[i-1];
		}
	}
	/*for(int i=0;i<n;++i){
		cout<<g[i]<<' '<<l[i]<<endl;
	}*/
	for(int i=pos;i<n;++i){
		if(g[i]-g[pos]>=l[i]-l[pos]){
			++gh[g[i]-g[pos]-(l[i]-l[pos])];
		}
		else{
			++lh[l[i]-l[pos]-(g[i]-g[pos])];
		}
	}
	for(int i=0;i<=pos;++i){
		int gr,le;
		if(i>0){
			gr=g[pos]-g[i-1];
			le=l[pos]-l[i-1];
		}
		else{
			gr=g[pos];
			le=l[pos];
		}
		//cout<<gr-le<<endl;
		if(gr>le){
			ans+=lh[gr-le];
		}
		else{
			ans+=gh[le-gr];
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
