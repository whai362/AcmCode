#include<cstdio>
using namespace std;
int main(){
	int i,j,l,n,k,t;
	scanf("%d%d",&n,&k);
	t=n*(n-1)/2;
	if(t<=k) printf("no solution\n");
	else{
		i=0,j=0;
		for(l=0;l<n;++l){
			printf("%d %d\n",i,j);
			++j;
		}
	}
	return 0;
}
