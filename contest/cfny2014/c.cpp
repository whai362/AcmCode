#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
const int M=1005;
int b[N],d[M];
int _hash[N];
int px[N];
int n,m;
int gao(int d){
	int fd;
	for(fd=0;fd<n;++fd){
		if(px[fd]==d) break;
	}
	int cp=px[fd];
	int ret=0;
	for(int i=fd-1;i>=0;--i){
		ret+=b[px[i]];
		px[i+1]=px[i];
	}
	px[0]=cp;
	return ret;
}
void print(){
	for(int i=0;i<n;++i)
		cout<<px[i]<<' ';
	cout<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	int cnt=0;
	for(int i=0;i<m;++i){
		scanf("%d",&d[i]);
		if(_hash[d[i]]==0){
			px[cnt++]=d[i];
			_hash[d[i]]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(_hash[i]==0)
			px[cnt++]=i;
	}
	int ans=0;
	for(int i=0;i<m;++i){
		ans+=gao(d[i]);
		//print();
	}
	cout<<ans<<endl;
	return 0;
}
