#include<stdio.h>
#include<string.h>
short dp[5002][5002]; //超内存时可以考虑下short
void lcs(char str1[],int l1,char str2[],int l2){
	int i,j;
	dp[0][0]=0;;
	for(i=1;i<=l1;++i) dp[i][0]=0;
	for(i=1;i<=l2;++i) dp[0][i]=0;
	for(i=1;i<=l1;i++)
		for(j=1;j<=l2;j++){
			if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i][j-1];
		}
}

int main(){
	char str1[5002],str2[5002];
	int i,len;
	scanf("%d%s",&len,str1);
	for(i=1;i<=len;++i) str2[len-i]=str1[i-1];
	lcs(str1,len,str2,len);
	printf("%d\n",len-dp[len][len]);
	return 0;
}


