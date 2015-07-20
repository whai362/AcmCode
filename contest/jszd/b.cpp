#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10][4];
int b[30],cnt;
int c[10][4];
bool
bool ok(int st,int n){
	cnt=0;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	while(st){
		b[cnt++]=st%3;
		b/=3;
	}
	for(int i=0;i<n;++i){
		int r=i/4;
		int c=i%4;
		a[r][c]=b[i];
	}
	for(int i=0;i<n/4;++i){
		for(int j=0;j<4;++i){
			if(a[i][j]==1){
				int tmpx=i;
				int tmpy=j+1;
				if(ok1(tmpx,tmpy,n/4,4)){
					c[tmpx][tmpy]=3;
				}
				else return false;
			}
			else if(a[i][j]==2){
				int tmpx=i+1;
				int tmpy=j;
				if(ok1(tmpx,tmpy,n/4,4)){
					c[tmpx][tmpy]=4;
				}
				else return false;
			}
		}
	}
	return true;

}
int main(){
	int n;
	cin>>n;
	n*=4;
	int lim=1;
	for(int i=0;i<n;++i){
		lim*=3;
	}
	int ans=0;
	for(int i=0;i<lim;++i){
		if(ok(i,n)) ++ans;
	}
	cout<<ans<<endl;
}
