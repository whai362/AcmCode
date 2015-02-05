#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int count=0,flag=0,i,n,Min=0x3f3f3f3f,a[100005]={0};
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(a[i]<Min)  Min=a[i];
	}
	for(i=0;i<n;++i){
		if(a[i]==Min) ++flag,count=i+1;
		if(flag>1) break;
	}
	if(flag==1) printf("%d\n",count);
	else printf("Still Rozdil\n");
	return 0;
}
