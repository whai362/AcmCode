#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int a,i,n,max=0,hash[1001];
	scanf("%d",&n);
	memset(hash,0,sizeof(hash));
	for(i=0;i<n;++i){
		scanf("%d",&a);
		++hash[a];
		if(hash[a]>max) max=hash[a];
	}
	if(max>(n+1)/2) printf("NO\n");
	else printf("YES\n");
	return 0;
}
