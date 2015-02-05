#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int main(){
	int cnt=0,a[10];
	for(int i=1;i<32;++i){
		cnt=0;
		memset(a,0,sizeof(a));
		int tmp=i;
		while(tmp){
			a[cnt++]=(tmp%2);
			tmp/=2;
		}
		cout<<"\"";
		for(int i=4;i>=0;--i){
			cout<<a[i];
		}
		cout<<"\",";
	}
}
