#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
bool a[N][N];
int n,m;
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]==0){
		return true;
	}
	return false;
}
int gao(int x,int y){
	int ret=1;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(ok(tmpx,tmpy)) ret*=2;
	}
	return ret;
}
int main(){
	int ans,tmp,T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&m);
	ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(i%2){
				if(j%2) a[i][j]=0;
				else a[i][j]=1;
			}
			else{
				if(j%2) a[i][j]=1;
				else a[i][j]=0;
			}
		}
	}
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]){
				ans+=gao(i,j);	
			}
		}
	}
	tmp=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(i%2){
				if(j%2) a[i][j]=1;
				else a[i][j]=0;
			}
			else{
				if(j%2) a[i][j]=0;
				else a[i][j]=1;
			}
		}
	}
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]){
				tmp+=gao(i,j);	
			}
		}
	}
	printf("%d\n",max(ans,tmp));
	}
	return 0;
}
