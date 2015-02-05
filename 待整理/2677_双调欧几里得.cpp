#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define N 105
#define INF 1e10
struct point{
	double x,y;
}p[N];
int n;
double d[N][N],dp[N][N];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double gao(){
	if(n==1) return 0;
	int i,j;
	dp[1][0]=d[1][0];
	for(i=1;i<n-1;++i){
		dp[i+1][i]=INF;
		for(j=0;j<i;++j){
			dp[i+1][j]=dp[i][j]+d[i][i+1];
			dp[i+1][i]=min(dp[i+1][i],dp[i][j]+d[j][i+1]);
		}
	}
	return dp[n-1][n-2]+d[n-1][n-2];
}
int main(){
	int i,j;
	while(cin>>n){
		for(i=0;i<n;++i){
			cin>>p[i].x>>p[i].y;
		}
		for(i=0;i<n-1;++i){
			for(j=i+1;j<n;++j){
				d[i][j]=d[j][i]=dis(p[i],p[j]);
			}
		}
		cout<<fixed<<setprecision(2)<<gao()<<endl;
	}
	return 0;
}
