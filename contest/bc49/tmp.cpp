#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=300010;
int n, p[N];
char s[N], str[N];
void kp(){
	int i,mx = 0, id;
	for(i=n; str[i]!=0; i++) str[i] = 0; 
	for(i=1; i<n; i++){
		if( mx > i )
			p[i] = min( p[2*id-i], p[id]+id-i );
		else
			p[i] = 1;
		for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
		if( p[i] + i > mx ){
			mx = p[i] + i;
			id = i;
		}
	}
}
bool ok1[N], ok2[N];
void init(){
	memset(ok1, 0, sizeof(ok1));
	memset(ok2, 0, sizeof(ok2));
	int i, j, k;
	str[0] = '$';str[1] = '#';
	for(i=0; i<n; i++){
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
	n = n*2+2; s[n] = 0;
}

bool ok(int l, int r, int len) {
	if(l == 0 && r == len - 1) return true;
	else if(l > 0 && r < len - 1 && ok1[l - 1] && ok2[r + 1]) return true;
	return false;
}

int main(){
	int L;
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		n = L = strlen(s);
		if(L < 3) {
			puts("-1");
			continue ;
		}
		init(); kp();
		
		for(int i = 1; i < n; ++i) {
			int len = p[i] - 1;
			int o = i / 2 - 1;
			int l = o - len / 2;
			int r = o + len / 2;
			if(str[i] == '#') ++l;
			if(l == 0) ok1[r] = 1;
			if(r == L - 1) ok2[l] = 1;
		}

		int flag = 0;

		for(int i = 1; i < n; ++i) {
			int len = p[i] - 1;
			int o = i / 2 - 1;
			int l = o - len / 2;
			int r = o + len / 2;
			if(str[i] == '#') ++l;
			if(ok(l, r, L)) {
				flag = 1;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");

		//for(int i = 0; i < L; ++i) {
		//	cout<<ok1[i];
		//}
		//cout<<endl;
		//for(int i = 0; i < L; ++i) {
		//	cout<<ok2[i];
		//}
		//cout<<endl;

		//cout<<str<<endl;
		//for(i=0; i<n; i++) {
		//	cout<<p[i];
		//}
		//cout<<endl;
		//	if(p[i]>ans)
		//		ans = p[i];
		//printf("%d\n", ans-1);
	}
	return 0;
}

