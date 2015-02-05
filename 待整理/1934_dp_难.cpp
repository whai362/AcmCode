#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	char s[85];
	node *l,*r;
};
int cnt,l1,l2;
int last1[85][30],last2[85][30],dp[85][85];
char s1[85],s2[85],tmp[85];
node *root;
void insert(node *&p){
	if(p==NULL){
		p=new node();
		strcpy(p->s,tmp);
		p->l=NULL;
		p->r=NULL;
	}
	else{
		int f=strcmp(p->s,tmp);
		if(f>0)
			insert(p->l);
		else if(f<0)
			insert(p->r);
	}
	return ;
}
void LDR(node *p){
	if(p){
		LDR(p->l);
		printf("%s\n",p->s);
		LDR(p->r);
	}
}
void dfs(int p1,int p2,int k){
	int i,t1,t2;
	if(k<0){
		insert(root);
		return ;
	}
	for(i=0;i<26;++i){
		t1=last1[p1][i];
		t2=last2[p2][i];
		if(dp[t1][t2]==k+1){
			tmp[k]=i+'a';
			dfs(t1-1,t2-1,k-1);
		}
	}
}
int main(){
	int i,j;
	scanf("%s%s",s1,s2);
	l1=strlen(s1),l2=strlen(s2);
	for(i=1;i<=l1;++i){
		for(j=1;j<=l2;++j){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	memset(last1,0,sizeof(last1));
	memset(last2,0,sizeof(last2));
	for(i=1;i<=l1;++i){
		for(j=0;j<26;++j){
			if(s1[i-1]==j+'a')
				last1[i][j]=i;
			else
				last1[i][j]=last1[i-1][j];
		}
	}
	for(i=1;i<=l2;++i){
		for(j=0;j<26;++j){
			if(s2[i-1]==j+'a')
				last2[i][j]=i;
			else
				last2[i][j]=last2[i-1][j];
		}
	}
	cnt=0;
	root=NULL;
	memset(tmp,0,sizeof(tmp));
	dfs(l1,l2,dp[l1][l2]-1);
	LDR(root);
	return 0;
}
