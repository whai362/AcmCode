#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
#define N 2000005
char s[N];
int main(){
	char *tmp;
	int n,nc,len;
	int i;
	set<string> c;
	scanf("%d%d%s",&n,&nc,s);
	len=strlen(s);
	for(i=0;i<=len-n;++i){
		tmp=new char[n+1];
		strncpy(tmp,s+i,n);
		c.insert(tmp);
	}
	printf("%d\n",c.size());
	return 0;
}

