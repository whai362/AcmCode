#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=105;
const int MAXN=1e4+5;
int a[N];
int sg[MAXN];

void get_sg(int n){
	sg[0]=0;
	for(int i=1;i<MAXN;++i){
		set<int> s;
		for(int j=0;j<n;++j){
			if(i >= a[j])
				s.insert(sg[i - a[j]]);
		}
		int g=0;
		while(s.count(g)!=0) ++g;
		sg[i]=g;
	}
}


int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		get_sg(n);
		int m;
		scanf("%d",&m);
		int h_cnt;
		char ans[N];
		for(int i=0;i<m;++i){
			scanf("%d",&h_cnt);
			int h;
			int tmp=0;
			for(int j=0;j<h_cnt;++j){
				scanf("%d",&h);
				cout<<sg[h]<<' ';
				tmp ^= sg[h];
			}
			cout<<endl;
			if(tmp==0) ans[i]='L';
			else ans[i]='W';
		}
		ans[m]=0;
		puts(ans);
	}
	return 0;
}
