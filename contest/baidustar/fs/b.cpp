#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n=6;
string str="abcdefghijkl";
bool ok(){
	int i;
	for(i=1;i<n;++i){
		if(str[i]<str[i-1]) return false;
	}
	for(i=n+1;i<2*n;++i){
		if(str[i]<str[i-1]) return false;
	}
	for(i=n;i<2*n;++i){
		if(str[i]<str[i-6]) return false;
	}
	return true;
}
int main(){
    int cnt=1;
    while(next_permutation(str.begin(), str.end())){
        if(ok()) ++cnt;
    }
	cout<<cnt<<endl;
    return 0;
}
