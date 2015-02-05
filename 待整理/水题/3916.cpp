#include<cstdio>
using namespace std;
int n,a[100];
int main(){
	int i;
	while(scanf("%d",&n) && n){
		for(i=0;i<n;++i)
		  scanf("%d",&a[i]);
		for(i=0;i<n;++i)
		  if(!i || a[i]!=a[i-1]) printf("%d ",a[i]);
		printf("$\n");
	}
	return 0;
}
