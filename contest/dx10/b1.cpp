#include<cstdio>
#include<iostream>
using namespace std;
const int N=100005;
int a[N];
int _abs(int n1){
	if(n1<0) return -n1;
	return n1;
}
int main(){
	int n,cas=0,T;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	int flag=1;
	__int64 ans=1;
	for(int i=1;i<n;++i){
		if(_abs(a[i]-a[i-1])>3) flag=0;
		else if(a[i]==a[i-1] && a[i]!=1) flag=0;
		else if(a[i]==1 && a[i-1]==2) ++ans;
		else if(a[i]==2 && a[i-1]==1) ++ans;
		//cout<<a[i]<<' '<<a[i-1]<<endl;
	}
	//cout<<ans<<endl;
	printf("Case #%d: ",++cas);
	if(!flag) printf("0\n");
	else if(a[n-1]==0) printf("%I64d\n",ans);
	else printf("%I64d\n",2*ans);
	}
	return 0;
}
