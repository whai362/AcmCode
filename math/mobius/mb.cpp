#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

int main(){
	getMu();
	for(int i=1;i<=10;++i){
		cout<<i<<' '<<mu[i]<<endl;
	}
	return 0;
}
