#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
using namespace std;
string words[1005][200];
int num[1005],max_len[200];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(max_len,0,sizeof(max_len));
		memset(num,0,sizeof(num));
		string line;
		int n=0;
		while(getline(cin,line) && line!="@"){
			//cout<<line<<endl;
			if(line=="") continue;
			istringstream strin(line);
			int p=0;
			string word;
			while(strin>>word){
				words[n][p]=word;
				max_len[p]=max(max_len[p],(int)word.size());
				++p;
			}
			num[n++]=p;
		}
		cout<<setiosflags(ios :: left);
		for(int i=0;i<n;++i){
			for(int j=0;j<num[i]-1;++j){
				cout<<setw(max_len[j]+1)<<words[i][j];
			}
			cout<<words[i][num[i]-1]<<endl;
		}
	}
	return 0;
}
