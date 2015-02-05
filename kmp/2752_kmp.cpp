#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=4e5+5;
char str[N];
int cnt,len,
	ans[N],
	next[N];
void gao(){
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<len){
		if(j==-1 || str[i]==str[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}
int main(){
	while(scanf("%s",str)!=EOF){
		len=strlen(str);
		gao();
		cnt=0;
		int i=len;
		while(i>0){
			ans[cnt++]=i;
			i=next[i];
		}
		for(int i=cnt-1;i>=0;--i){
			printf("%d%c",ans[i],i==0?'\n':' ');
		}
	}
	return 0;
}
