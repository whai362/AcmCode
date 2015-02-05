#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int cnt;
char num1[15],num2[15],tmp1[15],tmp2[15];
void dfs(int p,int c,int op){
	if(p<0){
		cnt+=c;
		return ;
	}
	if(tmp1[p]!='?'){
		if(op==1){
			//cout<<(int)tmp1[p]<<' '<<(int)tmp2[p]<<endl;
			dfs(p-1,c,1);
		}
		else if(op==0){
			if(tmp1[p]>tmp2[p]){
				//cout<<(int)tmp1[p]<<' '<<(int)tmp2[p]<<endl;
				if(!c) c=1;
				dfs(p-1,c,1);
			}
			else if(tmp1[p]==tmp2[p]) dfs(p-1,c,0);
			else dfs(p-1,c,-1);
		}
		else return ;

	}
	else{
		if(op==1)
			dfs(p-1,10*c,1);
		else if(op==0){
			dfs(p-1,c,0);
			if(!c) c=1;
			dfs(p-1,(9-tmp2[p])*c,1);
		}
		else return ;
	}
}
int main(){
	while(scanf("%s",num1) && num1[0]!='#'){
	scanf("%s",num2);
	memset(tmp1,0,sizeof(tmp1));
	memset(tmp2,0,sizeof(tmp2));
	int len1=strlen(num1),len2=strlen(num2),len=max(len1,len2);
	for(int i=0;i<len1;++i){
		if(num1[i]!='?') num1[i]-='0';
	}
	for(int i=0;i<len2;++i){
		if(num2[i]!='?') num2[i]-='0';
	}
	for(int i=0;i<len;++i){
		tmp1[i]=num1[len-1-i];
		tmp2[i]=num2[len-1-i];
	}
	cnt=0;
	dfs(len-1,0,0);
	cout<<cnt<<endl;
	}
	return 0;
}
