#include<cstdio>
using namespace std;
int main(){
	int i,j,n,k,a[100005];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	j=0;
	for(i=j;i<n;++i){
		if(a[i]!=a[k-1]) continue;
		for(j=i;j<n;++j){
			if(a[j]!=a[k-1]) break;
		}
		if(j==n) break;
	}
	if(i>=j || i+1>k) printf("%d\n",-1);
	else printf("%d\n",i);
	return 0;
}
