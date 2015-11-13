/*======================================================
# Author: whai
# Last modified: 2015-10-20 15:38
# Filename: e.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int num[N], num_tot;
int opt[N], opt_tot;

LL pre_mul[N], pre_add[N];
LL bac_mul[N], bac_add[N];

char str[N];

void gao(char str[]) {
	int len = strlen(str);
	num_tot = opt_tot = 0;
	num[num_tot++] = 0;
	opt[opt_tot++] = 0;
	for(int i = 0; i < len; ++i) {
		if(str[i] >= '0' && str[i] <= '9') num[num_tot++] = str[i] - '0';
		else {
			if(str[i] == '+') opt[opt_tot++] = 0;
			else opt[opt_tot++] = 1;
		}
	}
	num[num_tot++] = 0;
	opt[opt_tot++] = 0;
	
	for(int i = 0; i < opt_tot; ++i) {
		if(i == 0) {
			if(opt[i] == 0) {
				pre_add[i] = num[i];
				pre_mul[i] = 1;
			} else {
				pre_add[i] = 0;
				pre_mul[i] = num[i];
			}
		} else {
			if(opt[i] == 0) {
				pre_add[i] = pre_add[i - 1] + pre_mul[i - 1] * num[i];
				pre_mul[i] = 1;
			} else {
				pre_add[i] = pre_add[i - 1];
				pre_mul[i] = pre_mul[i - 1] * num[i];
			}
		}
	}

	for(int i = opt_tot - 1; i >= 0; --i) {
		if(i == opt_tot - 1) {
			if(opt[i] == 0) {
				bac_add[i] = num[i + 1];
				bac_mul[i] = 1;
			} else {
				bac_add[i] = 0;
				bac_mul[i] = num[i + 1];
			}
		} else {
			if(opt[i] == 0) {
				bac_add[i] = bac_add[i + 1] + bac_mul[i + 1] * num[i + 1];
				bac_mul[i] = 1;
			} else {
				bac_add[i] = bac_add[i + 1];
				bac_mul[i] = bac_mul[i + 1] * num[i + 1];
			}
		}
	}
	//for(int i = 0; i < len; ++i) {
	//	cout<<pre_add[i]<<','<<pre_mul[i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 0; i < len; ++i) {
	//	cout<<bac_add[i]<<','<<bac_mul[i]<<' ';
	//}
	//cout<<endl;

	LL ans = 0;

	for(int i = 0; i < opt_tot - 1; ++i) {
		LL tmp_add = 0, tmp_mul = 1, mid;
		for(int j = i + 1; j < opt_tot; ++j) {
			if(opt[j] == 0) {
				tmp_add += tmp_mul * num[j];
				mid = tmp_add;
				tmp_mul = 1;
			} else {
				tmp_mul *= num[j];
				mid = tmp_add + tmp_mul;
			}
			//cout<<i<<' '<<j<<' '<<mid<<' '<<tmp_add<<' '<<tmp_mul<<endl;
			LL tmp = pre_add[i] + pre_mul[i] * mid * bac_mul[j] + bac_add[j];
			ans = max(ans, tmp);
		}
	}
	cout<<ans<<endl;
}

int main() {
	scanf("%s", str);

	gao(str);
	return 0;
}
