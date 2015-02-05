#include<iostream>
using namespace std;
int main(){
	int i,a,b,c,n,m=1,min=0,max=0;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		m=1,max=0,min=0;
		for(i=0;i<a;++i){
			min=min+m*300;
			m=m+2;
		}
		for(i=0;i<b;++i){
			min=min+m*100;
			m=m+2;
		}
		for(i=0;i<c;++i){
			min=min+m*50;
			m=m+2;
		}
		cout<<min<<' ';
		m=1;
		for(i=0;i<c;++i){
			max=max+m*50;
			m=m+2;
		}
		for(i=0;i<b;++i){
			max=max+m*100;
			m=m+2;
		}
		for(i=0;i<a;++i){
			max=max+m*300;
			m=m+2;
		}
		cout<<max<<endl;
	}
	return 0;
	
}
