/*hdu 2222 Keywords Search
  题意：
  给出n个单词，然后给你一篇文章，问给出的单词在文章中出现的次数。
  限制：
  0 <= n <= 1e4; 单词只包含小写字母; 长度小于50;
  文章长度 <= 1e6
  思路：
  ac自动机模板题
 */
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
	void gao(char str[]){
		int ans=0,now=1,len=strlen(str);
		for(int i=0;i<len;++i){
			vis[now]=1;
			while(!next[now][str[i]-'a']) now=fail[now];
			now=next[now][str[i]-'a'];
			if(!vis[now])
				for(int j=now;j;j=fail[j]){
					ans+=sum[j];
					sum[j]=0;
				}
		}
		printf("%d\n",ans);
	}
	void debug(){
		for(int i=0;i<=cnt;++i){
			printf("id=%3d,fail=%3d,sum=%3d,chi=[",i,fail[i],sum[i]);
			puts("");
			for(int j=0;j<26;++j)
				printf("%2c",j+'a');
			puts("");
			for(int j=0;j<26;j++)
				printf("%2d",next[i][j]);
			puts("");
			printf("]\n");
		}
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
