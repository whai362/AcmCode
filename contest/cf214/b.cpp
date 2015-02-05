#include<cstdio>
using namespace std;
int k,n,a[100005];
int main(){
	int ans=0,i,j,tmp,sum=0,min=1000000000;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	tmp=n/k;
	for(i=0;i<k;++i){
		sum=0;
		for(j=0;j<tmp;++j){
			sum+=a[(i+j*k)%n];
		}
		if(sum<min) min=sum,ans=i;
	}
	printf("%d\n",ans+1);
	return 0;
}
