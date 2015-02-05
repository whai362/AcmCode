#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int b[1000];
int main(){
	int cnt=1;
	for(int i=1;i<=4;++i){
		for(int j=1;j<=7;++j){
			b[cnt++]=i*j;	
		}
	}
	sort(b+1,b+cnt);
	for(int i=1;i<cnt;++i){
		cout<<b[i]<<' ';
	}
	cout<<endl;
	return 0;
}
