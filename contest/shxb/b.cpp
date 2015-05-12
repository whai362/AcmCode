#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int a[N][N];
int mc[N],mr[N];
void gao(int n,int m){
	mr[0]=mc[m-1]=a[0][m-1];
	for(int i=0;i<n;++i){
		for(int j=m-1;j>=0;--j){
			if(i==0 && j==m-1) continue;
			if(i==0){
				mc[j]=a[i][j];
				a[i][j]=max(a[i][j],a[i][j+1]);
			}
			else if(j==m-1){
				mr[i]=a[i][j];
				a[i][j]=max(a[i][j],a[i-1][j]);
			}
			else{
				int t1,t2,t3;
				if(a[i][j]>mc[j])
					t1=a[i-1][j]+a[i][j]-mc[j];
				else
					t1=a[i-1][j];
				if(a[i][j]>mr[i])
					t2=a[i][j+1]+a[i][j]-mr[i];
				else
					t2=a[i][j+1];
				t3=a[i-1][j+1]+a[i][j];
				mr[i]=max(mr[i],a[i][j]);
				mc[j]=max(mc[j],a[i][j]);
				a[i][j]=max(t1,max(t2,t3));
			}
		}
	}
	//for(int i=0;i<n;++i){
	//	for(int j=0;j<m;++j){
	//		cout<<a[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	printf("%d\n",a[n-1][0]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&a[i][j]);
			}
		}
		gao(n,m);
	}
	return 0;
}
