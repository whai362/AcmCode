#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const int maxn = 200;
bool sex[maxn];
int da[maxn][maxn];
int n, m, q;

int Q()
{
	int count = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			if (sex[i]^sex[j]) count += da[i][j];
		}
	return count;
}

int main()
{
	int T;
	cin >> T;

	for (int ti = 1; ti <= T; ti++) {
		memset(da, 0, sizeof(da));
		cin >> n >> m >> q;
		cout << "Case #" << ti << ":" << endl;
		for (int i = 1; i <= n; i++)
			cin >> sex[i];
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			da[x][y] = da[y][x] = z;
		}
		for (int i = 0; i < q; i++) {
			int tmp;
			cin >> tmp;
			if (tmp == 3) {
				cout << Q() << endl;
			} else
			if (tmp == 2) {
				int x, y, z;
				cin >> x >> y >> z;
				da[x][y] = da[y][x] = z;
			} else {
				int x;
				cin >> x;
				sex[x] = !sex[x];
			}
		}
	}
}
