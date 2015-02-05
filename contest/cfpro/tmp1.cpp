#include <bits/stdc++.h>
#define snd(a) scanf("%d",&(a))
#define snlld(a) scanf("%lld",&(a))
#define rep(i,n) for((i)=0;(i)<(n);(i)+=1)
#define reps(i,s,n) for((i)=(s);(i)<(n);(i)+=1)
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pb push_back
#define pf push_front
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fill(a,v) memset((a),(v),sizeof(a))
#define sz size()
#define mp make_pair
#define mod  1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline T poww(T b,T p){ll a=1;while(p){if(p&1){a=(a*b);}p>>=1;b=(b*b);}return a;}
template<class T> inline T poww2(T b,int p){T a=1;while(p){if(p&1){a=(a*b);}p>>=1;b=(b*b);}return a;}
template<class T> inline T modpoww(T b,T p,T mmod){ll a=1;while(p){if(p&1){a=(a*b)%mmod;}p>>=1;b=(b*b)%mmod;}return a%mmod;}
template<class T>  inline T gcd(T a,T b){ if(b>a)return gcd(b,a);return ((b==0)?a:gcd(b,a%b));}
template<class T> inline void scan(vector<T>& a,int n){T b;int i; rep(i,n){cin>>b;a.pb(b);}}
inline void scand(vector<int>& a,int n){int b;int i; rep(i,n){snd(b);a.pb(b);}}
#define pii pair<int,int>
#define vpii vector<pii >
#define vi vector<int>
#define vvi vector<vi >
#define vl vector<long long>
#define fr first
#define sd second
int r,g;
int dp[2][200010];
int hmx;

ll solve(){
    int i,j,k,h,p;
    dp[0][0]=1;
    dp[0][1]=1;
    p=1;
    reps(h,2,hmx+1){
        rep(i,min(r+1,h*(h+1)/2+1)){
            dp[p][i]=dp[!p][i]+(i>=h?dp[!p][i-h]:0);
            dp[p][i]%=mod;
        }
        p=!p;
    }
    p=!p;
    ll ans=0,t=hmx*(hmx+1)/2;
    while(r>-1&&r+g>=t)ans=(ans+dp[p][r--])%mod;
    return ans;

}

int main(){
   int i,j,k;
   cin>>r>>g;
   if(r+g==0){
    cout<<"0\n";
    return 0;
   }
   ll s=1,e=900,m;
   hmx=0;
   while(s<=e){
        m=(s+e)/2;
        if(m*(m+1)/2<=r+g){
            hmx=m;
            s=m+1;
        }
        else e=m-1;

   }
    //cout<<"h="<<hmx<<"\n";
   cout<<solve()<<"\n";

}
