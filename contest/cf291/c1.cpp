#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
set<string> _set;
set<string>::iterator it;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	string str;
	cin>>n>>m;
	int maxl=0;
	for(int i=0;i<n;++i){
		cin>>str;
		_set.insert(str);
	}
	for(int i=0;i<m;++i){
		cin>>str;
		bool flag=false;
		if(str.length()>1000){
			for(it=_set.begin();it!=_set.end();++it){
				if(it->length()==str.length()){
					int cnt=0;
					for(int i=0;i<str.length();++i){
						if((*it)[i]!=str[i]){
							++cnt;
							if(cnt>1) break;
						}
					}
					if(cnt==1){ flag=true; break; }
				}
			}
		}
		else
			for(int j=0;j<str.length();++j){
				char bl=str[j];
				for(int k=0;k<3;++k){
					if(k==bl-'a') continue;
					str[j]=k+'a';
					if(_set.find(str)!=_set.end()){
						flag=true;
						break;
					}
				}
				str[j]=bl;
				if(flag) break;
			}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
