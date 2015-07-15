#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
char mp[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool ok(int x,int y,int n,int m){
	if(x>=0 && x<n && y>=0 && y<m) return true;
	return false;
}
int dd[]={-1,1};
bool cz(int i,int j,int n,int m){
	int flag=1;
	for(int k=1;k<3;++k){
		int tmpx=i+k;
		int tmpy=j;
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	flag=1;
	for(int k=1;k<3;++k){
		int tmpx=i;
		int tmpy=j+k;
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	flag=1;
	for(int k=1;k<3;++k){
		int tmpx=i-k;
		int tmpy=j;
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	flag=1;
	for(int k=1;k<3;++k){
		int tmpx=i;
		int tmpy=j-k;
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	flag=1;
	for(int k=0;k<2;++k){
		int tmpx=i+dd[k];
		int tmpy=j;
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	flag=1;
	for(int k=0;k<2;++k){
		int tmpx=i;
		int tmpy=j+dd[k];
		if(!ok(tmpx,tmpy,n,m)){
			flag=0;
			break;
		}
		if(mp[i][j]!=mp[tmpx][tmpy]){
			flag=0;
			break;
		}
	}
	if(flag) return true;
	return false;
}
void print(int n){
	for(int i=0;i<n;++i){
		cout<<mp[i]<<endl;
	}
	cout<<endl;
}
int deal(int x,int y,int n,int m){
	int ret=0;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i];
		int tmpy=y+dy[i];
		if(!ok(tmpx,tmpy,n,m)) continue;
		swap(mp[x][y],mp[tmpx][tmpy]);
		if(cz(tmpx,tmpy,n,m))
			++ret;
		swap(mp[x][y],mp[tmpx][tmpy]);
	}
	return ret>0;
}
void gao(int n,int m){
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			//cout<<i<<' '<<j<<' '<<deal(i,j,n,m)<<endl;
			//if(deal(i,j,n,m)>0)
			//	cout<<i<<' '<<j<<' '<<deal(i,j,n,m)<<endl;
			//print(n);
			ans+=deal(i,j,n,m);
			//print(n);
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%s",mp[i]);
		}
		//cout<<cz(n,m)<<endl;
		printf("Case #%d: ",++cas);
		gao(n,m);
	}
	return 0;
}
