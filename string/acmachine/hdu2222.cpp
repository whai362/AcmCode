#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500001;
int n;
int que[N];
char str[2*N];
struct acm{
	int cnt;
	int next[N][26],sum[N],fail[N];
	bool vis[N];
	void clear(){
		for(int i=1;i<=cnt;++i){
			vis[i]=sum[i]=fail[i]=0;
			for(int j=0;j<26;++j)
				next[i][j]=0;
		}
		cnt=1;
		for(int i=0;i<26;++i) next[0][i]=1;
	}
	void insert(char str[]){
		int now=1;
		int len=strlen(str);
		for(int i=0;i<len;++i){
			if(!next[now][str[i]-'a']) next[now][str[i]-'a']=++cnt;
			now=next[now][str[i]-'a'];
		}
		++sum[now];
	}
	void buildFail(){
		int head=0,tail=1;
		que[0]=1;
		fail[1]=0;
		while(head!=tail){
			int now=que[head];head++;
			for(int i=0;i<26;++i){
				int ch=next[now][i];
				if(!ch) continue;
				int tmp=fail[now];
				while(!next[tmp][i]) tmp=fail[tmp];
				fail[ch]=next[tmp][i];
				que[tail++]=ch;
			}
		}
	}
	void debug(){
        for(int i=0;i<=cnt;i++){
            printf("id=%3d,fail=%3d,sum=%3d,chi=[",i,fail[i],sum[i]);
            for(int j=0;j<26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
	void gao(char str[]){
		int ans=0,now=1,len=strlen(str);
		for(int i=0;i<len;++i){
			vis[now]=1;
			while(!next[now][str[i]-'a']) now=fail[now];
			now=next[now][str[i]-'a'];
			if(!vis[now])	//加上这个剪枝，能优化一倍的时间。
				for(int j=now;j;j=fail[j]){
					ans+=sum[j];
					sum[j]=0;
				}
		}
		printf("%d\n",ans);
	}
}acm;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		acm.clear();
		for(int i=0;i<n;++i){
			scanf("%s",str);
			acm.insert(str);
		}
		acm.buildFail();
		//acm.debug();
		scanf("%s",str);
		acm.gao(str);
	}
	return 0;
}
