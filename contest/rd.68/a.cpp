#include<cstdio>
using namespace std;
int main(){
	int a,c1=0,c2=0,i,l,n,m,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		if(a>0) ++c1;
		else ++c2;
	}
	for(i=0;i<m;++i){
		scanf("%d%d",&l,&r);
		if((r-l+1)%2==0 && (r-l+1)/2<=c1 && (r-l+1)/2<=c2)
		  printf("1\n");
		else
		  printf("0\n");
	}
	return 0;
}
