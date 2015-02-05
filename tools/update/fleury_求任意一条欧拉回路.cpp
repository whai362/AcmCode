/*codeforces 508 D. Tanya and Password
  题意：
  给出n个长度为3的字符串，如：abc bca aab 如果一个字符串的长度为2的后缀等于，另外一个字符串的长度为2的前缀，则这两个字符串能连起来，比如：aabca，然后这n个字符串可以形成一个图，求图上的一条欧拉通路。
  限制：
  1 <= n <= 2*10^5，字符串里面有大写字母，小写字母
  思路：
  把每个字符串当成边，其前缀后缀当作点，如：abc -> ab到bc。
  则这个问题化为：有62*62个点，2*10^5条边的图，求一条欧拉通路的题目。
  用fleury(弗罗莱)，个人感觉用邻接表实现效率比邻接矩阵
  ps:这道题dfs会爆栈，把它改成非递归的就行。
  */
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<stack>
using namespace std;
const int M=200005;
const int N=65*65;
vector<int> mp[N];
int fa[N];
int in[N],out[N];
char ans[M],rev[M];
int len=0;
string i2s[N];
map<string,int> s2i;
int stk[M],top=0;

int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}
void dfs(int x){
	while(mp[x].size()>0){
		stk[++top]=x;
		int ch=mp[x][mp[x].size()-1];
		mp[x].pop_back();
		x=ch;
	}
	stk[++top]=x;
}
void fleury(int S){
	int brige;
	stk[++top]=S;
	int flag=0;
	int tp;
	while(top>0){
		tp=stk[top--];
		brige=(mp[tp].size()==0);
		if(brige){
			if(flag)
				ans[len++]=i2s[tp][0];
			else{
				ans[len++]=i2s[tp][1];
				ans[len++]=i2s[tp][0];
				flag=1;
			}
		}
		else
			dfs(tp);
	}
}

int main(){
	int n,m;
	char str[5];
	string fr,to;
	n=0;
	scanf("%d",&m);
	for(int i=0;i<65*65;++i)
		fa[i]=i;
	for(int i=0;i<m;++i){
		int x,y;
		int fx,fy;
		scanf("%s",str);
		fr=str[0];
		fr+=str[1];
		to=str[1];
		to+=str[2];

		x=s2i[fr];
		if(x==0){ s2i[fr]=++n; i2s[n]=fr; x=n; }
		y=s2i[to];
		if(y==0){ s2i[to]=++n; i2s[n]=to; y=n; }

		mp[x].push_back(y);
		fx=getFa(x);
		fy=getFa(y);
		if(fx!=fy)
			fa[fy]=fx;
		++out[x];
		++in[y];
	}
	int lt=1;
	int root=getFa(1);
	for(int i=2;i<=n;++i){
		if(getFa(i)!=root){ lt=0; break; }
	}
	int S=0,T=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(in[i]==out[i]) continue;
		else{
			cnt++;
			if(in[i]-out[i]==1) T=i;
			else if(in[i]-out[i]==-1) S=i;
			else{ cnt=-1; break; }
		}
	}
	if(lt && ((cnt==2 && S!=T) || cnt==0)){
		puts("YES");
		if(cnt==0) S=1;
		fleury(S);
		int len=strlen(ans);
		for(int i=0;i<len;++i){
			rev[len-1-i]=ans[i];
		}
		puts(rev);
	}
	else{
		puts("NO");
	}
	return 0;
}
