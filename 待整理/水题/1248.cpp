#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ans[10],str[15];
int goal,a[6][13];
bool vis[13];
bool cmp(char a,char b){
	return a>b;
}

int pow(int x,int n){
	int i,ans=1;
	for(i=0;i<n;++i)
		ans*=x;
	return ans;
}

bool dfs(int t,int j){
	int i;
	if(t==goal && j==5) return 1;
	else if(j<5){
		for(i=0;i<strlen(str);++i){
			if(!vis[i] && j<5){
				vis[i]=1;
				ans[j]=str[i];
				if(dfs(t+a[j][i],j+1)) return 1;
				vis[i]=0;
			}
		}
	}
	return 0;
}

int main(){
	int i,j;
	while(scanf("%d%s",&goal,str) && (goal!=0 || strcmp(str,"END"))){
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		sort(str,str+strlen(str),cmp);
		for(i=0;i<strlen(str);++i)
		  for(j=0;j<5;++j){
			if(j%2==0) a[j][i]=pow(str[i]+1-'A',j+1);
			else a[j][i]=-pow(str[i]+1-'A',j+1);
		}
		if(dfs(0,0))
		  printf("%s\n",ans);
		else
		  printf("no solution\n");
	}
	return 0;
}

