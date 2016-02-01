/*题解：
  因为有多个分店，所以可以把分店当作起点，把多个起点压入队列尾，然后进行宽搜，然后可以得到任意一个分店到达任意一个点所需要花的最小步数，最后答案等于所有点步数*餐的份数的和。
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define LL long long

const int N = 1e3 + 5;
const int INF = 1000000000;

//坐标类
struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x; y = _y;
	}
};

//地图数组，其中-2表示不能经过的点，-1表示分店，其他表示要送到该点的餐的数量
int G[N][N];

//步数数组，其中step[x][y]表示从任意一个分店到达坐标为(x, y)的点所需要花的最小步数
int step[N][N];

//位移数组
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

//判断该点是否可以加到队列里面
bool legal(int x, int y, int n) {
	if(x >= 1 && x <= n && y >= 1 && y <= n && 
			G[x][y] != -2 && step[x][y] == INF)
		return true;
	return false;
}

void solve(int n) {
	queue<Point> que;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(G[i][j] == -1) {
				que.push(Point(i, j));	//把起点加入队列尾
				step[i][j] = 0;	//初始步数为0
			}

	while(!que.empty()) {
		Point now = que.front();
		que.pop();
		
		//从当前点向相邻的四个方向走
		for(int i = 0; i < 4; ++i) {
			int tmp_x = now.x + dx[i];
			int tmp_y = now.y + dy[i];
			if(legal(tmp_x, tmp_y, n)) {
				que.push(Point(tmp_x, tmp_y));	//如果符合条件，加入队列尾
				step[tmp_x][tmp_y] = step[now.x][now.y] + 1;	//步数+1
			}
		}
	}

	LL ans = 0;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(G[i][j] >= 0) {
				ans += (LL)G[i][j] * step[i][j];	//答案为步数*餐的份数的和
			}

	cout<<ans<<endl;
}

//初始化函数
void init(int n) {
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			step[i][j] = INF;
}

int main() {
	int n, m, k, d;
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = -1;
	}
	for(int i = 0; i < k; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		G[x][y] += c;
	}
	for(int i = 0; i < d; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = -2;
	}
	
	init(n);
	solve(n);

	return 0;
}

