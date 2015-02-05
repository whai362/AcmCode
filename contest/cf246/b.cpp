#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int x[N],y[N],X[N],Y[N];
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&x[i],&y[i]);
		++X[x[i]];
		++Y[y[i]];
	}
	for(i=0;i<n;++i){
		int tmp=n-1+X[y[i]];
		printf("%d %d\n",tmp,2*(n-1)-tmp);
	}
	return 0;
}
