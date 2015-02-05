#include<iostream>
using namespace std;
int a[1010];
int main(){
	int i,t,n,m,max,ans=0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(i=0;i<n;++i){
			cin>>a[i];
		}
		for(i=0;i<m;++i){
			ans=ans+a[i];
		}
		max=ans;
		if(n!=m){
			for(i=1;i<n;++i){
				ans=ans-a[i-1]+a[(i+m-1)%n];
				if(ans>max) max=ans;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}

