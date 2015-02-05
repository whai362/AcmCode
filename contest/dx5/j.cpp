#include<iostream>
#include<cstdio>
#include<cstring>
//#include<ctime>
using namespace std;
#define LL __int64
const int N=805;
const int MOD=3;
int n;
int a[N][N],b[N][N],ans[N][N];
void mul(){
    int i, j, k, L;
	int *p2;
    int tmp[N], con;
    for(i = 0; i < n; ++i){
        memset(tmp, 0, sizeof(tmp));
        for(k = 0, L = (n & ~15); k < L; ++k){
            con = a[i][k];
            for(j = 0, p2 = b[k]; j < n; ++j, ++p2)
                tmp[j] += con * (*p2);
            if((k & 15) == 15){
                for(j = 0; j < n; ++j) tmp[j] %= MOD;
            }
        }
        for( ; k < n; ++k){
            con = a[i][k];
            for(j = 0, p2 = b[k]; j < n; ++j, ++p2)
                tmp[j] += con * (*p2);
        }
        for(j = 0; j < n; ++j)
            ans[i][j] = tmp[j] % MOD;
    }
}
int main(){
	//double st=clock();
	char out[1605];
	while(~scanf("%d",&n)){
		memset(out,0,sizeof(out));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&a[i][j]);
				a[i][j]%=3;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&b[i][j]);
				b[i][j]%=3;
			}
		}
		mul();
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				out[j<<1]='0'+ans[i][j];
				if(j!=n-1) out[(j<<1)+1]=' ';
			}
			puts(out);
		}
	}
	//double en=clock();
	//cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
