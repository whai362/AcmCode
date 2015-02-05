#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int N=30005;
struct Data{
	int sp;
	string str;
};
char str[N];
vector<Data> tags;
vector<Data> words;
int main(){
	int T;
	int isTxt,tagSp,wdSp;
	Data tmp;
	scanf("%d",&T);
	gets(str);
	int cas=0;
	while(T--){
		int flag=0;
		isTxt=tagSp=wdSp=0;
		words.clear();
		tags.clear();
		cout<<"Case #"<<++cas<<":"<<endl;

		while(1){
			gets(str);
			int len=strlen(str);
		
			if(str[0]==0) continue;
			else if(str[0]!='<'){
				for(int i=0;i<tags.size();++i){
					Data tag=tags[i];
					if(tag.str[1]=='/') --tag.sp;
					for(int j=0;j<tag.sp;++j){
						cout<<' ';
					}
					cout<<tag.str<<endl;
				}
				tags.clear();
				tmp.str="";
				if(words.size()==0)
					tmp.sp=tagSp;
				if(str[0]!=32 && str[0]!=9){
					tmp.str+=str[0];
				}
				isTxt=1;
			}
			else{
				for(int i=0;i<words.size();++i){
					Data word=words[i];
					if(i==0){
						for(int j=0;j<word.sp;++j){
							cout<<' ';
						}
						cout<<word.str;
					}
					else{
						cout<<' '<<word.str;
					}
				}
				if(words.size()) cout<<endl;
				words.clear();
				tmp.str="<";
				tmp.sp=tagSp;
				if(str[1]!='/') ++tagSp;
				isTxt=2;
			}

			for(int i=1;i<len;++i){
				if(str[i]=='<'){
					if(isTxt==1){
						if(tmp.str!="") words.push_back(tmp);
						for(int j=0;j<words.size();++j){
							Data word=words[j];
							if(j==0){
								for(int k=0;k<word.sp;++k){
									cout<<' ';
								}
								cout<<word.str;
							}
							else{
								cout<<' '<<word.str;
							}
						}
						if(words.size()) cout<<endl;
						words.clear();
					}
					tmp.str="<";
					tmp.sp=tagSp;
					if(str[i+1]!='/') ++tagSp;
					isTxt=2;
				}
				else if(str[i]=='>'){
					tmp.str+='>';
					tags.push_back(tmp);
					isTxt=0;
				}
				else if(str[i]=='/'){
					tmp.str+='/';
					--tagSp;
				}
				else if(isTxt==1 && (str[i]==32 || str[i]==9)){
					if(tmp.str!="") words.push_back(tmp);
					tmp.str="";
					isTxt=0;
					continue;
				}
				else{
					if(isTxt==0){
						isTxt=1;
						tmp.str="";
						tmp.sp=tagSp;
						for(int i1=0;i1<tags.size();++i1){
							Data tag=tags[i1];
							if(tag.str[1]=='/'){
								--tag.sp;
							}
							for(int i2=0;i2<tag.sp;++i2){
								cout<<' ';
							}
							cout<<tag.str<<endl;
						}
						tags.clear();
					}
					tmp.str+=str[i];
				}
			}
			if(isTxt==1){
				words.push_back(tmp);
			}
			else{
				for(int i=0;i<tags.size();++i){
					Data tag=tags[i];
					if(tag.str[1]=='/') --tag.sp;
					for(int j=0;j<tag.sp;++j){
						cout<<' ';
					}
					cout<<tag.str<<endl;
					if(tag.str=="</html>") flag=1;
					if(flag==1) break;
				}
				tags.clear();
				if(flag==1) break;
			}
		}
	}
	return 0;
}
