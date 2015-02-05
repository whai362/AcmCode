#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
map<string,string> d;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s1,s2;
	for(int i=0;i<m;++i){
		cin>>s1>>s2;
		d[s1]=s2;
	}
	string w,dw;
	for(int i=0;i<n;++i){
		cin>>w;
		int l1=w.length();
		dw=d[w];
		int l2=dw.length();
		if(l1>l2)
			cout<<dw;
		else 
			cout<<w;
		if(i!=n-1) cout<<' ';
		else cout<<endl;
	}
	return 0;
}
