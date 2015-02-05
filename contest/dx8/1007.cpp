#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
int a[N][2*N],tab[N][2*N],s[N][2],t[N][2];
int ans[N];
int p;
bool dfs(int n){
	/*for(int i=0;i<p;++i){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	cout<<'!'<<n<<endl;*/
	if(n>=p) return true;
	for(int i=0;i<p;++i){
		int flag=1;
		if(ans[i]==-1) ans[i]=n;
		else if(ans[i]!=n) flag=0;

		//cout<<i<<' '<<t[n][0]<<' '<<t[n][1]<<endl;
		if(ans[t[i][0]]==-1) ans[t[i][0]]=s[n][0];
		else if(ans[t[i][0]]!=s[n][0]) flag=0;

		if(ans[t[i][1]]==-1) ans[t[i][1]]=s[n][1];
		else if(ans[t[i][1]]!=s[n][1]) flag=0;

		//cout<<flag<<endl;
		if(flag){
			if(dfs(n+1)) return true;
			else{
				ans[i]=-1;
				ans[t[i][0]]=-1;
				ans[t[i][1]]=-1;
			}
		}
		else{
			ans[i]=-1;
			ans[t[i][0]]=-1;
			ans[t[i][1]]=-1;
		}
	}
	return false;
}

int main(){
	int cas=0;
	while(scanf("%d",&p) && p){
		for(int i=0;i<p;++i){
			for(int j=0;j<2*p;++j){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<p;++i){
		  s[i][0]=a[i][2*i];
		  s[i][1]=a[i][2*i+1];
		  //cout<<s[i][0]<<' '<<s[i][1]<<endl;
		}
		memset(tab,0,sizeof(tab));
		for(int i=0;i<p;++i){
			int tmp=i*i;
			tab[i][2*i+1]=tmp%p;
			tmp/=p;
			tab[i][2*i]=tmp%p;
		}
		for(int i=0;i<p;++i){
		  t[i][0]=tab[i][2*i];
		  t[i][1]=tab[i][2*i+1];
		  //cout<<t[i][0]<<' '<<t[i][1]<<endl;
		}
		memset(ans,-1,sizeof(ans));
		dfs(0);
		printf("Case #%d: ",++cas);
		for(int i=0;i<p;++i){
			printf("%d ",ans[i]);
			//cout<<ans[i]<<' ';
		}
		puts("");
	}
	return 0;
}
