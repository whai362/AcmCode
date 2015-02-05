#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int i,count=0,n,a[100005],b[100005];
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;++i){
		if(a[i]!=b[i]) ++count;
	}
	if(count<=2) printf("YES\n");
	else printf("NO\n");
	return 0;
}
