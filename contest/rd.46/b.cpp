//#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
int a[100005],cnt[100005],hash[5005];
int main(){
	int c=0x3f3f3f3f,i,j,n,tmp;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	cnt[n-1]=0;
	for(i=n-2;i>=0;--i){
		if(a[i]==a[i+1]) cnt[i]=cnt[i+1];
		else cnt[i]=n-1-i;
	}
	//for(i=0;i<n;++i) cout<<cnt[i]<<' ';
	//cout<<endl;
	j=1;
	for(i=a[0];i<=a[n-1] && j<n;++i){
		if(i<a[j]) hash[i]=cnt[j-1];
		else if(i==a[j]){
			hash[i]=cnt[j];
			for(j;a[j]==a[j+1] && j<n;++j);
			++j;
		}
	}
	//for(i=a[0];i<=a[n-1];++i) cout<<hash[i]<<' ';
	//cout<<endl;
	for(i=0;i<n;++i){
		if(2*a[i]<a[n-1]){
			tmp=i+hash[2*a[i]];
		}
		else{
			tmp=i;
		}
		if(tmp<c) c=tmp;
	}
	cout<<c<<endl;
	return 0;
}
