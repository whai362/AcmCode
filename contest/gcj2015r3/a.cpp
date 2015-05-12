#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		printf("Case #%d: %d\n",++cas,(c+w-1)/w*r+w-1);
	}
	return 0;
}
