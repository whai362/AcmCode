#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;

int cnt[N];
int s = 0;
int dfs(int x) 
{
	//static FILE*fout = fopen("XX" , "w");
	if(x == 10000000)
		return 0;
	++s;
	
	//fprintf(fout ,"%d\n" , x);

	return dfs(x + 1) + 1;
}

int main() {
	cout<<(1LL<<31) - 1<<endl;
	int n;
	int a;
	cin>>n;
	s = 0;
	for(int i = 0; i < n; ++i) {
		cin>>a;
		++cnt[a];
		printf("%d%c", cnt[a] + s, i == n - 1 ? '\n' : ' ');
	}
	cout<<endl;
	return 0;
}
