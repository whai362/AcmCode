#include<iostream>
using namespace std;
long long a[55][2];
int main(){
	int i,n;
	a[0][0]=a[0][1]=3;
	a[1][0]=a[1][1]=6;
	a[2][0]=a[2][1]=6;
	while(cin>>n){
		for(i=3;i<n;++i){
			a[i][0]=a[i-1][0]+a[i-1][1]*2;
			a[i][1]=a[i-1][0];
		}
		cout<<a[n-1][0]<<endl;
	}
	return 0;
}
