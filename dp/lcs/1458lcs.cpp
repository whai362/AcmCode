#include<stdio.h>
#include<string.h>
int dp[500][500];
void lcs(char str1[],int l1,char str2[],int l2){
	int i,j;
	dp[0][0]=0;;
	for(i=1;i<=l1;++i) dp[i][0]=0;
	for(i=1;i<=l2;++i) dp[0][i]=0;
	for(i=1;i<=l1;++i)
	  for(j=1;j<=l2;++j){
			if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i][j-1];
	  }
}

int main(){
	char str1[500],str2[500];
	int l1,l2;
	while(scanf("%s%s",str1,str2)!=EOF){
		l1=strlen(str1),l2=strlen(str2);
		lcs(str1,l1,str2,l2);
		printf("%d\n",dp[l1][l2]);
	}
	return 0;
}

