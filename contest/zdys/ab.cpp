#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int abs(int a){
	if(a>=0) return a;
	return -a;
}
int gao(string str){
	int len=str.length();
	int a,b;
	a=b=str[0]-'0';
	for(int i=1;i<len;++i){
		b=abs(str[i]-'0'-b);
	}
	return b;
}
int main(){
	int _max=0,_min=0x3f3f3f3f;
	string str="123456789;",ans1,ans2;
	_max=_min=gao(str);
	ans1=ans2=str;
	while(next_permutation(str.begin(), str.end())){
		int tmp=gao(str);
		if(tmp>_max) _max=tmp,ans1=str;
		if(tmp<_min) _min=tmp,ans2=str;
	}
	cout<<_max<<' '<<ans1<<endl;
	cout<<_min<<' '<<ans2<<endl;
	cout<<char('9'+2)<<endl;
	return 0;
}
