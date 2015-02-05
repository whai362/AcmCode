#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int ans=0,i,n,l;
	char a[2005];
	scanf("%d%s",&n,a);
	l=strlen(a);
	for(i=n;i<l;i=i+n){
		if(a[i-1]==a[i-2] && a[i-2]==a[i-3]) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
