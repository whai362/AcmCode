#include<fstream>
//#include<iostream>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
int main(){
	int i,n,m;
	cin>>n>>m;
	if(n>=m){
		while(n || m){
			if(n) cout<<'B',n--;
			if(m) cout<<'G',m--;
		}
	}
	else{
		while(n || m){
			if(m) cout<<'G',m--;
			if(n) cout<<'B',n--;
		}
	}
	cout<<endl;
	return 0;
}
