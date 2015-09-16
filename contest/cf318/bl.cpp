#include <iostream>
using namespace std;
#define LL __int64
const int INF = 1e9;
int main() {
	int n = 11;
	cout<<n<<endl;
	LL out = 1;
	for(int i = 0; out < INF; ++i)
		out *= 2;
	cout<<out<<' ';
	out = 1;
	for(int i = 0; out < INF; ++i)
		out *= 3;
	cout<<out<<' ';
	out = 1;
	for(int i = 0; i < 4; ++i)
		out *= 7;
	cout<<out<<' ';
	for(int i = 0; i < (n - 3) / 2; ++i) {
		out = 1;
		for(int i = 0; out < INF; ++i)
			out *= 2;
		cout<<out<<' ';
		out = 1;
		for(int i = 0; out < INF; ++i)
			out *= 3;
		cout<<out<<' ';
	}
}
