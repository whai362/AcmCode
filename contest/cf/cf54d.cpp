#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int n,k;
char ans[N],name[N],num[N];
char getTc(char str[]){
	int len=strlen(str);
	int flag=0;
	for(int i=1;i<len;++i){
		if(str[i]!=str[i-1]){
			flag=1;
			break;
		}
	}
	if(flag) return str[0];
	else return (str[0]-'a'+1)%k+'a';
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",name);
	scanf("%s",num);
	int len1=strlen(num),
		len2=strlen(name);
	int flag=1;
	for(int i=0;i<n;++i)
		ans[i]='#';
	ans[n]=0;
	for(int i=0;i<len1;++i){
		if(num[i]=='1'){
			for(int j=0;j<len2;++j){
				if(i+j>=n){
					flag=0;
					break;
				}
				if(ans[i+j]!='#'){
					if(ans[i+j]==name[j])
						continue;
					else{
						flag=0;
						break;
					}
				}
				else
					ans[i+j]=name[j];
			}
		}
	}
	//cout<<flag<<endl;
	//cout<<ans<<endl;
	if(flag){
		char tc=getTc(name);
		for(int i=0;i<n;++i)
			if(ans[i]=='#') ans[i]=tc;
		//cout<<ans<<endl;
		for(int i=0;i<n;++i)
			if(i<len1){
				if(num[i]=='0'){
					int j;
					for(j=0;j<len2;++j){
						if(i+j>=n) break;
						if(ans[i+j]!=name[j]) break;
					}
					//cout<<j<<' '<<len2<<endl;
					if(j==len2){
						flag=0;
						break;
					}
				}
			}
		//cout<<flag<<endl;
		if(flag) puts(ans);
		else puts("No solution");
	}
	else
		puts("No solution");
	return 0;
}

