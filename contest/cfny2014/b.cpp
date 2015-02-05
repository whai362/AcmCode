#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define pb push_back
const int N=305;
int a[N];
char str[N];
int fa[N];
int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}
int seq[N];
int ans[N];
vector<int> vc[N],id[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		seq[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=0;i<n;++i){
		scanf("%s",str);
		int len=strlen(str);
		int u,v,fu,fv;
		u=a[i+1];
		fu=getFa(u);
		for(int j=0;j<len;++j){
			if(str[j]=='1'){
				v=a[j+1];
				fv=getFa(v);
				if(fu!=fv){
					fa[fv]=fu;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		fa[i]=getFa(i);
		vc[fa[i]].pb(i);
		id[fa[i]].pb(seq[i]);
	}
	for(int i=1;i<=n;++i){
		sort(vc[i].begin(),vc[i].end());
		sort(id[i].begin(),id[i].end());
		//cout<<i<<':'<<endl;
		for(int j=0;j<vc[i].size();++j){
			//cout<<vc[i][j]<<' ';
			ans[id[i][j]]=vc[i][j];
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",ans[i],i!=n?' ':'\n');
	}
	return 0;
}
