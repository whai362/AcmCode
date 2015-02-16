/*codeforces 514C Watto and Mechanism
  题意：
  给出一个包含n个单词的字典，给出m个待查询单词，如果单词在有且仅有一个字符不相同的情况下可以在字典里找到，则输出YES，否则输出NO
  限制：
  0 <= n,m <= 3*10^5; 总字符长度不大于6*10^5
  思路：
  分段暴力。
  以查询单词长度为500分段：
  查询单词长度<500则：采用set查询，复杂度为600*500*500=1.5*10^8
  查询单词长度>500则：暴力查询，复杂度为600*600*500=1.8*10^8
  在复杂度内可以实现。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<tr1/unordered_set>
#include<ctime>
using namespace std;
using namespace std::tr1;
unordered_set<string> _set;
unordered_set<string>::iterator it;
int main(){
	double st=clock(),en;
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
		if(str.length()>500){
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
	en=clock();
	cerr<<(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
