#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 2305
#define M 2305
int a[N],dp1[M][2],dp2[M];
char str[N];
int main(){
	int i,j,n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		memset(dp1,0,sizeof(dp1));
		dp1[0][0]=1;
		for(i=0;i<n;++i){
			for(j=0;j<=m;++j){
				dp1[j][(i+1)%2]=dp1[j][i%2];
				if(j>=a[i]) dp1[j][(i+1)%2]=(dp1[j][(i+1)%2]+dp1[j-a[i]][i%2])%10;
			}
		}
		for(i=0;i<n;++i){
			for(j=0;j<=m;++j){
				if(j>=a[i]){
					dp2[j]=dp1[j][n%2]-dp2[j-a[i]];
					if(dp2[j]<0) dp2[j]+=10;
				}
				else
					dp2[j]=dp1[j][n%2];
				if(j>0) str[j-1]=dp2[j]%10+'0';
			}
			str[j-1]=0;
			printf("%s\n",str);
		}
	}
	return 0;
}

