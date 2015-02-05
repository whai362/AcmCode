#include<cstdio>
using namespace std;
int main(){
	int cnt=0,i,n;
	char a[55];
	scanf("%d%s",&n,a);
	for(i=0;i<n-1;++i){
		if(a[i]==a[i+1]) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
