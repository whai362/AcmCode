#include<cstdio>
#include<iostream>
using namespace std;
int a[1005];
int main(){
	int ans_i,cnt,i,j,_max,n,k;
	scanf("%d%d",&n,&k);
	_max=0;
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;++i){
		cnt=0;
		if(a[i]+(0-i)*k<=0) continue;
		for(j=0;j<n;++j){
			if(a[i]+(j-i)*k==a[j]) ++cnt;
		}
		if(cnt>_max) _max=cnt,ans_i=i;
	}
	printf("%d\n",n-_max);
	int t1,t2;
	for(i=0;i<n;++i){
		t1=a[ans_i]+(i-ans_i)*k;
		if(t1!=a[i]){
			t2=t1-a[i];
			if(t2>0) printf("+ ");
			else printf("- "),t2=-t2;
			printf("%d %d\n",i+1,t2);
		}
	}
}	
