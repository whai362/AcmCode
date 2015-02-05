#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char m1[105][105],m2[105][105];
int main(){
	int n,m,k;
	char s1[10],s2[10];
	while (~scanf("%d%d%d",&n,&m,&k),n|m|k){
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		int p,x,y;
		scanf("%d",&p);
		for(int i=0;i<p;++i){
			scanf("%s%d%s%d",s1,&x,s2,&y);
			if(s1[0]=='c'){
				m1[x][y]=1;
			}
			else{
				m2[x][y]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				for(int l=1;l<=k;++l){
					if(m1[i][j]==0 && m2[j][l]==0) ++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
}
