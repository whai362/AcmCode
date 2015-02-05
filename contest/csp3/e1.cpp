#include<cstdio>
using namespace std;
int a[]={1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",a[n-1]);
	}
	return 0;
}
