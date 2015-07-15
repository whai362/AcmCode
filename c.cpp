#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
const int MOD=1000000007;
#define LL __int64
LL dp1[N][N];
LL dp2[N][N];
int pre[N][N];
int tab[30];
char X[N],Y[N];
void Add(LL &a,LL b){
	a+=b;
	if(a>=MOD)
		a-=MOD;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",X,Y);
		int n=strlen(X);
		int m=strlen(Y);
	
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(tab,0,sizeof(tab));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=m;++i){
			tab[Y[i-1]-'a']=i;
			for(int j=0;j<26;++j){
				pre[i][j]=tab[j];
			}
		}

		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(X[i-1]==Y[j-1]){
					dp1[i][j] = max(dp1[i-1][j-1]+1,max(dp1[i-1][j],dp1[i][j-1]));
				}
				else{
					dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]);
				}
			}
		}

		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j){
				if(dp1[i][j]==0){
					dp2[i][j]=1;
					continue;
				}
				if(dp1[i-1][j] == dp1[i][j]){
					Add(dp2[i][j],dp2[i-1][j]);
				}
				if(pre[j][X[i-1]-'a']){
					int id=pre[j][X[i-1]-'a'];
					if(dp1[i-1][id-1]+1 == dp1[i][j])
						Add(dp2[i][j],dp2[i-1][id-1]);
				}
			}
		}
		printf("%I64d\n",dp2[n][m]);
	}
	return 0;
}
