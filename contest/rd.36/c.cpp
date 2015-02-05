#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[105][10005];
int b[105];
int main(){
	int i,j,len,n,m,min=0x3f3f3f3f,tmp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%s",s[i]);
	}
	for(i=0;i<n;++i){
		len=strlen(s[i]);
		for(j=0;j<len;++j){
			if(s[i][j]=='1') break;
		}
		if(j==len){
			printf("-1\n");
			return 0;
		}
		b[i]=j;
	}
	for(i=0;i<len;++i){
		tmp=0;
		for(j=0;j<n;++j){
			tmp+=abs(b[j]-i);
		}
		if(tmp<min) min=tmp;
	}
	printf("%d\n",min);
	return 0;
}
