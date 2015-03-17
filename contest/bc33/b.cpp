#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool ok(string s){
	for(int i=0;i<s.size();++i){
		int flag=1;
		int ff=0;
		for(int j=1;j<=i;++j){
			if(ff==0){
				if(s[j]>s[j-1]) ff=1;
				else ff=2;
			}
			if(ff==1){
				if(s[j]<s[j-1]){ ff=-1; break; }
			}
			if(ff==2){
				if(s[j]>s[j-1]){ ff=-1; break; }
			}
		}
		if(ff==-1) flag=0;
		ff=0;
		for(int j=i+1;j<s.size();++j){
			if(ff==0){
				if(s[j]>s[j-1]) ff=1;
				else ff=2;
			}
			if(ff==1){
				if(s[j]<s[j-1]){ ff=-1; break; }
			}
			if(ff==2){
				if(s[j]>s[j-1]){ ff=-1; break; }
			}
		}
		if(ff==-1) flag=0;
		if(flag) return true;
	}
	return false;
}
int main(){
	string s="12345678";
	int cnt=1;
	while(next_permutation(s.begin(),s.end())){
		//cout<<s<<' '<<ok(s)<<endl;
		if(ok(s)) ++cnt;
	}
	cout<<cnt<<endl;
}
