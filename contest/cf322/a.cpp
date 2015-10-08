#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m;
	cin>>n>>m;
	cout<<min(n, m)<<' '<<(n + m - 2 * min(n, m)) / 2<<endl;
}
