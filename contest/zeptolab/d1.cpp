/*codeforces 526 d Om Nom and Necklace
  题意：
  给出一个字符串，问对于字符串的每个位置p，求从0到p的字符串是否符合格式：S=A+B+A+B+A+...+A+B+A，其中A,B是字符串，且可以是空串。
  限制：
  字符串长度1e6
  思路：
  next数组的灵活运用。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
void getNext(){
	int j, k;
	j = 0; k = -1; nxt[0] = -1;
	while(j < tlen)
		if(k == -1 || T[j] == T[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];

}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",T);
	tlen=n;
	getNext();
	//for(int i=1;i<=n;++i){
	//	cout<<i<<' '<<nxt[i]<<endl;
	//}
	for(int i=0;i<n;++i){
		int p=i+1;
		int bl=p/(p-nxt[p]);
		if(p%(p-nxt[p])==0){
			if(bl/k>=bl%k) putchar('1');
			else putchar('0');
		}
		else{
			if(bl/k>bl%k) putchar('1');
			else putchar('0');
		}
	}
	puts("");
	return 0;
}
