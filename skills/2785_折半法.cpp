#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4005;
int n;
int a[N],b[N],c[N],d[N],tab[N*N];
void gao(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			tab[i*n+j]=c[i]+d[j];
		}
	}
	sort(tab,tab+n*n);
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int tmp=-(a[i]+b[j]);
			ans+=upper_bound(tab,tab+n*n,tmp)-lower_bound(tab,tab+n*n,tmp);
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	gao();
	return 0;
}
