#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005,
	  M=105,
	  MAXB=10;
char str[N][M],digs[M],tmp[M];
int tot=0;
struct Trie{
	int br[MAXB];
	int num;
	char str[M];
	void clear(){
		num=0;
		memset(br,-1,sizeof(br));
		memset(str,0,sizeof(str));
	}
}trie[N*M];

int cid[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int fl[N][M];
void insert(char str[],int ind){
	int cur=0,len=strlen(str);
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<len;++i){
		tmp[i]=str[i];
		int id=cid[str[i]-'a'];
		if(trie[cur].br[id]==-1){
			trie[tot].clear();
			trie[cur].br[id]=tot;
			cur=tot++;
		}
		else
			cur=trie[cur].br[id];
		//cout<<tmp<<' '<<fl[ind][i]<<endl;
		if(fl[ind][i]>trie[cur].num){
			strcpy(trie[cur].str,tmp);
			trie[cur].num=fl[ind][i];
		}
		else if(fl[ind][i]==trie[cur].num){
			if(strcmp(trie[cur].str,tmp)>0){
				strcpy(trie[cur].str,tmp);
			}
		}
	}
}

void gao(char str[]){
	int cur=0,
		flag=0,
		len=strlen(str);
	for(int i=0;i<len-1;++i){
		int id=str[i]-'0';
		//cout<<"!"<<id<<endl;
		if(trie[cur].br[id]==-1 || flag==1){
			flag=1;
			puts("MANUALLY");
		}
		else{
			cur=trie[cur].br[id];
			puts(trie[cur].str);
		}
	}
}

void init(){
	tot=0;
	trie[tot++].clear();
	memset(fl,0,sizeof(fl));
}

int main(){
	int n,q,T,cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i){
			scanf("%s%d",str[i],&fl[i][0]);
			int len=strlen(str[i]);
			for(int j=1;j<len;++j){
				fl[i][j]=fl[i][j-1];
			}
			//insert(str,fl);
		}
		for(int i=1;i<n;++i){
			for(int j=0;str[i][j] && str[i-1][j];++j){
				if(str[i][j]==str[i-1][j]){
					fl[i][j]+=fl[i-1][j];
					fl[i-1][j]=0;
				}
				else break;
			}
		}
		for(int i=0;i<n;++i){
			insert(str[i],i);
		}
		scanf("%d",&q);
		printf("Scenario #%d:\n",++cas);
		for(int i=0;i<q;++i){
			scanf("%s",digs);
			gao(digs);
			puts("");
		}
		puts("");
	}
	return 0;
}
