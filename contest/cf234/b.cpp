#include<cstdio>
#include<iostream>
using namespace std;
char m[1005][1005];
int hash[1005];
int main(){
	int ans=0,i,j,f,ff=1,s,e,n,mm,tmp;
	scanf("%d%d",&n,&mm);
	for(i=0;i<n;++i){
		scanf("%s",m[i]);
		tmp=-1;
		s=e=-1;
		f=-1;
		for(j=0;j<mm;++j){
			if(m[i][j]=='G') f=0,s=j;
			if(s!=-1 && m[i][j]=='S'){
				//if(tmp==-1) tmp=e-s;
				//else if(e-s!=tmp) ff=0;
				f=1;
				e=j;
				hash[e-s]=1;
				//cout<<"!"<<e-s<<endl;
			}
		}
		if(f==0) ff=0;
	}
	for(j=0;j<mm;++j){
		if(hash[j]) ++ans;
	}
	if(ans && ff) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
