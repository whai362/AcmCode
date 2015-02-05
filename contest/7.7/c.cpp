#include<cstdio>
#include<iostream>
using namespace std;
const int N=35;
int n;
int a[N][N],b[N][N],t[N][N];
void turn(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			t[n-1-j][i]=b[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			b[i][j]=t[i][j];
		}
	}
	/*for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}*/
}
int gao(){
	int ans=0;
	for(int i=0;i<4;++i){
		turn();
		int tmp=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(a[i][j]==b[i][j]){
					++tmp;
				}
			}
		}
		ans=max(ans,tmp);
	}
	return ans;
}
int main(){
	while(scanf("%d",&n) && n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&b[i][j]);
		}
	}
	cout<<gao()<<endl;
	}
	return 0;
}
