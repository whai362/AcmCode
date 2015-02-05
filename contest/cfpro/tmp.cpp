#include<iostream>
//#include<ctime>
using namespace std;
#define ll __int64
const int mod=1e9+7;
int r,g;
int dp[2][200010];
int hmx;

ll solve(){
	int i,j,k,h,p;
	dp[0][0]=1;
	dp[0][1]=1;
	p=1;
	int sum=1;
	for(h=2;;++h){
		sum+=h;
		if(sum>r+g) break;
		for(int i=0;i<=min(r,h*(h+1)/2);++i){
			dp[p][i]=dp[!p][i]+(i>=h?dp[!p][i-h]:0);
			dp[p][i]%=mod;
		}
		p=!p;
	}
	p=!p;
	hmx=h-1;
	ll ans=0,t=hmx*(hmx+1)/2;
	while(r>-1&&r+g>=t)ans=(ans+dp[p][r--])%mod;
	return ans;

}

int main(){
	//double st=clock(),en;
	int i,j,k;
	cin>>r>>g;
	if(r+g==0){
		cout<<"0\n";
		return 0;
	}
	cout<<solve()<<"\n";
	//en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
}

