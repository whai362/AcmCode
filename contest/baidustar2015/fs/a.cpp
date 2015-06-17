#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_LAB  = 6;
const int MAX_EDGE = 400*MAX_LAB;
const int MAX_NODE = 40+MAX_EDGE;
const int MAX_ANS = MAX_NODE;

typedef struct { int x, y; char lab; } arrow;

void compute_reachabilty(arrow arr[], int N, int A, int G, bool r[])
{
	bool changed;

	r[G] = true;
	do {
		int i;
		changed = false;
		for(i=0; i<A; ++i)
			if( !r[arr[i].x] && r[arr[i].y] )
				r[arr[i].x] = changed = true;
	} while( changed );
}

void solve(arrow arr[], int N, int A, int S, int G, int SpellLimit)
{
	int  i,j,k;
	char answer[MAX_ANS+1] = {};
	bool cur[MAX_NODE] = {};
	bool r[MAX_NODE] = {};

	compute_reachabilty(arr, N, A, G, r);
	if( !r[S] ) {
		puts("Tough way!");
		return;
	}

	cur[S] = true;

	for(i=0; i<SpellLimit; ++i) {
		if( cur[G] ) {
			puts(answer);
			return;
		}

		bool next[MAX_NODE] = {};
		char nextLab = 127;
		for(k=0; k<A; ++k)
			if( cur[arr[k].x] && r[arr[k].y] && arr[k].lab<=nextLab ) {
				if( arr[k].lab < nextLab ) {
					memset(next, 0, sizeof(next));
					nextLab = arr[k].lab;
				}
				next[arr[k].y] = true;
			}
		answer[i] = nextLab;
		memcpy(cur, next, sizeof(cur));
	}

	puts("Tough way!");
}

int main()
{
	int N,A,S,G;
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d%d%d%d",&N,&A,&S,&G);
		int i,j,ai=0,SpellLimit = MAX_LAB*N;
		arrow arr[MAX_EDGE];

		for(i=0; i<A; ++i) {
			int  fr, to;
			char lab[99];
			scanf("%d %d %s", &fr, &to, lab);

			for(j=0; lab[j]; ++j) {
				int   x = j==0 ? fr : N-1;
				int   y = lab[j+1] ? N++ : to;
				arrow a = {x, y, lab[j]};
				arr[ai++] = a;
			}
		}
		printf("Case #%d:\n",++cas);
		solve(arr, N, ai, S, G, SpellLimit);
	}
	return 0;
}
