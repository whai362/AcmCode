#include<iostream>
#include<cstring>
using namespace std;
int vis[10005],ans[105][11];
void div(int x){
	memset(vis,0,sizeof(vis));
	int now=10;
	while(now && !vis[now]){
		//cout<<"!"<<endl;
		vis[now]=1;
		++ans[x][now/x];
		now=(now%x)*10;
	}
}
int main(){
	int i,sum,n,k;
	for(i=2;i<=100;++i){
		//cout<<i<<endl;
		div(i);
	}
	while(cin>>n>>k){
		sum=0;
		for(i=2;i<=n;++i){
			sum+=ans[i][k];
		}
		cout<<sum<<endl;
	}
	return 0;
}
