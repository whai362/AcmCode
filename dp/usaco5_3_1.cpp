/*
ID: usaasu2
PROG: milk4
LANG: C++11
*/
//#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
ifstream fin ("milk4.in" );
ofstream fout("milk4.out");
const int INF=0x3f3f3f3f;
int a[101];
int dp[2][20005][2];

bitset<101> da[2][20005][2];

int xb(int x){
	return (x+2)%2;
}

int cmp(bitset<101> a,bitset<101> b){
	for(int i=0;i<101;++i){
		if(a[i]==b[i]) continue;
		else if(a[i]>b[i]) return -1;
		else return 1;
	}
	return 0;
}

void print(bitset<101> x){
	int cnt=0;
	int out[101];
	for(int i=0;i<101;++i){
		if(x[i]==1) out[cnt++]=a[i];
	}
	fout<<out[0];
	for(int i=1;i<cnt;++i){
		fout<<' '<<out[i];
	}
	fout<<endl;
}

int main(){
	int k,n;
	//scanf("%d%d",&k,&n);
	fin>>k>>n;
	for(int i=0;i<n;++i){
		//scanf("%d",&a[i]);
		fin>>a[i];
	}
	sort(a,a+n);
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;++i){
		dp[xb(i)][0][1]=1;
		da[xb(i)][0][1][i]=1;
		for(int j=1;j<=k;++j){
			int tmp;
			bitset<101> tmpbit;
			if(i){
				tmp=dp[xb(i-1)][j][0];
				tmpbit=da[xb(i-1)][j][0];
				if(tmp>dp[xb(i-1)][j][1] || (tmp==dp[xb(i-1)][j][1] && cmp(tmpbit,da[xb(i-1)][j][1])>0)){
					tmp=dp[xb(i-1)][j][1];
					tmpbit=da[xb(i-1)][j][1];
				}
				if(dp[xb(i)][j][0]>=tmp && tmp!=INF){
					dp[xb(i)][j][0]=tmp;
					da[xb(i)][j][0]=tmpbit;
				}
			}

			if(j-a[i]>=0){
				if(dp[xb(i)][j][1]>dp[xb(i)][j-a[i]][1]){
					dp[xb(i)][j][1]=dp[xb(i)][j-a[i]][1];
					da[xb(i)][j][1]=da[xb(i)][j-a[i]][1];
				}
				else if(dp[xb(i)][j][1]==dp[xb(i)][j-a[i]][1]){
					if(cmp(da[xb(i)][j][1],da[xb(i)][j-a[i]][1])>0)
						da[xb(i)][j][1]=da[xb(i)][j-a[i]][1];
				}

				if(dp[xb(i)][j][1]>dp[xb(i)][j-a[i]][0]+1){
					dp[xb(i)][j][1]=dp[xb(i)][j-a[i]][0]+1;
					da[xb(i)][j][1]=da[xb(i)][j-a[i]][0] | da[xb(i)][0][1];
				}
				else if(dp[xb(i)][j][1]==dp[xb(i)][j-a[i]][0]+1){
					tmpbit=da[xb(i)][j-a[i]][0] | da[xb(i)][0][1];
					if(cmp(da[xb(i)][j][1],tmpbit)>0)
						da[xb(i)][j][1]=tmpbit;
				}

				if(i){
					tmp=dp[xb(i-1)][j-a[i]][0];
					tmpbit=da[xb(i-1)][j-a[i]][0];
					if(tmp>dp[xb(i-1)][j-a[i]][1] || (tmp==dp[xb(i-1)][j-a[i]][1] && cmp(tmpbit,da[xb(i-1)][j-a[i]][1])>0)){
						tmp=dp[xb(i-1)][j-a[i]][1];
						tmpbit=da[xb(i-1)][j-a[i]][1];
					}

					if(dp[xb(i)][j][1]>tmp+1){
						dp[xb(i)][j][1]=tmp+1;
						da[xb(i)][j][1]=tmpbit | da[xb(i)][0][1];
					}
					else if(dp[xb(i)][j][1]==tmp+1){
						tmpbit=tmpbit | da[xb(i)][0][1];
						if(cmp(da[xb(i)][j][1],tmpbit)>0)
							da[xb(i)][j][1]=tmpbit;
					}
				}
			}
		}
		memset(dp[xb(i+1)],0x3f,sizeof(dp[xb(i+1)]));
		memset(da[xb(i+1)],0,sizeof(da[xb(i+1)]));
	}
	int ans=dp[xb(n-1)][k][0];
	bitset<101> ansbit=da[xb(n-1)][k][0];

	if(ans>dp[xb(n-1)][k][1] || (ans==dp[xb(n-1)][k][1] && cmp(ansbit,da[xb(n-1)][k][1])>0)){
		ans=dp[xb(n-1)][k][1];
		ansbit=da[xb(n-1)][k][1];
	}

	fout<<ans<<' ';
	print(ansbit);
	return 0;
}
