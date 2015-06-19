#include<iostream>
#include<cstdio>
using namespace std;
const int N=10005;
char str[N];
bool vis[N];
bool ok(int sum,int n,int mod){
	for(int i=0;i<n-1;++i){
		sum=sum*2%mod;
		if(vis[sum]) return false;
	}
	return true;
}
bool dfs(int sum,int len,int n,int mod){
	if(len+n-1==mod){
		//cout<<"!"<<endl;
		if(ok(sum,n,mod)) return true;
		return false;
	}
	for(int i=0;i<=1;++i){
		int tmp=sum*2%mod+i;
		if(vis[tmp]) continue;
		//cout<<len<<' '<<tmp<<' '<<i<<endl;
		vis[tmp]=1;
		str[len+n-1]=i+'0';
		if(dfs(tmp,len+1,n,mod)) return true;
		str[len+n-1]=0;
		vis[tmp]=0;
	}
	return false;
}
void gao(int n){
	int max_len=(1<<n);
	printf("%d ",max_len);
	for(int i=0;i<n;++i)
		str[i]='0';
	vis[0]=1;
	dfs(0,1,n,max_len);
	puts(str);
}
int main(){
	int n;
	scanf("%d",&n);
	gao(n);
	return 0;
}
