#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int gx[30][30];
char name[105][105];
char ans[105];
int len;
int du[30];
void gao(){
	//cout<<"!!!"<<endl;
	for(int i=0;i<26;++i)
		for(int j=0;j<26;++j)
			if(gx[i][j]) ++du[j];
	queue<int> q;
	for(int i=0;i<26;++i){
		if(du[i]==0){ q.push(i); du[i]=-1; }
	}
	len=0;
	//cout<<"???"<<endl;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		ans[len++]=now+'a';
		for(int i=0;i<26;++i){
			if(gx[now][i] && du[i]>0) --du[i];
			if(du[i]==0){ q.push(i); du[i]=-1; }
		}
	}
	if(len==26) puts(ans);
	else puts("Impossible");
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%s",name[i]);
	int flag=1;
	for(int i=1;i<n;++i){
		int len1=strlen(name[i-1]);
		int len2=strlen(name[i]);
		int len=min(len1,len2);
		int j;
		for(j=0;j<len;++j){
			if(name[i][j]!=name[i-1][j]){
				int u=name[i-1][j]-'a';
				int v=name[i][j]-'a';
				if(gx[u][v]==0)
					gx[u][v]=1;
				else if(gx[v][u]==1){
					//cout<<char(u+'a')<<' '<<char(v+'a')<<endl;
					flag=0;
					break;
				}
				break;
			}
		}
		if(j==len && len1>len2) flag=0;
		if(flag==0) break;
	}
	//cout<<flag<<endl;
	if(flag==0) puts("Impossible");
	else gao();
	return 0;
}
