#include<iostream>
#include<cstdio>
using namespace std;
int a[105],a1,a2[105],a3[105],f[105];
int main(){
	int i,n,cnt=0,c1=1,c2=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(a[i]>0) ++cnt;
	}
	for(i=0;i<n;++i){
		if(a[i]<0){
			a1=a[i];
			f[i]=1;
			break;
		}
	}
	if(cnt>0){
		for(i=0;i<n;++i){
			if(a[i]>0){
				a2[c2++]=a[i];
				f[i]=1;
				break;
			}
		}
	}
	else{
		for(i=0;i<n && c2<2;++i){
			if(a[i]<0 && !f[i]){
				a2[c2++]=a[i];
				f[i]=1;
			}
		}
	}
	printf("%d %d\n",c1,a1);
	printf("%d",c2);
	for(i=0;i<c2;++i){
		printf(" %d",a2[i]);
	}
	cout<<endl;
	printf("%d",n-c1-c2);
	for(i=0;i<n;++i){
		if(!f[i]) printf(" %d",a[i]);
	}
	cout<<endl;
	return 0;
}
