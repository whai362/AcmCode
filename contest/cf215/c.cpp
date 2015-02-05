#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
char str[N];
int main(){
	int i,len,l,r,m,tmp1,tmp2,a,b,c;
	scanf("%s",str);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&l,&r);
		len=r-l+1;
		a=b=c=0;
		for(i=l-1;i<=r-1;++i){
			if(str[i]=='x') ++a;
			else if(str[i]=='y') ++b;
			else if(str[i]=='z') ++c;
		}
		tmp1=max(a,b);
		tmp1=max(tmp1,c);
		tmp2=min(a,b);
		tmp2=min(tmp2,c);
		if(tmp1==tmp2 || tmp1==tmp2+1 || r-l<2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
