#include<iostream>
#include<cstdio>
using namespace std;
bool ok(int x){
	int ret=0;
	while(x){
		if(x & 1) ++ret;
		x/=2;
	}
	return ret==11;
}
int main(){
	int lim=(1<<23);
	int cnt=0;
	for(int i=0;i<lim;++i){
		if(ok(i)){ ++cnt; };
	}
	cout<<cnt<<endl;
}
