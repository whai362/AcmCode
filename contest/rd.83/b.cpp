#include<cstdio>
using namespace std;
__int64 a[100005];
int main(){
	int i,m;
	__int64 n,t=0,s=1;
	scanf("%I64d%d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<m;++i){
		if(a[i]>=s) t+=a[i]-s;
		else t+=n-s+a[i];
		s=a[i];
	}
	printf("%I64d\n",t);
}
