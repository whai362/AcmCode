#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int a[N][N];
void paint(int x1,int y1,int x2,int y2){
	int X1=x1,Y1=y1,X2=x2,Y2=y2;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	for(int i=x1;i<=x2;++i){
		for(int j=y1;j<=y2;++j){
			//if(i==0 && j==0) cout<<X1<<' '<<Y1<<' '<<X2<<' '<<Y2<<endl;
			++a[i][j];
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		int k;
		scanf("%d%d%d",&n,&m,&k);
		for(int x1=0;x1<n;++x1){
			for(int y1=0;y1<m;++y1){
				for(int x2=0;x2<n;++x2){
					for(int y2=0;y2<m;++y2){
						paint(x1,y1,x2,y2);
					}
				}
			}
		}
		double sum=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				sum+=(double)a[i][j];
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
		//cout<<(double)a[0][0]/(n*m*n*m)<<endl;
		cout<<sum/(n*m*n*m)<<endl;
	}
}
