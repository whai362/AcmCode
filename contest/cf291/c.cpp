#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define MP make_pair
map< pair<string,string>,int > mp;
set< string > st;
string trans(string a){
	string ret;
	int len=a.length();
	for(int i=0;i<len+4;++i){
		char tmp=0;
		for(int j=i;j<min(i+5,len);++j){
			tmp=tmp*3+a[j]-'a';
		}
		ret+=tmp;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	string str;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>str;
		int len=str.length();
		if(len==1){
			string cp=str;
			for(int i=0;i<3;++i){
				cp[0]=i+'a';
				if(cp!=str){ st.insert(cp); }
			}
		}
		else if(len==2){
			string cp1=str,cp2=str;
			for(int i=0;i<3;++i){
				cp1[0]=i+'a';
				if(cp1!=str) st.insert(cp1);
			}
			for(int i=0;i<3;++i){
				cp2[1]=i+'a';
				if(cp2!=str) st.insert(cp2);
			}
		}
		else{
			for(int i=0;i<len;++i){
				string a=trans(str.substr(0,i)),b=trans(str.substr(i+1,len-i+1));
				pair<string,string> pr=MP(a,b);
				int tmp=mp[pr];
				mp[pr]=(tmp|(1<<(str[i]-'a')));
			}
		}
	}
	for(int i=0;i<m;++i){
		cin>>str;
		bool ans=false;
		int len=str.length();
		if(len<=2 && st.find(str)!=st.end()) ans=true;
		else{
			for(int i=0;i<len;++i){
				string a=trans(str.substr(0,i)),b=trans(str.substr(i+1,len-i+1));
				pair<string,string> pr=MP(a,b);
				int tmp=mp[pr];
				if(tmp && tmp^(1<<(str[i]-'a'))){
					ans=true;
					break;
				}
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
