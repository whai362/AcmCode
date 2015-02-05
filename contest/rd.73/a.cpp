#include<cstdio>
using namespace std;
int a[10005],b[10005];
int main(){
	int ans,i,j,n;
	scanf("%d",&n);
	ans=n;
	for(i=0;i<n;++i){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(j!=i && b[j]==a[i]){
				--ans;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
