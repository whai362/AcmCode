#include<iostream>
using namespace std;
int main(){
	int n,c=0,m=2,max=2,x[1000],y[1000];
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
	}
	for(int j=0;j<n-2;++j){
		for(int k=j+1;k<n-1;++k){
			m=2;
			for(int p=k+1;p<n;++p) if((y[p]-y[j])*(x[p]-x[k])==(y[p]-y[k])*(x[p]-x[j])) ++m;
			if(m>max) max=m;
		}
	}
	cout<<max<<endl;
	return 0;
}

