#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int ans=0,d,i,n,tmp1,tmp2,a[2005];
	scanf("%d",&d);
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;++i){
		ans+=d-a[i];
	}
	printf("%d\n",ans);
	return 0;
}
