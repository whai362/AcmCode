#include<cstdio>
#include<cstring>
using namespace std;
int judge(char a,char b){
	if(a==b) return 0;
	if((a=='R' && b=='P') || (a=='P' && b=='R')){
		if(a=='P') return 1;
		else return 2;
	}
	else if((a=='R' && b=='S') || (a=='S' && b=='R')){
		if(a=='R') return 1;
		else return 2;
	}
	else if((a=='P' && b=='S') || (a=='S' && b=='P')){
		if(a=='S') return 1;
		else return 2;
	}
}
int main(){
	int i,len,tmp,cnt[2];
	char s1[100],s2[100];
	while(scanf("%s%s",s1,s2) && s1[0]!='E'){
		len=strlen(s1);
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<len;++i){
			tmp=judge(s1[i],s2[i]);
			if(tmp) ++cnt[tmp-1];
		}
		printf("P1: %d\nP2: %d\n",cnt[0],cnt[1]);
	}
	return 0;
}
