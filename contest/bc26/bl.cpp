#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int cal(string s){
	int _max=0;
	int ret=0;
	for(int i=0;i<s.length();++i){
		if(s[i]>=_max){
			ret+=s[i]-'0';
		}
		_max=max(_max,(int)s[i]);
	}
	return ret;
}
int main(){
	string str="1122334";
	int ans=cal(str);
	cout<<str<<endl;
	//int cnt=1;
	while(next_permutation(str.begin(),str.end())){
		ans+=cal(str);
		//cout<<str<<endl;
		//++cnt;
	}
	cout<<ans<<endl;
	//cout<<cnt<<endl;
}
