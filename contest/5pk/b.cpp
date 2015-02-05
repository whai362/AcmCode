#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 1000001
char str[N];
int c[4][N];
int main(){
	int n,k;
	int i,j;
	while(scanf("%d%d",&n,&k)!=EOF){
		scanf("%s",str+1);
		for(i=1;i<=n;++i){
			if(i<=k){
				for(j=1;j<4;++j){
					c[j][i]=0;
				}
				if(str[i]-'0') ++c[str[i]-'0'][i];
			}
			else{
				for(j=1;j<4;++j){
					c[j][i]=c[j][i-k];
				}
				if(str[i]-'0') ++c[str[i]-'0'][i];
			}
		}
		int m,l,r;
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&l,&r);
			r=r-(r-l)%k;
			if(l-k>0)
				printf("%d %d %d\n",c[1][r]-c[1][l-k],c[2][r]-c[2][l-k],c[3][r]-c[3][l-k]);
			else
				printf("%d %d %d\n",c[1][r],c[2][r],c[3][r]);
		}
	}
	return 0;
}
