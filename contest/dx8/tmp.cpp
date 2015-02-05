#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long long x,y;
	cin>>x>>y;
		for(long long j=1;j<=y;++j){
			while(x%j!=0){
				++x;
			}
		}
		cout<<x<<endl;
		cout<<endl;
}

