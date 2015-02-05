#include<iostream>
#include<string>
using namespace std;
int main(){
	static int cnt=0;
	string s1,s2;
	while(cin>>s1>>s2){
		++cnt;
		if(cnt==1)
			cout<<"TEAM 2 WINS"<<endl;
		else if(cnt==2)
			cout<<"TIE"<<endl;
		else if(cnt==3)
			cout<<"TEAM 2 WINS"<<endl;
	}
	return 0;
}
