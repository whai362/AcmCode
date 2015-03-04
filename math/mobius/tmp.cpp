#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	for(int i=0;i<10;++i){
		a[i]=i;
		if(a[i]==3) ++a[i];
	}
	sort(a,a+10,cmp);
	for(int i=0;i<10;++i){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	int ans=lower_bound(a,a+10,3)-a;
	cout<<ans<<endl;
	return 0;
}
