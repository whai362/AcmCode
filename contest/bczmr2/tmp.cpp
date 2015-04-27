#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef unsigned long long LL;


LL a[550];
LL A[550];
LL C[550][550];
LL dp[55][550];
string biao="23456789TJQKA";
int tab[300];
void Init()
{
    for(int i=0; i<60; i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1; j<i; j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1]);
    }
    A[0]=1;
    for(int i=1; i<60; i++)
        A[i]=(A[i-1]*i);
	for(int i=0;i<biao.length();++i){
		tab[biao[i]]=i;
	}
}
char str[5];
int cnt[15];
int main()
{
	ios_base::sync_with_stdio(false);
    Init();
    int T,n,tt=1;
    cin>>T;
    while(T--)
    {
		memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=1; i<=n; i++){
			cin>>str;
			cnt[tab[str[0]]]++;
            //cin>>a[i];
		}
		n=1;
		for(int i=0;i<15;++i){
			if(cnt[i]>0) a[n++]=cnt[i];
		}
		--n;
        memset(dp,0,sizeof(dp));
        dp[1][a[1]-1]=1;
        LL sum=a[1];
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<sum; j++)
                for(int k=1; k<=a[i]; k++)
                    for(int u=0; u<=j && u<=k; u++)
                        dp[i][j-u+a[i]-1-(k-1)]=(dp[i][j-u+a[i]-k]+(((dp[i-1][j]*C[j][u])*C[sum+1-j][k-u])*C[a[i]-1][k-1]));
            sum+=a[i];
        }
       cout<<"Case #"<<tt++<<": ";
        LL ans=dp[n][0];
        for(int i=1; i<=n; i++)
            ans=(ans*A[a[i]]);
        cout<<ans<<endl;
    }
    return 0;
}

