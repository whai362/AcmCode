/*======================================================
# Author: whai
# Last modified: 2015-12-18 19:40
# Filename: tmp.cpp
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
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 55;
const double PI = acos(-1.0);

double a[N];
double fac[N];

int main() {
	srand(time(NULL));
	double x = -3;
	for(int i = 0; i < 50; ++i) {
		double r = (double)(rand() % RAND_MAX) / RAND_MAX;
		a[i] = sin(PI * x) / (PI * x) + 0.1 * x + 0.05 * r;
		x += 6.0 / 49;
		cout<<a[i]<<' ';
	}
	cout<<endl;
	
	for(int i = 0; i < 50; ++i) {
		fac[0] += a[i];
	}
	fac[0] /= 50;
	//cout<<fac[0];

	for(int i = 1; i <= 30; ++i) {
		x = -3;
		double sum = 0;
		int f = (i + 1) / 2;
		if(i % 2) {
			for(int j = 0; j < 50; ++j) {
				fac[i] += a[j] * sin(x * f / 2);
				sum += sin(x * f / 2);
				x += 6.0 / 49;
			}
		} else {
			for(int j = 0; j < 50; ++j) {
				fac[i] += a[j] * cos(x * f / 2);
				sum += cos(x * f / 2);
				x += 6.0 / 49;
			}
		}
		fac[i] /= 50;
		//cout<<' '<<fac[i]<<','<<sum<<endl;
	}
	//cout<<endl;

	x = -3;
	for(int i = 0; i < 50; ++i) {
		double out = fac[0];
		for(int j = 1; j <= 30; ++j) {
			int f = (j + 1) / 2;
			if(j % 2) {
				out += fac[j] * sin(x * f / 2);
			} else {
				out += fac[j] * cos(x * f / 2);
			}
		}
		x += 6.0 / 49;
		cout<<out<<' ';
	}
	cout<<endl;

	return 0;
}
