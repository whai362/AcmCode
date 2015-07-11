#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=100005;
char str[N];
char out[N];
int ejz[N];
string table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char tab[255];
void trans(char x[]){
	int len=strlen(x);
	memset(ejz,0,sizeof(ejz));
	int ejz_len=0;
	for(int i=0;i<len;++i){
		int tmp=x[i];
		for(int j=7;j>=0;--j){
			if(tmp & (1<<j))
				ejz[ejz_len++]=1;
			else
				ejz[ejz_len++]=0;
		}
	}
	//for(int i=0;i<ejz_len;++i){
	//	cout<<ejz[i];
	//	if((i+1)%6==0) cout<<' ';
	//}
	//cout<<endl;

	int out_len=0;
	for(int i=0;i<ejz_len;i+=6){
		int tmp=0;
		for(int j=i;j<i+6;++j){
			tmp=tmp*2+ejz[j];
		}
		//cout<<tmp<<' ';
		out[out_len++]=tab[tmp];
	}
	//cout<<endl;
	while(out_len%4){
		out[out_len++]='=';
	}
	out[out_len]=0;
}
void gao(int k){
	for(int i=0;i<k;++i){
		trans(str);
		int len=strlen(out);
		for(int j=0;j<len;++j){
			str[j]=out[j];
		}
		str[len]=0;
		//cout<<str<<endl;
	}
	cout<<str<<endl;
}
void predo(){
	for(int i=0;i<table.size();++i){
		tab[i]=table[i];
	}
}
int main(){
	int T;
	int k;
	predo();
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d",&k);
		scanf("%s",&str);
		printf("Case #%d: ",++cas);
		gao(k);
	}
	return 0;
}
