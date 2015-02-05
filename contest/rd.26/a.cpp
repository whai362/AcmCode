#include<cstdio>
using namespace std;
int n,m,a[55],b[55];
int main(){
	int count=0,i,j,_max=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;++i)
	  for(j=0;j<m;++j){
		  if(b[j]%a[i]==0 && b[j]/a[i]==_max) ++count;
		  else if(b[j]%a[i]==0 && b[j]/a[i]>_max) count=1,_max=b[j]/a[i];
	  }
	printf("%d\n",count);
	return 0;
}
