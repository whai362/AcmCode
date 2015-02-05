#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=500005;
bool vis[N];
char str[N];
int num[N];
int getNum(int n){
	int tmp=0;
	for(int i=n-3;i<=n;++i){
		tmp=tmp*26+str[i]-'a';
	}
	return tmp;
}
int main(){
	int n,flag,p;
	while(scanf("%d",&n)!=EOF){
	if(n>=4 && n<456980){
	memset(str,0,sizeof(str));
	memset(vis,0,sizeof(vis));
	str[0]=str[1]=str[2]=str[3]='a';
	char i[N];
	vis[0]=true;
	p=4;
	i[4]='a';
	while(p<n){
		flag=0;
		for(;i[p]<='z';++i[p]){
			str[p]=i[p];
			num[p]=getNum(p);
			if(!vis[num[p]]){
				vis[num[p]]=true;
				++p;
				i[p]='a';
				flag=1;
				break;
			}
		}
		if(flag==0){
			--p;
			while(i[p]=='z')
				--p;
			vis[num[p]]=false;
			++i[p];
		}
	}
	if(flag) puts(str);
	else puts("Impossible");
	}
	else if(n>=456980){
		puts("Impossible");
	}
	else{
		for(int i=0;i<n;++i){
			printf("a");
		}
		puts("");
	}
	}
	return 0;
}
