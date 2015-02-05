#include<cstdio>
using namespace std;
int ans[10000][4],c[55],a[55][55];
int main(){
	int cnt=0,i,j,n,tmp;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	  scanf("%d",&c[i]);
	for(i=0;i<n;++i)
	  for(j=1;j<=c[i];++j)
		scanf("%d",&a[j][c[i]]);
	i=j=1;
	while(a[i][j]){
		if(!a[i-1][j] && a[i-1][j]>a[i][j]){
			ans[cnt++][0]=i-1;
		}
	}
}
