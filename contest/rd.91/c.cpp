#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(a[n-1]!=1){
		printf("1");
		for(i=1;i<n;++i){
			printf(" %d",a[i-1]);
		}
		printf("\n");
	}
	else{
		for(i=0;i<n-1;++i){
			printf("1 ");
		}
		printf("2\n");
	}
	return 0;
}
