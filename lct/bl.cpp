#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int T;
	T = 5;
	cout<<T<<endl;
	while(T--) {
		int n = 10;
		int q = 1000;
		cout<<n<<' '<<q<<endl;
		for(int i = 0; i < n; ++i) {
			int a = rand() % 10000 + 1;
			cout<<a<<' ';
		}
		cout<<endl;
		cout<<1<<' '<<1<<' '<<2<<endl;
		for(int i = 1; i < q; ++i) {
			int op = rand() % 5 + 1;
			cout<<op<<' ';
			if(op == 3) cout<<rand() % i + 1<<endl;
			else cout<<rand() % n + 1<<' '<<rand() % n + 1<<endl;
		}
	}
}
