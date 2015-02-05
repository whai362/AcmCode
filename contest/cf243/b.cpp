#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string a[105];
int main(){
	int n,m;
	int i;
	cin>>n>>m;
	getchar();
	for(i=0;i<n;++i){
		getline(cin,a[i]);
	}
	if(n%2) cout<<n<<endl;
	else{
		int tmp=n;
		while(!(tmp%2)){
			for(i=0;i<tmp/2;++i){
				//cout<<a[i]<<' '<<a[tmp-1-i]<<endl;
				if(a[i]!=a[tmp-1-i]) break;
			}
			//cout<<i<<endl;
			if(i<tmp/2) break;
			else tmp/=2;
		}
		cout<<tmp<<endl;
	}
	return 0;
}
