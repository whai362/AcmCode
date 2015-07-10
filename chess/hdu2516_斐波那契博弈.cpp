#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=55;

LL fa[N];
void predo(){
	fa[0]=fa[1]=1;
	for(int i=2;i<N;++i)
		fa[i]=fa[i-1]+fa[i-2];
}

int main(){
	predo();
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		bool flag=0;
		for(int i=0;i<N;++i){
			if(fa[i]==n){
				flag=1;
				break;
			}
		}
		if(flag) puts("Second win");
		else puts("First win");
	}
	return 0;
}
