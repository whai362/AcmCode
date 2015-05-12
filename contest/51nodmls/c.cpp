#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int S;
vector<int> B[N],bcnt;
int maxx[N];
int pos[N];
void deal(int &k){
	int _max=0,bl=-1,mv=-1,op=0,p=k,sum=0;
	for(int i=0;i<bcnt;++i){
		if(B[i].size()==0) continue;
		if(p>=B[i].size()){
			if(maxx[i]>_max){
				_max=maxx[i];
				bl=i;
				mv=pos[i];
				op=sum+pos[i];
				p-=B[i].size();
			}
			sum+=B[i].size();
		}
		else{
			for(int j=0;j<p;++j){
				if(B[i][j]>_max){
					_max=B[i][j];
					bl=i;
					mv=j;
					op=sum+j;
				}
			}
			break;
		}
	}
	update(bl,mv);
}
void gao(int n,int k){
	for(int i=0;i<=bcnt;++i){
		for(int j=0;j<B[i].size();++j){
			if(B[i][j]>maxx[i]){
				pos[i]=j;
				maxx[i]=B[i][j];
			}
		}
	}

	for(int i=0;i<n;++i){
		int o=deal(k);
		printf("%d\n",o);
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	S=sqrt(n);
	bcnt=0;
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		int bl=i/S;
		B[bl].PB(a);
	}
	bcnt=n/S;
	gao(n,k);
	return 0;
}
