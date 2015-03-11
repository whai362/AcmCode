#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cnt=9;
	cout<<"1~9"<<endl;
	for(int i=10;i<=n;++i){
		if(i%10!=0 && (i%10)%(i/10)==0){ ++cnt; }
	}
	cout<<"cnt:"<<cnt<<endl;
}
