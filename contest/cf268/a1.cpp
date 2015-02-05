#include<iostream>
#include<cstdio>
using namespace std;
int aa[105];
int main(){
	int n;
	scanf("%d",&n);
	int a,b,u,v;
	scanf("%d",&a);
	for(int i=0;i<a;++i){
		scanf("%d",&u);
		aa[u]=1;
	}
	scanf("%d",&a);
	for(int i=0;i<a;++i){
		scanf("%d",&u);
		aa[u]=1;
	}
	int flag=1;
	for(int i=1;i<=n;++i){
		if(aa[i]==0){
			flag=0;
			break;
		}
	}
	if(flag) puts("I become the guy.");
	else puts("Oh, my keyboard!");
	return 0;
}
