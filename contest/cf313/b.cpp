#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200005;
char S[N], T[N];
void deal(int L, int R, char str[]){
	int len = R - L + 1;
	if(len % 2) return ;
	int mid = (L + R) >> 1;
	deal(L, mid, str);
	deal(mid + 1, R, str);
	int flag = 0;
	for(int i = L; i <= mid; ++i){
		if(str[i] == str[i + len/2]) continue;
		else if(str[i] < str[i + len/2]) break;
		else{
			flag = 1;
			break;
		}
	}
	if(!flag) return ;
	for(int i = L; i <= mid; ++i){
		swap(str[i], str[i + len/2]);
	}
}
void gao(char str[]) {
	int len = strlen(str);
	deal(0, len - 1, str);
}
int main(){
	cin>>S>>T;
	gao(S);
	gao(T);
	//cout<<S<<endl;
	//cout<<T<<endl;
	if(strcmp(S,T) == 0)
		puts("YES");
	else
		puts("NO");
}
