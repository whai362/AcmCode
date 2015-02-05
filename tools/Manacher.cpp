//主要是用来求某个字符串的最长回文子串
#include<iostream>
#include<vector>
using namespace std;
const int N=300010;
int n, p[N];
char s[N], str[N];
#define _min(x, y) ((x)<(y)?(x):(y))
void kp(){
    int i,mx = 0, id;
for(i=n; str[i]!=0; i++) str[i] = 0; 
//没有这一句有问题。。就过不了ural1297，比如数据：ababa aba
    for(i=1; i<n; i++){
        if( mx > i )
            p[i] = _min( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
        if( p[i] + i > mx ){
            mx = p[i] + i;
            id = i;
        }
    }
}
void init(){
	int i, j, k;
	str[0] = '$';str[1] = '#';
	for(i=0; i<n; i++){
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
	n = n*2+2; s[n] = 0;
}
int main(){
	int i, ans;
	while(scanf("%s", s)!=EOF){
		n = strlen(s);
		init(); kp(); ans = 0;
		for(i=0; i<n; i++)
			if(p[i]>ans)
				ans = p[i];
		printf("%d\n", ans-1);
	}
	return 0;
}

