#include<cstdio>
#include<iostream>
using namespace std;
#define N 30005
int a[N],sum1[N],sum2[N];
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	if(a[0]==1)
		sum1[0]=1;
	for(i=1;i<n;++i){
		if(a[i]==1) sum1[i]=sum1[i-1]+1;
		else sum1[i]=sum1[i-1];
	}
	if(a[n-1]==2)
		sum2[n-1]==1;
	for(i=n-2;i>=0;--i){
		if(a[i]==2) sum2[i]=sum2[i+1]+1;
		else sum2[i]=sum2[i+1];
	}
	/*for(i=0;i<n;++i){
		cout<<sum2[i]<<' ';
	}*/
	//cout<<endl;
	int ans_i,_max=0;
	for(i=0;i<n;++i){
		int tmp=sum1[i]+sum2[i]-1;
		if(tmp>_max){
			_max=tmp;
			ans_i=i;
		}
	}
	int ans=0;
	for(i=0;i<ans_i;++i){
		if(a[i]!=1) ++ans;
	}
	for(i=ans_i+1;i<n;++i){
		if(a[i]!=2) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}
