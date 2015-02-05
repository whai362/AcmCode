#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;
set<string> _set;
int main(){
	ios_base::sync_with_stdio(false);
	int n,T,cas=0;
	string s1,s2,s3,tmp;
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s1>>s2>>s3;
		_set.clear();
		int cnt=0,flag=1;
		while(1){
			tmp="";
			for(int i=0;i<n;++i){
				tmp+=s2[i];
				tmp+=s1[i];
			}
			++cnt;
			if(tmp==s3)
				break;
			else if(_set.find(tmp)!=_set.end()){
				flag=0;
				break;
			}
			else{
				_set.insert(tmp);
			}
			s1=tmp.substr(0,n);
			s2=tmp.substr(n,2*n);
		}
		if(flag) cout<<++cas<<' '<<cnt<<endl;
		else cout<<++cas<<' '<<-1<<endl;
	}
	return 0;
}
