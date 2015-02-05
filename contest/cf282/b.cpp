#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
int main(){
	LL a,b;
	scanf("%I64d%I64d",&a,&b);
	LL tmp=a-b;
	if(tmp<0) puts("0");
	else if(tmp==0) puts("infinity");
	else{
		int ans=0;
		LL lim=sqrt((double)tmp);
		for(int i=1;i<=lim;++i){
			if(tmp%i==0){
				int tt=tmp/i;
				if(i>b)
					++ans;
				if(tt!=i && tt>b)
					++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
