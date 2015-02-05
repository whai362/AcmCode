#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int cnt=0,i,j,p,tmp;
	scanf("%d",&p);
	for(i=1;i<p;++i){
		tmp=1;
		for(j=1;j<p;++j){
			tmp=(i*tmp)%p;
			if(tmp==1) break;
		}
		if(tmp==1 && j==p-1) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
