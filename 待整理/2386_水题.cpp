#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
char _map[N][N];
bool vis[15000];
int n,m;
int f[15000];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && _map[x][y]=='W'){
		return true;
	}
	return false;
}
int getFa(int n){
	if(n!=f[n]){
		return f[n]=getFa(f[n]);
	}
	return n;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
	for(int i=0;i<n*m;++i){
		f[i]=i;
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='W'){
				int fp=getFa(i*m+j);
				if(ok(i+1,j)){
					f[getFa((i+1)*m+j)]=fp;
				}
				if(ok(i,j+1)){
					f[getFa(i*m+j+1)]=fp;
				}
				if(ok(i+1,j+1)){
					f[getFa((i+1)*m+j+1)]=fp;
				}
				if(ok(i+1,j-1)){
					f[getFa((i+1)*m+j-1)]=fp;
				}
			}
			else f[i*m+j]=-1;
		}
	}
	int cnt=0;
	for(int i=0;i<m*n;++i){
		//cout<<f[i]<<' ';
		//if((i+1)%m==0) cout<<endl;

		if(f[i]!=-1){
			int fa=getFa(i);
			if(!vis[fa]){
				++cnt;
				vis[fa]=true;
			}
		}
	}
	printf("%d\n",cnt);
	//cout<<cnt<<endl;
	}
	return 0;
}
