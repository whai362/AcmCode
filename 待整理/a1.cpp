#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define N 100005
vector<int>G[N], P[N], tmp;
set<int>s[N];
set<int>::iterator it;
int n,m;
bool work(){
    for(int i = m; i>1; i--) {        
        for(int j = G[i].size()-1; j>=0; j--) {
            it = s[i-1].lower_bound(-G[i][j]);
            if(it==s[i-1].end())return false;
            int pos = lower_bound(G[i-1].begin(), G[i-1].end(), -(*it))-G[i-1].begin();
            P[i-1][pos] = j;            
            s[i-1].erase(it);
        }
    }
    return true;
}
void init(){
    for(int i = 0; i <= n; i++)G[i].clear(), s[i].clear(), P[i].clear();
}
int Stack[N];
int main(){
    int T, Cas = 1,i,j,k;cin>>T;
    while(T--) {
        init();
        scanf("%d %d",&n,&m);
        bool success = true;
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            for(int z = 0; z < k; z++)
            {
                scanf("%d",&j);
                G[i].push_back(j);
                s[i].insert(-j);
                if(z && G[i][z-1]>G[i][z]) 
                    success=false;
                P[i].push_back(-1);
            }
        }
        printf("Case #%d: ",Cas++);
        if(success && work()) {
            int top = 0;
            for(i = 0; i < P[1].size(); i++)
            {                
                int h = 1, l = i;
                tmp.clear();
                while(1)
                {
                    tmp.push_back(G[h][l]);
                    if(P[h][l]==-1)break;
                    l = P[h][l];
                    h++;                
                }            
                for(j=tmp.size()-1;j>=0;j--)
                    Stack[top++] = tmp[j];            
            }
            for(i=0;i<top;i++)
            printf("%d%c",Stack[i],i==top-1?'\n':' ');
        }
        else puts("No solution");
    }
    return 0;
}
B. Beautiful Garden

B:点击打开链接
暴力
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N = 42;
int n, a[N];
int dis[N * N], dep;
bool vis[N][N];
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        std::sort(a, a + n);
        dep = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                dis[dep++] = a[j] - a[i];
        std::sort(dis, dis + dep);
        dep = std::unique(dis, dis + dep) - dis;
        
        int ans = n - 1, cnt, idx, f;
        ll st;
        
        for (int i = 0; i < dep; ++i) {
            memset(vis, 0, sizeof vis);
            for (int k = 0; k < n; ++k)
                for (int z = 0; z < n; ++z)
                    if(!vis[k][z]) {
                        st = a[k] - (ll)z * dis[i];
                        cnt = idx = 0;
                        f = 1;
                        for (int l = 0; l < n; ++l) {
                            while (idx < n && a[idx] < st)
                                ++idx;
                            if (idx < n && st == a[idx]) {
                                if (vis[idx][l]) {
                                    f = 0;
                                    break;
                                }
                                vis[idx][l] = true;
                                ++cnt, ++idx;
                            }
                            st += dis[i];
                        }
                        if (f && n - cnt < ans)
                            ans = n - cnt;
                    }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    
    return 0;
}

E. Elegant String

