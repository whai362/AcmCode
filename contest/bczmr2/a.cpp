#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL unsigned long long
const int N=60;
string str[N];
bool ok(string s){
	for(int i=1;i<s.length();++i){
		if(str[s[i-1]-'0'][0]==str[s[i]-'0'][0]) return false;
	}
	return true;
}
void gao(int n){
	string seq="";
	for(int i=0;i<n;++i){
		seq+=char(i+'0');
	}
	//cout<<seq<<endl;
	LL ans=0;
	if(ok(seq)) ++ans;
	while(next_permutation(seq.begin(),seq.end())){
		//cout<<seq<<endl;
		if(ok(seq)) ++ans;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int cas=0;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>str[i];
		}
		cout<<"Case #"<<++cas<<": ";
		gao(n);
	}
	return 0;
}
