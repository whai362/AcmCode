/*======================================================
# Author: whai
# Last modified: 2015-11-01 19:05
# Filename: frist.cpp
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

int main() {
	int T;
	double a[4], l;
	scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= 3; ++i) {
			scanf("%lf", &a[i]);
		}
		scanf("%lf", &l);
		sort(a + 1, a + 1 + 3);
		//for(int i = 1; i <= 3; ++i){
		//	cout<<a[i]<<' ';
		//}
		//cout<<endl;
		double sum = a[1] + a[2] + a[3] + l;
		double avg = sum / 3;
		double ans;
		if(a[3] <= avg) {
			ans = sqrt(sum / 2 * (sum / 2 - avg) * (sum / 2 - avg) * (sum / 2 - avg));
		} else if(a[2] <= avg) {
			double tmp = (sum - a[3]) / 2;
			if(a[2] <= tmp) {
				ans = sqrt(sum / 2 * (sum / 2 - a[3]) * (sum / 2 - tmp) * (sum / 2 - tmp));
			} else {
				tmp = sum - a[3] - a[2];
				ans = sqrt(sum / 2 * (sum / 2 - a[3]) * (sum / 2 - a[2]) * (sum / 2 - tmp));
			}
		} else {
			double tmp = sum - a[3] - a[2];
			ans = sqrt(sum / 2 * (sum / 2 - a[3]) * (sum / 2 - a[2]) * (sum / 2 - tmp));
		}
		printf("%.10f\n", ans);
	}
	return 0;
}

