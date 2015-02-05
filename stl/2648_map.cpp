#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
const int N=10005;
string str,p;
int s;
map<string,int> mp;
int tab[N];
int main(){
	int n,m;
	ios_base::sync_with_stdio(false);
	while(cin>>n){
		int pos=-1;
		mp.clear();
		memset(tab,0,sizeof(tab));
		for(int i=0;i<n;++i){
			cin>>str;
			mp[str]=i;
			if(pos==-1 && str=="memory") pos=i;
		}
		cin>>m;
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				cin>>s>>p;
				tab[mp[p]]+=s;
			}
			int rk=1;
			for(int i=0;i<n;++i){
				if(tab[i]>tab[pos]) ++rk;
			}
			cout<<rk<<endl;
		}
	}
	return 0;
}
