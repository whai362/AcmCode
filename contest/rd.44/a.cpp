#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a,b,i,n,ans,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&a,&b);
		if(a==0 && b==1) cnt2+=2,++cnt3,++cnt4;
		else if(a==1 && b==0) cnt1+=2,++cnt3,++cnt4;
		else if(a==0 && b==0) ++cnt1,++cnt2,cnt3+=2;
		else if(a==1 && b==1) ++cnt1,++cnt2,cnt4+=2;
	}
	ans=min(cnt1,cnt2);
	ans=min(ans,cnt3);
	ans=min(ans,cnt4);
	printf("%d\n",ans);
	return 0;
}
