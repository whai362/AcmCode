#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> _map;
string str[1005];
int main(){
	ios_base::sync_with_stdio(false);
	int n,T;
	string ans,tmp,str[15];
	cin>>T;
	while(T--){
		cin>>n;
		cin>>str[0];
		ans="";
		for(int i=1;i<n;++i){
			cin>>str[i];
		}
		int len=str[0].length();
		for(int i=0;i<len;++i){
			for(int j=1;j<=len-i;++j){
				int flag=1;
				tmp=str[0].substr(i,j);
				//cout<<'!'<<tmp<<endl;
				for(int k=1;k<n;++k){
					if(str[k].find(tmp)==string::npos){
						flag=0;
						break;
					}
				}
				if(flag){
					int tlen=tmp.length(),
						alen=ans.length();
					if(tlen>=3){
						if(tlen>alen){
							ans=tmp;
						}
						else if(tlen==alen && ans>tmp){
							ans=tmp;
						}
					}
				}
			}
		}
		if(ans.length()) cout<<ans<<endl;
		else cout<<"no significant commonalities"<<endl;
	}
	return 0;
}
