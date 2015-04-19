/*poj 2406
  题意：
  给出一个字符串，问这个字符串最多由多少个重复的子串构成。
  限制：
  1 <= len <= 1e6
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*
这个模板 字符串是从0开始的
Next数组是从1开始的
*/
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
	while(scanf("%s",T)!=EOF){
		if(T[0]=='.') break;
		tlen=strlen(T);
		getNext();
		int zq=tlen-nxt[tlen];
		if(tlen%zq==0)
			printf("%d\n",tlen/zq);
		else 
			puts("1");
	}
	return 0;
}
