#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int cnt;
string name[1005],na1[1005],na2[1005];
int f[1005],r[1005];
int find(string na){
	int l=0,r=cnt-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(na>name[mid]) l=mid+1;
		else if(na<name[mid]) r=mid-1;
		else return mid;
	}
}
int getFa(int x){
	if(f[x]!=x){
		getFa(f[x]);
		r[x]=r[x]^r[f[x]];
		f[x]=f[f[x]];
	}
	return f[x];
}
int main(){
	int cas=0,T,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);
		cnt=0;
		memset(r,0,sizeof(r));
		for(int i=0;i<105;++i){
			f[i]=i;
		}
		for(int i=0;i<m;++i){
			cin>>na1[i]>>na2[i];
			name[cnt++]=na1[i];
			name[cnt++]=na2[i];
		}
		sort(name,name+cnt);
		cnt=unique(name,name+cnt)-name;
		/*for(int i=0;i<cnt;++i){
		  cout<<name[i]<<endl;
		  }
		  cout<<find("Fake_Thomas_Jefferson");*/
		int a,b,fa,fb,flag=1;
		for(int i=0;i<m;++i){
			a=find(na1[i])+1;
			b=find(na2[i])+1;
			//cout<<a<<' '<<b<<endl;
			fa=getFa(a);
			fb=getFa(b);
			if(fa!=fb){
				f[fb]=fa;
				if(r[b]==1) r[fb]=r[a]^0;
				else r[fb]=r[a]^1;
			}
			else if(r[a]^r[b]==0) flag=0;
		}
		printf("Case #%d: ",++cas);
		if(flag==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
