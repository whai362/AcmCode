#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int i,n,sum,s[105];
	while(scanf("%d",&n)&&n){
		for(i=0;i<n;++i) scanf("%d",&s[i]);
		sort(s,s+n);
		sum=0;
		for(i=1;i<n-1;++i) sum=sum+s[i];
		printf("%d\n",sum/(n-2));
	}
	return 0;
}
