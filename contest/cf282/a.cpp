#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int pos[N];
int ans[N];
int cnt=0;
char str[N];
int main(){
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;++i){
		if(str[i]=='#'){
			pos[cnt++]=i;
		}
	}
	int llc=0,lrc=0;
	for(int i=pos[cnt-1];i<len;++i){
		if(str[i]=='(') ++llc;
		if(str[i]==')') ++lrc;
	}
	int now=0;
	int flag=1;
	int lc=0,rc=0;
	for(int i=0;i<len;++i){
		if(str[i]=='('){
			++now;
			++lc;
		}
		else if(str[i]==')'){
			--now;
			++rc;
			if(now<0){
				flag=0;
				break;
			}
		}
		else{
			if(i!=pos[cnt-1]){
				--now;
				++rc;
				if(now<0){
					flag=0;
					break;
				}
				ans[i]=1;
			}
			else{
				int _left=llc+lc;
				int _righ=lrc+rc;
				if(_righ>=_left){
					flag=0;
					break;
				}
				int tmp=_left-_righ;
				now-=tmp;
				if(now<0){
					flag=0;
					break;
				}
				ans[i]=tmp;
			}
		}
	}
	if(flag){
		for(int i=0;i<cnt;++i){
			printf("%d\n",ans[pos[i]]);
		}
	}
	else{
		puts("-1");
	}
	return 0;
}
