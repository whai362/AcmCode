#include<iostream>
#include<cstdio>
#include<cstring>
int hash[10005];
int main(){
	int T,cas=0;
	int r,n,s,flag;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	memset(hash,0,sizeof(hash));
	for(int i=0;i<n;++i){
		scanf("%d",&r);
		s=10000-(100-r)*(100-r);
		++hash[s];
	}
	int _max=0;
	for(int i=0;i<=10000;++i){
		if(_max<hash[i]) _max=hash[i];
	}
	int cnt=0;
	for(int i=0;i<=10000;++i){
		if(hash[i]==_max) ++cnt;
	}
	printf("Case #%d:\n",++cas);
	if(cnt!=1 && cnt*_max==n){
		puts("Bad Mushroom");
	}
	else{
		int i;
		for(i=0;i<=10000;++i){
			if(hash[i]==_max){
				printf("%d",i);
				break;
			}
		}
		++i;
		for(;i<=10000;++i){
			if(hash[i]==_max){
				printf(" %d",i);
			}
		}
		puts("");
	}
	}
	return 0;
}
