#include<cstdio>
using namespace std;
int n,a[50005],max1[50005],max2[50005];
void tomax1(){
	int i,maxx,tmp;
	maxx=tmp=max1[0]=a[0];
	for(i=1;i<n;++i){
		tmp+=a[i];
		if(tmp<a[i]) tmp=a[i];
		if(tmp>maxx) maxx=tmp;
		max1[i]=maxx;
	}
	return ;
}

void tomax2(){
	int i,maxx,tmp;
	maxx=tmp=max2[n-1]=a[n-1];
	for(i=n-2;i>=0;--i){
		tmp+=a[i];
		if(tmp<a[i]) tmp=a[i];
		if(tmp>maxx) maxx=tmp;
		max2[i]=maxx;
	}
	return ;
}

int main(){
	int ans,i,t,tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=-99999999;
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		tomax1();
		tomax2();
		for(i=0;i<n-1;++i){
			tmp=max1[i]+max2[i+1];
			if(tmp>ans) ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
