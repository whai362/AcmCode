#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 10005
bool prime[N],vis[N];
struct data{
	int n,step;
	data(){}
	data(int _n,int _step){
		n=_n;
		step=_step;
	}
};
bool is_prime(int n){
	int i;
	if(n<2) return false;
	else if(n==2) return true;
	else{
		for(i=2;i*i<=n;++i){
			if(n%i==0)
				return false;
		}
	}
	return true;
}
int main(){
	char s[5];
	int ans,a,b,flag,T;
	int i,j;
	for(i=2;i<=N;++i){
		prime[i]=is_prime(i);
	}
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&a,&b);
	if(a==b) printf("0\n");
	else{
	flag=0;
	memset(vis,0,sizeof(vis));
	queue<data> q;
	q.push(data(a,0));
	vis[a]=true;
	while(!q.empty()){
		data top=q.front();
		q.pop();
		for(i=0;i<4;++i){
			sprintf(s,"%d",top.n);
			for(j='0';j<='9';++j){
				if(i==0 && j=='0') continue;
				s[i]=j;
				int tmp;
				sscanf(s,"%d",&tmp);
				if(tmp==b){
					flag=1;
					ans=top.step;
					break;
				}
				if(prime[tmp] && !vis[tmp]){
					q.push(data(tmp,top.step+1));
					vis[tmp]=true;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	printf("%d\n",ans+1);
	}
	}
	return 0;
}
