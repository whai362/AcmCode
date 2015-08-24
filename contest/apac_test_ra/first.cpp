#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e5 + 5;

string deal(string S) {
	reverse(S.begin(), S.end());
	for(int i = 0; i < S.length(); ++i) {
		if(S[i] == '0') S[i] = '1';
		else S[i] = '0';
	}
	return S;
}

int main() {
	cout<<(1LL << 62)<<endl;
	int n;
	string S = "0", T;
	for(int i = 0; i < 20; ++i) {
		T = S + "0" + deal(S);
		S = T;
		if(S.length() > INF) break;
	}
	//cout<<S<<endl;
	int TT;
	scanf("%d", &TT);
	int cas = 0;
	while(TT--) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %c\n", ++cas, S[n - 1]);
	}
	return 0;
}
