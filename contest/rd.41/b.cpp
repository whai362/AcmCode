#include<cstdio>
using namespace std;
int l[100005],r[100005];
int main(){
	int i,n,min=0x3f3f3f3f,max=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]<min) min=l[i];
		if(r[i]>max) max=r[i];
	}
	for(i=1;i<=n;++i){
		if(l[i]==min && r[i]==max){
			printf("%d\n",i);
			break;
		}
	}
	if(i>n) printf("-1\n");
	return 0;
}
