/*codeforces 508 E. Arthur and Brackets
  题意：
  有n对括号，按顺序，给出每对括号长度的范围，输出一种情况。
  限制：
  1 <= n <= 600
  思路：
  贪心：能匹配的先匹配。
  括号匹配问题，果断先思考用栈能不能做。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=605;
int stk[N],top;
char ans[2*N];
int len=0;
int pos[N],l[N],r[N];
int main(){
	int n;
	int flag=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&l[i],&r[i]);
		if(flag==0) continue;
		stk[++top]=i;
		pos[i]=len;
		ans[len++]='(';
		while(top>0 && pos[stk[top]]+l[stk[top]]<=len){
			if(pos[stk[top]]+r[stk[top]]<len){
				flag=0;
				break;
			}
			else{
				ans[len++]=')';
				--top;
			}
		}
	}
	if(flag && top==0){
		puts(ans);
	}
	else{
		puts("IMPOSSIBLE");
	}
	return 0;
}
