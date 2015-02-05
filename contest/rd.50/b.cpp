#include<cstdio>
#include<algorithm>
using namespace std;
int a[55];
int main(){
	int i,n,k,tmp;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i)
	    scanf("%d",&a[i]);
	sort(a,a+n);
	if(k>n) printf("-1\n");
	else{
		tmp=n-1-k;
		if(a[tmp]==a[tmp+1]) printf("-1\n");
		else{
			printf("%d %d\n",a[tmp]+1,0);
		}
	}
	return 0;
}
