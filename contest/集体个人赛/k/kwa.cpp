#include<iostream>
using namespace std;
int main(){
	int i,j,t,n,m,temp,count=0,sum=0,a[110],c[110];
	cin>>t;
	while(t--){
		cin>>n;
		count=0,sum=0;
		for(i=1;i<n;++i) cin>>a[i];
		for(i=1;i<n;++i) cin>>c[i];
		if(n%2==0) m=n/2;
		else m=(n+1)/2;
		for(i=1;i<n-1;++i)
			for(j=i+1;j<n;++j){
				if((c[i]>c[j]&&a[i]!=1)||a[j]==1){
					temp=c[i],c[i]=c[j],c[j]=temp;
					temp=a[i],a[i]=a[j],a[j]=temp;
				}
			}
		for(i=1;i<n;++i){
			if(a[i]!=1) sum=sum+c[i];
			++count;
			if(count==m) break;
		}
		cout<<sum<<endl;
	}
	
}
