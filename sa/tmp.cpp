#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=600005;
int n;
//后缀数组模板
//注意k是全局变量不要乱用
int k;	//用于倍增法求后缀数组的全局变量
int rank[N],tmp[N];
int sa[N*2];
bool cmp_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n? rank[i+k]:-1;
		int rj=j+k<=n? rank[j+k]:-1;
		return ri<rj;
	}
}
void build_sa(char arr[],int len,int sa[]){	//改arr，len为数组长度
	for(int i=0;i<=len;++i){
		sa[i]=i;
		rank[i]=i<len? arr[i]:-1;
	}
	//利用对长度为k的排序的结果对长度为2k的排序
	for(k=1;k<=len;k*=2){
		sort(sa,sa+len+1,cmp_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=len;++i){
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp_sa(sa[i-1],sa[i])? 1:0);
		}
		for(int i=0;i<=len;++i){
			rank[i]=tmp[i];
		}
	}
}
int lcp[N*2];
void build_lcp(char *s, int *sa, int *lcp)
{
	n = strlen(s);
	for (int i = 0; i <= n; i++) rank[sa[i]] = i;
	int h = 0;
	lcp[0] = 0; 
	for (int i = 0; i < n; i++){
		int j = sa[rank[i] - 1];
		for (h ? h-- : 0; j + h < n&&i + h < n&&s[j + h] == s[i + h]; h++);
		lcp[rank[i] - 1] = h;
	}
}
char S[N],T[N];
void gao(){
	int len1=strlen(S);
	S[len1]='#';
	S[len1+1]=0;
	strcat(S,T);
	int len2=strlen(S);
	build_sa(S,len2,sa);
	build_lcp(S,sa,lcp);
	int ans=0;
	for(int i=0;i<len2;++i){
		if((sa[i]<len1)!=(sa[i+1]<len1)){
			ans=max(ans,lcp[i]);
		}
	}
	printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
}
int main(){
	int TT;
	scanf("%d",&TT);
	getchar();
	while(TT--){
		gets(S);
		gets(T);
		//cout<<S<<endl<<T<<endl;
		gao();
	}
	return 0;
}
