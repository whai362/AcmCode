#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define LL long long

const int N = 1e5 + 5;

char str[N];
int str_len;

char bac[N];
int bac_len;
vector<char> bac_str[70];

int limit = 0;

int k[N];

int sum[N][30];

void predo(char str[]) {
    str_len = strlen(str);
	bac_len = str_len;
    for(int i = 0; i < str_len; ++i) {
        if(i == 0) {
            sum[0][str[i] - 'a'] = 1;
        } else {
            for(int j = 0; j < 30; ++j) {
                sum[i][j] = sum[i - 1][j];
            }
            ++sum[i][str[i] - 'a'];
        }
		bac[i] = str[i];
    }
}

void shift(int id, int x) {
	for(int i = bac_len - x; i < bac_len; ++i) {
		bac_str[id].push_back(bac[i]);
	}
	if(bac_len < (limit - id) * 100) {
		int new_len = bac_len;
		for(int i = bac_len - x; i < bac_len - x + bac_len; ++i) {
			bac[new_len++] = bac[i % bac_len];
		}
		bac_len = new_len;
	} else {
		bac_len -= x;
		
	}
}

LL ss[70][30][105];

LL gao(LL x, char ch) {
	if(x == 0) return 0;
	if(x <= str_len) {
		return sum[x - 1][ch - 'a'];
	}
	LL pre = sum[str_len - 1][ch - 'a'];
	LL pre_len = str_len;
	int p = 0;
	while(pre_len * 2 <= x) {
		pre *= 2;
		pre_len *= 2;
		++p;
	}

	//cout<<pre_len<<' '<<pre<<' '<<p<<endl;
	if(x - pre_len > k[p]) {
		LL add = ss[p][ch - 'a'][bac_str[p].size()];
		//for(int i = 0; i < bac_str[p].size(); ++i) {
		//	if(bac_str[p][i] == ch) ++add;
		//}
		return pre + add + gao(x - pre_len - k[p], ch);
	} else {
		LL add = ss[p][ch - 'a'][x - pre_len];
		//for(int i = 0; i < x - pre_len; ++i) {
		//	if(bac_str[p][i] == ch) ++add;
		//}
		return pre + add;
	}
}



int main() {
    scanf("%s", str);

    predo(str);

    int n, m;
    scanf("%d%d", &n, &m);

	LL tmp_len = str_len;

	while(tmp_len < 2 * 1e18) {
		++limit;
		tmp_len *= 2;
	}
	tmp_len = str_len;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &k[i]);
		if(i <= limit) {
			k[i] %= tmp_len;
			shift(i, k[i]);
			tmp_len *= 2;
		}
    }
	for(int i = 0; i < 70; ++i) {
		for(int j = 0; j < bac_str[i].size(); ++j) {
			for(int l = 0; l < 30; ++l) {
				ss[i][l][j + 1] = ss[i][l][j];
			}
			char ch = bac_str[i][j] - 'a';
			++ss[i][ch][j + 1];
		}
	}
	//for(int i = 0; i < 1; ++i) {
	//	for(int j = 0; j < bac_str[i].size(); ++j) {
	//		cout<<bac_str[i][j];
	//	}
	//	cout<<endl;
	//}

    char ch[3];
    for(int i = 0; i < m; ++i) {
        LL l, r; 
		scanf("%I64d%I64d", &l, &r);
        scanf("%s", ch);
        printf("%I64d\n", gao(r, ch[0]) - gao(l - 1, ch[0]));
    }
    return 0;
}
