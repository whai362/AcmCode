#include<cstdio>
using namespace std;
int main(){
	int cas=0,n;
	while(scanf("%d",&n) && n){
		if(n%2) printf("%d. odd %d\n",++cas,(n-1)/2);
		else printf("%d. even %d\n",++cas,n/2);
	}
	return 0;
}
