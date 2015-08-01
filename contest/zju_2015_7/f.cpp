#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_NICO = 1e7+5;
bool ni[MAX_NICO];
void init() {
    ni[0] = false;
//    ni[0] = true;
    ni[1] = false;
    for (int i = 2; i < MAX_NICO; i ++) {
        if (ni[i]) continue;
        for (int j = i + i; j < MAX_NICO; j = j + i) {
            ni[j] = true;
        }
    }
    ni[6] = false;
    for (int i = 0; (1 << i) < MAX_NICO; i ++) {
        ni[1 << i] = false;
    }
}

const int N = 1e5 + 5;

int a[N];

vector<int> bl[1000];
vector<int> up[1000];
int cnt[1000];
void predo() {
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < 1000; ++i){
		bl[i].clear();
		up[i].clear();
	}

	int sz = sqrt(N) + 1;
	
	for(int i = 0; i < n; ++i){
		int bl_id = i / sz;
		bl[bl_id].push_back(a[i]);
		if(ni[a[i]]) ++cnt[bl_id];
	}
}

void query(int l, int r){
	int 
}


int main(){
	init();
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		predo(n);
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			int op;
			int l, r, p;
			scanf("%d", &op);
			if(op == 1){
				scanf("%d%d", &l, &r);
				query(l, r);
			} else if(op == 2){
				scanf("%d%d%d", &l, &r, &p);
				update(l, r, p);
			} else if(op == 3){
				scanf("%d%d", &l, &p);
				update(l, p);
			}
		}
	}
	return 0;
}
