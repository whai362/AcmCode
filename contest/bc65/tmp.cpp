const LL mod = 1e9+7;
const LL LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;
const int maxn = 5e5 + 100;

struct Side{
    int v,next;
}side[maxn];
int node[maxn];
int cnt,K;
int dp[11][maxn];

void add_side(int u,int v){
    side[cnt].v = v;
    side[cnt].next = node[u];
    node[u] = cnt++;
}

void dfs1(int u){
    dp[0][u] = 1;
    for(int i=node[u];~i;i=side[i].next){
        int v = side[i].v;
        dfs1(v);
        for(int j=0;j<K;j++){
            dp[j+1][u]+=dp[j][v];
        }
    }
}

void dfs2(int u){
    for(int i=node[u];~i;i=side[i].next){
        int v = side[i].v;
        for(int j=K;j>=2;j--){
            dp[j][v] += (dp[j-1][u]-dp[j-2][v]);
        }
        dp[1][v]+=dp[0][u];
        dfs2(v);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        clr(node,-1);
        clr(dp,0);
        cnt = 0;
        int n;
        LL A,B;
        cin>>n>>K>>A>>B;
        for(int i=2;i<=n;i++){
            int u = (A*i+B)%(i-1)+1;
            add_side(u,i);
        }
        dfs1(1);
        dfs2(1);
        int ans = 0;
        for(int i=1;i<=n;i++){
            int sum = 0;
            for(int j=0;j<=K;j++)
                sum+=dp[j][i];
            ans^=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}
