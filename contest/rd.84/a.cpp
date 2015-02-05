#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int x,y,a,b,t,ans;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	t=x*y/__gcd(x,y);
	ans=b/t-a/t;
	if(a%t==0) ++ans;
	printf("%d\n",ans);
	return 0;
}
