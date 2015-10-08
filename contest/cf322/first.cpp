#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define LL __int64

#define P pair<int, int>
#define X first
#define Y second

int main(){
	int n ,k;
	cin>>n>>k;

	LL ans = 0;

	priority_queue< P, vector<P>, greater<P> > q;
	for(int i = 0; i < n; ++i) {
		LL a;
		cin>>a;
		ans += a / 10;
		q.push(P(10 - a % 10, a));
	}

	//for(int i = 0; i < n; ++i) {
	//	P p = q.top(); q.pop();
	//	cout<<p.X<<' '<<p.Y<<endl;
	//}

	while(k && !q.empty()) {
		P now = q.top(); q.pop();
		if(now.Y < 100) {
			if(now.X <= k) {
				k -= now.X;
				now.Y += now.X;
				now.X = 10;
				q.push(now);
				++ans;
			} else {
				k = 0;
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
