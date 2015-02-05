#include<iostream>
#include<cstdio>
using namespace std;
string name1,name2,ans;
int get_(string str){
	int len=str.length();
	for(int i=0;i<len;++i){
		if(str[i]=='_') return i+1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int i1,i2;
	while(cin>>name1>>name2){
	i1=get_(name1);
	i2=get_(name2);
	//cout<<i1<<' '<<i2<<endl;
	ans=name1.substr(i1,name1.length()-i1)+"_small_"+name2.substr(i2,name2.length()-i2);
	cout<<ans<<endl;
	}
	return 0;
}
