#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int ans=0,i,m,n,d,a[105];
	scanf("%d%d",&n,&d);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	sort(a,a+n);
	if(m>n){
		for(i=0;i<n;++i){
			ans+=a[i];
		}
		ans-=(m-n)*d;
	}
	else{
		for(i=0;i<m;++i){
			ans+=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
