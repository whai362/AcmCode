#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
int f[N],hash[N];
string s[N];
bool cmp(string a,string b){
	return a.length()<b.length();
}
int getf(int n){
	if(f[n]!=n) return f[n]=getf(f[n]);
	return n;
}
int main(){
	int n;
	int cas=0,ans,i,j;
	while(cin>>n){
		for(i=0;i<n;++i){
			cin>>s[i]; 
		}
		sort(s,s+n,cmp);
		for(i=0;i<n;++i) f[i]=i;
		memset(hash,0,sizeof(hash));
		ans=0;
		for(i=0;i<n;++i){
			for(j=i;j<n;++j){
				int tmp=s[j].find(s[i]);
				if(tmp>=0 && tmp<=s[j].length()-s[i].length()){
					f[j]=getf(i);
				}
			}
		}
		for(i=0;i<n;++i){
			int t=getf(i);
			if(hash[t]==0) ++ans,f[i]=t,hash[t]=1;
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}
