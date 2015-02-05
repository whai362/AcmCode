#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T;
char str[50], slen;
char leftnum[50], rightnum[50];
char ans[50];
long long target;
long long getnm(int l, int r)
{
    long long ans = 0;
    for (int i = 1; i <= l; i++)
    {
        ans *= 10;
        ans += leftnum[i];
    }
    for (int i = r; i >= 1; i--)
    {
        ans *= 10;
        ans += rightnum[i];
    }
    return ans;
}
long long dfs(int k, int r, int eq)
{
	// printf("k=%4d,r=%4d,eq=%4d\n",k,r,eq);
    long long ans = -1;
    if (k + r - 1 >= slen)
    {
        if (k + r - 1 > slen)
            return -1ll;
        ans = getnm(k - 1, r);
        // printf("getnum=%lld\n",ans);
        if (ans < target)
            return ans;
        return -1ll;
    }
    for (int i = eq ? str[k] : 9; i >= 0; i--)
    {
        leftnum[k] = i;
        if ((k == 1 || leftnum[k] != leftnum[k - 1]) && !(k == 1 && i == 0) && !(k+r == slen))
        {
            for (int l = 1; l + r + k <= slen; l++)
            {
                rightnum[r + l] = i;
                ans = max(ans, dfs(k + 1, r + l, eq && (i == str[k])));
            }
        }
        else
            ans = max(ans, dfs(k + 1, r, eq && i == str[k]));
        if (ans  > 0 )
            return ans;
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &target);
        sprintf(str+1, "%lld", target);
        slen = strlen(str+1);
        for (int i = 1; i<=slen; i++)
            str[i] -= '0';
        printf("%lld\n",dfs(1, 0, 1));
    }
    return 0;
}
