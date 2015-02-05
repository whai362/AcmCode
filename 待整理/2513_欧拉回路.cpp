#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=250005;
struct String{
	char str[15];
	bool operator == (const String &other) const{
		if(strcmp(str,other.str)==0){
			return true;
		}
		return false;
	}
}col[2*N];
struct Stick{
	char c1[15],c2[15];
}st[N];
bool vis[2*N];
int cnt0,cnt1,unique_count;
int d[2*N],f[2*N];
bool cmp(String s1,String s2){
	if(strcmp(s1.str,s2.str)<0)
		return true;
	return false;
}
int find(char *c){
	int l=0,r=unique_count-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		int ret=strcmp(col[mid].str,c);
		if(ret==0){
			l=mid;
			break;
		}
		else if(ret<0){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int getFa(int n){
	if(n!=f[n]){
		return f[n]=getFa(f[n]);
	}
	return n;
}
bool ok(){
	int fa=getFa(0);
	for(int i=1;i<unique_count;++i){
		if(getFa(i)!=fa){
			return false;
		}
	}
	return true;
}
int main(){
	cnt0=0,cnt1=0;
	while(scanf("%s%s",st[cnt0].c1,st[cnt0].c2)!=EOF){
		strcpy(col[cnt1++].str,st[cnt0].c1);
		strcpy(col[cnt1++].str,st[cnt0].c2);
		++cnt0;
	}
	sort(col,col+cnt1,cmp);
	unique_count=unique(col,col+cnt1)-col;
	for(int i=0;i<unique_count;++i){
		f[i]=i;
	}
	for(int i=0;i<cnt0;++i){
		int u,v;
		u=find(st[i].c1);
		v=find(st[i].c2);
		++d[u];
		++d[v];
		int fu,fv;
		fu=getFa(u);
		fv=getFa(v);
		if(fu!=fv){
			f[fv]=fu;
		}
	}
	if(ok()){
		int cntO=0;
		for(int i=0;i<unique_count;++i){
			if(d[i]%2){
				++cntO;
			}
		}
		if(cntO==0 || cntO==2){
			printf("Possible\n");
		}
		else{
			printf("Impossible\n");
		}
	}
	else{
		printf("Impossible\n");
	}
	return 0;
}
