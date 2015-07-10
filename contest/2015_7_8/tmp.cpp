#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int n, m;
ll dp[2][(1<<11)+5];

void print(int x){
	for(int i=0;i<2;++i){
		if(x & (1 << i)) cout<<1;
		else cout<<0;
	}
}

int main () {
    while (scanf("%d%d", &n, &m) == 2) {
        int now = 0, pre = 1;

        if (n < m)
            swap(n, m);

        int e = (1<<m)-1;
        memset(dp[now], 0, sizeof(dp[now]));

        dp[now][e] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                swap(now, pre);
                memset(dp[now], 0, sizeof(dp[now]));

				cout<<i<<','<<j<<":"<<endl;

                for (int s = 0; s <= e; s++) {
                    if (j && !(s&(1<<(j-1))) && (s&(1<<j))){
                        dp[now][s | (1<<(j-1))] += dp[pre][s];
						
						cout<<"ºá·Å:";
						print(s);
						cout<<"->";
						print(s | (1<<(j-1)));
						cout<<endl;
					}
                    dp[now][s ^ (1<<j)] += dp[pre][s];
					cout<<"Êú·Å:";
					print(s);
					cout<<"->";
					print(s ^ (1<<j));
					cout<<endl;
                }
            }
        }
        printf("%lld\n", dp[now][e]);
    }
    return 0;
}
