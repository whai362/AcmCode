#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
	int x;
	while(scanf("%d", &x)!=EOF) {
		srand(100321);
		for(int i = 0; i < 16; ++i) {
			if(rand()%2) cout<<"GTW wins"<<endl;
			else cout<<"DSY wins"<<endl;
		}
	}
	return 0;
}
