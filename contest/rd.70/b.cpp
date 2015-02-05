//#184 div2 B
#include<iostream>
using namespace std;
int main(){
	int i,n,f=0;
	__int64 p,q,t,a[100];
	cin>>p>>q>>n;
	for(i=0;i<n;++i){
		cin>>a[i];
		if(f || (q && a[i]>p/q)) f=1;
		else{
			p-=a[i]*q;
			t=p,p=q,q=t;
		}
	}
	if(!f && !q) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
