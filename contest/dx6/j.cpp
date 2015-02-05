#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char trans(char t){
	if(t>='3' && t<='9'){
		return t-'0';
	}
	switch(t){
		case 'T': return 10;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		case 'A': return 14;
		case '2': return 15;
		case 'X': return 16;
		case 'Y': return 17;
	}
}
string s1,s2;
vector<int> v1[6],v2[6];

bool gao(){
	int flag;
	for(int i=0;i<v1[1].size();++i){
		if(s1.length()==1) return true;
		flag=1;
		for(int j=0;j<v2[1].size();++j){
			if(v2[1][j]>v1[1][i]){
				flag=0;
				break;
			}
		}
		if(v2[4].size()>0 || v2[5].size()>0) flag=0;
		if(flag) return true;
	}

	for(int i=0;i<v1[2].size();++i){
		if(s1.length()==2) return true;
		flag=1;
		for(int j=0;j<v2[2].size();++j){
			if(v2[2][j]>v1[2][i]){
				flag=0;
				break;
			}
		}
		if(v2[4].size()>0 || v2[5].size()>0) flag=0;
		if(flag) return true;
	}

	for(int i=0;i<v1[3].size();++i){
		if(s1.length()==3) return true;
		flag=1;
		for(int j=0;j<v2[3].size();++j){
			if(v2[3][j]>v1[3][i]){
				flag=0;
				break;
			}
		}
		if(v2[4].size()>0 || v2[5].size()>0) flag=0;
		if(flag) return true;
	}
	for(int i=0;i<v1[4].size();++i){
		if(s1.length()==4) return true;
		flag=1;
		for(int j=0;j<v2[4].size();++j){
			if(v2[4][j]>v1[4][i]){
				flag=0;
				break;
			}
		}
		if(v2[5].size()>0) flag=0;
		if(flag) return true;
	}

	if(v1[1].size()>1){
		for(int i=0;i<v1[3].size();++i){
			if(s1.length()==4) return true;
			flag=1;
			if(v2[1].size()>1){
				for(int j=0;j<v2[3].size();++j){
					if(v2[3][j]>v1[3][i]){
						flag=0;
						break;
					}
				}
			}
			if(v2[4].size()>0 || v2[5].size()>0) flag=0;
			if(flag) return true;
		}
	}

	if(v1[2].size()>1){
		for(int i=0;i<v1[3].size();++i){
			if(s1.length()==5) return true;
			flag=1;
			if(v2[2].size()>1){
				for(int j=0;j<v2[3].size();++j){
					if(v2[3][j]>v1[3][i]){
						flag=0;
						break;
					}
				}
			}
			if(v2[4].size()>0 || v2[5].size()>0) flag=0;
			if(flag) return true;
		}
	}

	if(v1[1].size()>2 || v1[2].size()>1){
		for(int i=0;i<v1[4].size();++i){
			if(s1.length()==6) return true;
			flag=1;
			if(v2[1].size()>2 || v2[2].size()>1){
				for(int j=0;j<v2[4].size();++j){
					if(v2[4][j]>v1[4][i]){
						flag=0;
						break;
					}
				}
			}
			if(v2[4].size()>0 || v2[5].size()>0) flag=0;
			if(flag) return true;
		}
	}
	if(v1[5].size()>0) return true;
	return false;
}

int main(){
	int T;
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>s1>>s2;
		for(int i=0;i<6;++i){
			v1[i].clear();
			v2[i].clear();
		}
		int len=s1.length();
		for(int i=0;i<len;++i){
			s1[i]=trans(s1[i]);
		}
		sort(s1.begin(),s1.end());

		/*for(int i=0;i<len;++i){
		  cout<<(int)s1[i]<<' ';
		  }
		  cout<<endl;*/

		string tmp="";
		for(int i=0;i<len;++i){
			if(tmp==""){
				tmp+=s1[i];
			}
			else if(s1[i]==s1[i-1]){
				tmp+=s1[i];
			}
			else{
				int sz=tmp.length();
				for(int j=1;j<=sz;++j){
					v1[j].push_back((int)tmp[0]);
				}
				tmp="";
				tmp+=s1[i];
			}
		}
		int le=tmp.length();
		for(int i=1;i<=le;++i){
			v1[i].push_back((int)tmp[0]);
		}

		if(len>=2 && s1[len-1]==17 && s1[len-2]==16){
			v1[5].push_back((int)s1[len-1]);
		}

		/*for(int i=1;i<6;++i){
		  cout<<i<<':';
		  for(int j=0;j<v1[i].size();++j){
		  cout<<v1[i][j]<<' ';
		  }
		  cout<<endl;
		  }
		  cout<<"!!!"<<endl;*/

		/*********************************************/

		len=s2.length();
		for(int i=0;i<len;++i){
			s2[i]=trans(s2[i]);
		}
		sort(s2.begin(),s2.end());

		/*for(int i=0;i<len;++i){
		  cout<<(int)s2[i]<<' ';
		  }
		  cout<<endl;*/

		tmp="";
		for(int i=0;i<len;++i){
			if(tmp==""){
				tmp+=s2[i];
			}
			else if(s2[i]==s2[i-1]){
				tmp+=s2[i];
			}
			else{
				int sz=tmp.length();
				for(int j=1;j<=sz;++j){
					v2[j].push_back((int)tmp[0]);
				}
				tmp="";
				tmp+=s2[i];
			}
		}
		le=tmp.length();
		for(int i=1;i<=le;++i){
			v2[i].push_back((int)tmp[0]);
		}

		if(len>=2 && s2[len-1]==17 && s2[len-2]==16){
			v2[5].push_back((int)s2[len-1]);
		}

		/*for(int i=1;i<6;++i){
		  cout<<i<<':';
		  for(int j=0;j<v2[i].size();++j){
		  cout<<v2[i][j]<<' ';
		  }
		  cout<<endl;
		  }*/

		/*********************************************/
		if(gao()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
