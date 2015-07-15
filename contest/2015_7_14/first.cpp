#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=55;
int a[N],b[N];
int main(){
	int n,m;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int sum1=0,sum2=0;
		for(int i=0;i<n-1;++i){
			scanf("%d",&a[i]);
			sum1+=a[i];
		}
		for(int i=0;i<m;++i){
			scanf("%d",&b[i]);
			sum2+=b[i];
		}
		int high,low;
		high=sum1/(n-1);
		if(sum1%(n-1)==0) --high;
		low=sum2/m;
		++low;
		cout<<low<<' '<<high<<endl;
	}
	return 0;
}
