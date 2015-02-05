#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=5000005;
char str[N];
bool vis[N];
int getNum(int n){
	int tmp=0;
	for(int i=n-3;i<=n;++i){
		tmp+=tmp*26+str[i]-'a';
	}
	return tmp;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	memset(str,0,sizeof(str));
	memset(vis,0,sizeof(vis));
	str[0]=str[1]=str[2]=str[3]='z';
	for(int i=4;i<n;++i){
		for(char j='a';j<='z';++j){
			str[i]=j;
			int num=getNum(i);
			if(!vis[num]){
				vis[num]=true;
				break;
			}
		}
	}
	puts(str);
	}
	return 0;
}

