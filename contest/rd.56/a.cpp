#include<cstdio>
using namespace std;
int main(){
	int a,cnt=0,i,n,s=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		s+=a;
	}
	for(i=1;i<=5;++i){
		if((s+i)%(n+1)!=1) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
