#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 2 * 1e4 + 5;

int workzd(int len, char str[]) {
	int i=0,j=1,k=0;
	while(i<len && j<len && k<len) {
		int t = str[(i+k)%len] - str[(j+k)%len];
		if(!t) k++;
		else {,
			if(t>0) j = j+k+1;
			else i = i+k+1;
			if(i == j) j++;
			k = 0 ;
		}
	}
	return i<j?i:j;
}

char str[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s", str);
		int p1 = workzd(n, str);
		reverse(str, str + n);
		int p1 = workzd
		//cout<<workzd(n, str)<<endl;
	}
}

