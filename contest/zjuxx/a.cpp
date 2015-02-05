#include<cstdio>
using namespace std;
int main(){
	int a,i,n,t,_max,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&_max);
		sum=0;
		for(i=0;i<n;++i){
			scanf("%d",&a);
			sum+=a;
		}
		if(sum>_max) printf("Warning\n");
		else printf("Safe\n");
	}
	return 0;
}
