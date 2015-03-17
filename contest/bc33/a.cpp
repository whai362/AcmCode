#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
char tab[37];
char ans[205],str[205];
int h[300];
void add(int b){
	int p=203;
	int len=strlen(str);
	for(int i=len-1;i>=0;--i,--p){
		if(ans[p]==0){
			//ans[p]=str[i];
			ans[p]=tab[h[str[i]]%b];
		}
		else{
			ans[p]=tab[(h[ans[p]]+h[str[i]])%b];
		}
	}
}
int main(){
	int n,b;
	for(int i=0;i<10;++i){
		tab[i]=i+'0';
		h[i+'0']=i;
	}
	for(int i=10;i<36;++i){
		tab[i]=i-10+'a';
		h[i-10+'a']=i;
	}
	while(scanf("%d%d",&n,&b)!=EOF){
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i){
			scanf("%s",str);
			add(b);
		}
		int st=0;
		while(st<=204 && (ans[st]==0 || ans[st]=='0')) ++st;
		if(st>=204) puts("0");
		else puts(ans+st);
	}
	return 0;
}
