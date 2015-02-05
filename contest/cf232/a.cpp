#include<cstdio>
using namespace std;
int hash[105];
int main(){
	int ans=0,i,j,l,ll,r,rr,n;
	scanf("%d",&n);
	scanf("%d%d",&ll,&rr);
	for(i=1;i<n;++i){
		scanf("%d%d",&l,&r);
		for(j=l;j<r;++j){
			hash[j]=1;
		}
	}
	for(i=ll;i<rr;++i){
		if(!hash[i]) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
