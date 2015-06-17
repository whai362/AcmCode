#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string st[105][15];
int dp[105][15];
char str[105];
int main(){
	scanf("%s",str);
	int len=strlen(str);
	dp[0][(str[0]-'0')%8]=1;
	st[0][(str[0]-'0')%8]=str[0];
	if(!dp[0][0]){
		dp[0][0]=1;
	}
	else{
		puts("YES");
		cout<<str[0]<<endl;
		return 0;
	}
	string ans="";
	for(int i=1;i<len;++i){
		for(int j=0;j<8;++j){
			if(dp[i-1][j]){
				dp[i][(j*10+str[i]-'0')%8]=1;
				st[i][(j*10+str[i]-'0')%8]=st[i-1][j]+str[i];
			}
		}
		for(int j=0;j<8;++j){
			if(dp[i][j]==0){
				dp[i][j]=dp[i-1][j];
				st[i][j]=st[i-1][j];
			}
		}
		//for(int j=0;j<8;++j){
		//	cout<<st[i][j]<<' ';
		//}
		//cout<<endl;
		if(st[i][0].length()>0){
			ans=st[i][0];
			break;
		}
	}
	if(ans.length()==0) puts("NO");
	else{
		puts("YES");
		cout<<ans<<endl;
	}
	return 0;
}
