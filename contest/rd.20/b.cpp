#include<cstdio>
using namespace std;
int main(){
	int i,n,p[105];
	double ans;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&p[i]);
	ans=0.0;
	for(i=0;i<n;++i){
		ans=ans+1.0/n*p[i];
	}
	printf("%.12lf\n",ans);
	return 0;
}
