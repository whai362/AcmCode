#include<cstdio>
using namespace std;
int h[35],a[35];
int main(){
	int cnt=0,i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&h[i],&a[i]);
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(a[i]==h[j]) ++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
