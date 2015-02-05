#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
string op[]={"ADD","SUB","DIV","MUL","MOVE","SET"};
string code[]={"000001","000010","000011","000100","000101","000110"};
string rid[]={
"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010","11011","11100","11101","11110","11111"
};
map<string,string> m1,m2;
map<string,int> m3;
map<int,string> m4;
int main(){
	for(int i=0;i<6;++i){
		m1[op[i]]=code[i];
		m2[code[i]]=op[i];
	}
	for(int i=1;i<=31;++i){
		m3[rid[i]]=i;
		m4[i]=rid[i];
	}
	int t;
	string cmd1,num;
	int cmd2,cmd3;
	ios_base::sync_with_stdio(false);
	while(cin>>t){
	if(t){
		cin>>cmd1;
		cmd2=0;
		//cout<<cmd1<<endl;
		if(cmd1=="SET"){
			cin>>num;
			int len1=num.length();
			for(int i=0;i<len1;++i){
				if(num[i]>='0' && num[i]<='9'){
					cmd2=cmd2*10+num[i]-'0';
				}
			}
			if(m4.find(cmd2)!=m4.end()){
				string ans=m1[cmd1]+m4[cmd2];
				cout<<ans<<endl;
			}
			else{
				puts("Error!");
			}
			continue;
		}
		cin>>num;
		cmd2=0,cmd3=0;
		int len=num.length(),flag=0;
		for(int i=0;i<len;++i){
			if(num[i]>='0' && num[i]<='9'){
				if(flag==0){
					cmd2=cmd2*10+num[i]-'0';
				}
				else{
					cmd3=cmd3*10+num[i]-'0';
				}
			}
			else if(num[i]==','){
				flag=1;
			}
		}

		//cout<<cmd2<<' '<<cmd3<<endl;

		if(m1.find(cmd1)!=m1.end() && m4.find(cmd2)!=m4.end() && m4.find(cmd3)!=m4.end()){
			string ans=m1[cmd1]+m4[cmd2]+m4[cmd3];
			cout<<ans<<endl;
		}
		else{
			puts("Error!");
		}
	}
	else{
		//cout<<t<<endl;
		cin>>cmd1;
		string t1,t2,t3;
		int len=cmd1.length();
		if(len==16){
			t1=cmd1.substr(0,6);
			t2=cmd1.substr(6,5);
			t3=cmd1.substr(11,5);
			//cout<<t1<<' '<<t2<<' '<<t3<<endl;
			if(m2.find(t1)!=m2.end() && m3.find(t2)!=m3.end() && m3.find(t3)!=m3.end()){
				cout<<m2[t1]<<" R"<<m3[t2]<<",R"<<m3[t3]<<endl;
			}
			else{
				puts("Error!");
			}
		}
		else if(len==11){	
			t1=cmd1.substr(0,6);
			t2=cmd1.substr(6,5);
			if(m2[t1]=="SET" && m3.find(t2)!=m3.end()){
				cout<<"SET R"<<m3[t2]<<endl;
			}
			else{
				puts("Error!");
			}
		}
		else{
			puts("Error!");
		}
	}
	}
	return 0;
}