E：点击打开链接
先得到一个dp方程
dp[i][j]表示字符串长度为i，结尾有j个数互不相同的方法数
然后得到转移方程再用矩阵快速幂加速
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define Matr 11
#define mod 20140518
struct mat{
    ll a[Matr][Matr],size;
    mat(){
        size = 0;
        memset(a, 0, sizeof a);
    }
};
mat multi(mat m1,mat m2){
    mat ans = mat(); ans.size = m1.size;
    for(int i = 1; i <= m1.size; i++)
        for(int j = 1; j<= m2.size; j++)
            if(m1.a[i][j])
                for(int k = 1; k <= m1.size; k++)
                    ans.a[i][k] = (ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%mod;
    return ans;
}
mat quickmulti(mat m,ll n){
    mat ans = mat();
    ll i;
    for(i=1;i<=m.size;i++)ans.a[i][i] = 1;
    ans.size = m.size;
    while(n){
        if(n&1)ans = multi(m,ans);
        m=multi(m,m);
        n /= 2;
    }
    return ans;
}
ll n,k;
int main(){
    ll T, Cas = 1;cin>>T;
    while(T--){
        cin>>n>>k;
        mat z = mat();
        for(ll i = 1; i <= k; i++)
            for(ll j = i; j <= k; j++)
                z.a[i][j] = 1;
        ll now = k;
        for(ll i = 2; i <= k; i++, now--)
            z.a[i][i-1]+=now;
        z.size = k;
        z = quickmulti(z, n-1);
        ll tmp = 0;
        for(ll i = 1; i <= k; i++)
            tmp += z.a[i][1];
        tmp *= (k+1);
        tmp %= mod;
        printf("Case #%lld: %lld\n",Cas++,tmp);
    }
    return 0;
}

H. Happy Reversal

H：点击打开链接
把所有数字取法后都一起排序，最大的减最小的即可
可能最大最小都来源一个数，则答案就是 第二大减最小 或者最大减第二小
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 20005;
ll a[N], b[N];
ll er[N];
int main() {
    int T;
    char s[66];
    er[0] = 1;
    for(int i = 1;i<63;i++)er[i] = er[i-1]*2;
    while(~scanf("%d", &T)) {
        for(int cas = 1; cas <= T; cas ++) {
            int n, m;
            scanf("%d%d", &n, &m);
            for(int i = 0; i < n; i ++) {
                scanf("%s", s);
                ll suma = 0;
                ll sumb = 0;
                for(int j = 0; j < m; j ++) {
                    suma = suma * 2 + (s[j] == '1');
                    sumb = sumb * 2 + (s[j] == '0');
                }
                a[i*2] = max(suma, sumb);
                a[i*2+1] = min(suma, sumb);
            }
            sort(a, a + n + n);
            ll ans;
            if( a[2*n-1] + a[0] + 1 == er[m] ) ans = max(a[2*n-2] - a[0], a[2*n-1] - a[1]);
            else ans = a[2*n-1] - a[0];
            printf("Case #%d: %lld\n", cas, ans);
        }
    }
    return 0;
}

J. Justice String

J：点击打开链接
hash二分第一个不同的字符距离0的位置，再二分第二个不同的字符距离第一个字符的位置
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 3000007;
int sa[MAX_N], ws[MAX_N], rank[MAX_N], height[MAX_N];
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAX_N],wb[MAX_N],wv[MAX_N],wss[MAX_N];
struct suffix {
    int c0(int *r, int a, int b) {
     return r[a] == r[b] && r[a+1] == r[b+1] && r[a+2] == r[b+2];
    }
    int c12(int k,int *r,int a,int b) {
       if(k == 2)
        return r[a] < r[b] || ( r[a] == r[b] && c12(1,r,a+1,b+1) );
      else return r[a] < r[b] || ( r[a] == r[b] && wv[a+1] < wv[b+1] );
    }
    void sort(int *r,int *a,int *b,int n,int m)    {
        int i;
        for(i = 0;i < n;i++)wv[i] = r[a[i]];
        for(i = 0;i < m;i++)wss[i] = 0;
        for(i = 0;i < n;i++)wss[wv[i]]++;
        for(i = 1;i < m;i++)wss[i] += wss[i-1];
        for(i = n-1;i >= 0;i--)
        b[--wss[wv[i]]] = a[i];
    }
    void dc3(int *r,int *sa,int n,int m) {
        int i, j, *rn = r + n;
        int *san = sa + n, ta = 0, tb = (n+1)/3, tbc = 0, p;
        r[n] = r[n+1] = 0;
        for(i = 0;i < n;i++)if(i %3 != 0)wa[tbc++] = i;
        sort(r + 2, wa, wb, tbc, m);
        sort(r + 1, wb, wa, tbc, m);
        sort(r, wa, wb, tbc, m);
        for(p = 1, rn[F(wb[0])] = 0, i = 1;i < tbc;i++)
        rn[F(wb[i])] = c0(r, wb[i-1], wb[i]) ? p - 1 : p++;
        if(p < tbc)dc3(rn,san,tbc,p);
        else for(i = 0;i < tbc;i++)san[rn[i]] = i;
        for(i = 0;i < tbc;i++) if(san[i] < tb)wb[ta++] = san[i] * 3;
        if(n % 3 == 1)wb[ta++] = n - 1;
        sort(r, wb, wa, ta, m);
        for(i = 0;i < tbc;i++)wv[wb[i] = G(san[i])] = i;
        for(i = 0, j = 0, p = 0;i < ta && j < tbc;p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
        for(;i < ta;p++)sa[p] = wa[i++];
        for(;j < tbc;p++)sa[p] = wb[j++];
    }
    void DA(int str[],int sa[],int n,int m)    {
        for(int i = n;i < n*3;i++)
            str[i] = 0;
        dc3(str, sa, n+1, m);
        int i,j,k = 0;
        for(i = 0;i <= n;i++)rank[sa[i]] = i;
        for(i = 0;i < n; i++)
        {
            if(k) k--;
            j = sa[rank[i]-1];
            while(str[i+k] == str[j+k]) k++;
            height[rank[i]] = k;
        }
    }
};
int RMQ[MAX_N], mm[MAX_N], best[20][MAX_N];
void initRMQ(int n) {
    mm[0] = -1;
    for(int i = 1; i <= n; ++i) {
        mm[i]=((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        best[0][i] = i;
    }
    for (int i = 1; i <= mm[n]; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            int a = best[i - 1][j];
            int b = best[i - 1][j + (1 << (i - 1))];
            if (RMQ[a] < RMQ[b]) best[i][j] = a;
            else best[i][j] = b;
        }
    }
}
int query(int a, int b) {
    int t = mm[b - a + 1];
    b -= (1 << t) - 1;
    a = best[t][a], b = best[t][b];
    return RMQ[a] < RMQ[b] ? a : b;
}
int lcp(int a, int b) {
    a = rank[a], b = rank[b];
    if (a > b) swap(a, b);
    return height[query(a + 1, b)];
}
char A[MAX_N],B[MAX_N];
int r[MAX_N], da[MAX_N];
int main() {
    int T;
    int cas = 0;
    scanf("%d",&T);
    while(T-- > 0) {
        suffix ar;
        scanf("%s%s",A, B);
        int len1 = strlen(A);
        int len2 = strlen(B);
        if(len1 < len2) {
            printf("Case #%d: -1\n", ++cas);
            continue;
        }
        int n = len1 + len2 + 1;
        for(int i = 0; i < len1; ++i) r[i] = A[i];
        for(int i = 0; i < len2; ++i) r[len1 + 1 + i] = B[i];
        r[len1] = 1;
        r[n] = 0;
        ar.DA(r, sa, n, 128);
    
        for(int i = 1; i <= n; ++i)
          RMQ[i] = height[i];
        initRMQ(n);
        int ans = -1;
        for(int i = 0; i <= len1 - len2; ++i) {
            int st = i;
            int ed = len1 + 1;
            int tmp = lcp(st, ed);
        //    printf("here1 %d %d %d\n", st, ed, tmp);
            st += tmp;
            ed += tmp;
            if(ed >= n) {
                ans = i;
                break;
            }
            st++;
            ed++;
            if(ed >= n) {
                ans = i;
                break;
            }
            tmp = lcp(st, ed);
        //    printf("here2 %d %d %d\n", st, ed, tmp);
            st += tmp;
            ed += tmp;
            if(ed >= n) {
                ans = i;
                break;
            }
            st++;
            ed++;
            if(ed >= n) {
                ans = i;
                break;
            }
            tmp = lcp(st, ed);
    //        printf("here3 %d %d %d\n", st, ed, tmp);
            st += tmp;
            ed += tmp;
            if(ed >= n)  {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}


