#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
int a[15];
char str[380000][25];
bool vis[10];
vector<int> tab[105];
bool jg(int u,int v){
	if(u>v) swap(u,v);
	int fd=u*10+v;
	//cout<<fd<<endl;
	for(int i=0;i<tab[fd].size();++i){
		if(vis[tab[fd][i]]==0) return false;
	}
	return true;
}
void print(int n){
	for(int i=0;i<n;++i){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
bool ok(int a[],int n){
	//print(n);
	memset(vis,0,sizeof(vis));
	vis[a[0]]=1;
	for(int i=1;i<n;++i){
		if(!jg(a[i-1],a[i])) return false;
		vis[a[i]]=1;
	}
	return true;
}
int main(){
	int T;
	tab[13].PB(2);
	tab[17].PB(4);
	tab[19].PB(5);
	tab[28].PB(5);
	tab[37].PB(5);
	tab[39].PB(6);
	tab[46].PB(5);
	tab[79].PB(8);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		//print(n);
		int cnt=0;
		if(ok(a,n)){	//1的情况
			int len=0;
			for(int i=0;i<n;++i){
				str[cnt][len++]=a[i]+'0';
				str[cnt][len++]=' ';
			}
			str[cnt][len-1]=0;
			++cnt;
		}
		while(next_permutation(a,a+n)){
			if(ok(a,n)){	//1的情况
				int len=0;
				for(int i=0;i<n;++i){
					str[cnt][len++]=a[i]+'0';
					str[cnt][len++]=' ';
				}
				str[cnt][len-1]=0;
				++cnt;
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;++i){
			puts(str[i]);
		}
	}
	return 0;
}
