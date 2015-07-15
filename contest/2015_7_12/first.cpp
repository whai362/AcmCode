#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005;
double a[N];
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		double n;
		int m;
		cin>>n>>m;
		double sum=0;
		for(int i=0;i<m;++i){
			cin>>a[i];
			sum+=a[i];
		}
		printf("Case #%d:\n", ++cas);
		for(int i=0;i<m;++i){
			printf("%.6f\n",n*a[i]/sum);
		}
	}
	return 0;
}
