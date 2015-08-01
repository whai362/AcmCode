#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
int n,pos[N];
struct acm{
	int cnt;
	int next[N][26],sum[N],fail[N],que[N];
	char str[N];
	acm(){
		cnt=1;
		for(int i=0;i<26;++i) next[0][i]=1;
	}
	void insert(int &pos){
		scanf("%s",str);
		int now=1;
		int len=strlen(str);
		for(int i=0;i<len;++i){
			if(!next[now][str[i]-'a']) next[now][str[i]-'a']=++cnt;
			now=next[now][str[i]-'a'];
			++sum[now];
		}
		pos=now;
	}
	void buildFail(){
		int head=0,tail=1;
		que[0]=1;
		fail[1]=0;
		while(head!=tail){
			int now=que[head]; ++head;
			for(int i=0;i<26;++i){
				int ch=next[now][i];
				if(!ch) continue;
				int k=fail[now];
				while(!next[k][i]) k=fail[k];
				fail[ch]=next[k][i];
				que[tail++]=ch;
			}
		}
		for(int i=tail-1;i>=0;--i){
			//cout<<fail[que[i]]<<' ';
			sum[fail[que[i]]]+=sum[que[i]];
		}
		//cout<<endl;
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
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		acm.insert(pos[i]);
		//cout<<pos[i]<<' ';
	}
	//cout<<endl;
	acm.buildFail();
	acm.debug();
	for(int i=1;i<=n;++i)
		printf("%d\n",acm.sum[pos[i]]);
	return 0;
}
