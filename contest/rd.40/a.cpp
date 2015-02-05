#include<cstdio>
using namespace std;
int main(){
	int i,y,k,n,flag=0,tmp;
	scanf("%d%d%d",&y,&k,&n);
	tmp=n/k;
	for(int i=1;i<=tmp;++i){
		if(i*k>y) flag=1,printf("%d ",i*k-y);
	}
	if(flag) printf("\n");
	else printf("-1\n");
	return 0;
}
