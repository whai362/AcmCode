#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 100005
int dp[N];
int main(){
	char s[N];
	int i,l,m,a,b;
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;++i){
		if(s[i]==s[i+1]) ++dp[i+1];
		dp[i+2]=dp[i+1];
	}
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		printf("%d\n",dp[b-1]-dp[a-1]);
	}
}
