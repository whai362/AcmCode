#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int count=0,i,flag=0,n,m,a[3005];
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=0;i<m;++i)
	  scanf("%d",&a[i]);
	sort(a,a+m);
	for(i=0;i<m;++i){
		if((a[i]+1==a[i+1] && a[i+1]+1==a[i+2]) || a[0]==1 || a[m-1]==n){
			flag=1;
			break;
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}
