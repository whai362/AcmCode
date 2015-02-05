#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int count,i,j,n,t,a[305],b[305];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		for(i=1;;++i){
			count=0;
			for(j=0;j<n;++j)
			  b[count++]=a[j]%i;
			sort(b,b+count);
			for(j=0;j<count-1;++j)
			  if(b[j]==b[j+1]) break;
			if(j==count-1) break;
		}
		printf("%d\n",i);
	}
	return 0;
}
