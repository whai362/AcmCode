#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
set< pair<string,string> > st;
set< string > s;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	string str;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>str;
		int len=str.length();
		if(len==1){
			s.insert("a");
			s.insert("b");
			s.insert("c");
		}
		if(len==2){
			string cp=str;
			for(int i=0;i<3;++i){
				str[0]=i+'a';
				s.insert(str);
			}
			for(int i=0;i<3;++i){
				cp[1]=i+'a';
				s.insert(cp);
			}
		}
		for(int i=0;i<len;++i){
			//cout<<str.substr(0,i)<<' '<<str.substr(i+1,len-i-1)<<endl;
			st.insert(make_pair(str.substr(0,i),str.substr(i+1,len-i-1)));
		}
	}
	for(int i=0;i<m;++i){
		cin>>str;
		bool ans=false;
		int len=str.length();
		if(len<=2 && s.find(str)!=s.end()) ans=true;
		for(int i=0;i<len;++i){
			if(st.find(make_pair(str.substr(0,i),str.substr(i+1,len-i-1)))!=st.end()){
			   ans=true;
			   break;
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
