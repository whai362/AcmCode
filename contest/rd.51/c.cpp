#include<cstdio>
#include<cstring>
using namespace std;
char s[1000005];
int p[1000005];
int main(){
	int i,l,r,len;
	scanf("%s",s);
	len=strlen(s);
	l=0,r=len-1;
	for(i=0;i<len;++i){
		if(s[i]=='l')
		  p[r--]=i;
		else
		  p[l++]=i;
	}
	for(i=0;i<len;++i){
		printf("%d\n",p[i]+1);
	}
	return 0;
}
