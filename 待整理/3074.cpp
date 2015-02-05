#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100], _map[100];
int r[10][10],
	c[10][10],
	cell[10][10],
	cellPos[]={0,3,6,27,30,33,54,57,60},
	dc[]={0,1,2,9,10,11,18,19,20};
void predeal(){
	for(int i=0; i<81; ++i){
		if(str[i] != '.'){
			int num = str[i] - '0',
				row = i / 9,
				col = i - i / 9 * 9;
			_map[i] = str[i];
			r[row][num] = 1;
			++r[row][0];
			c[col][num] = 1;
			++c[col][0];
			cell[row / 3 * 3 + col / 3][num] = 1;
			++cell[row / 3 * 3 + col / 3][0];
		}
	}
}
bool ok(int n, int num){
	int row = n / 9,
		col = n - n / 9 * 9;
	if(!r[row][num] && !c[col][num] &&
			!cell[row / 3 * 3 + col / 3][num])
		return true;
	return false;
}
void fill(int n, int num){
	int row = n / 9,
		col = n - n / 9 * 9;
	_map[n] = num + '0';
	r[row][num] = 1;
	++r[row][0];
	c[col][num] = 1;
	++c[col][0];
	cell[row / 3 * 3 + col / 3][num] = 1;
	++cell[row / 3 * 3 + col / 3][0];
}
void unfill(int n, int num){
	int row = n / 9,
		col = n - n / 9 * 9;
	r[row][num] = 0;
	--r[row][0];
	c[col][num] = 0;
	--c[col][0];
	cell[row / 3 * 3 + col / 3][num] = 0;
	--cell[row / 3 * 3 + col / 3][0];
}
bool cut(int n){
	int row = n / 9,
		col = n - n / 9 * 9;
	if(r[row][0] == 8){
		int num;
		for(int i=1; i<10; ++i){
			if(r[row][i] == 0){
				num=i;
				break;
			}
		}
		for(int i=row*9; i<(row+1) * 9; ++i){
			if(_map[i] == 0){
				if(ok(i, num)) return true;
				return false;
			}
		}
	}
	if(c[col][0] == 8){
		int num;
		for(int i=1; i<10; ++i){
			if(c[col][i] == 0){
				num=i;
				break;
			}
		}
		for(int i=col; i<81; i+=9){
			if(_map[i] == 0){
				if(ok(i, num))  return true;
				return false;
			}
		}
	}
	int tmp = row / 3 * 3 + col/3;
	if(cell[tmp][0] == 8){
		int num;
		for(int i=1; i<10; ++i){
			if(cell[tmp][i] == 0){
				num = i;
				break;
			}
		}
		int pos=cellPos[tmp];
		for(int i=0; i<9; ++i){
			if(_map[pos+dc[i]] == 0){
				if(ok(pos+dc[i],num)) return true;
				return false;
			}
		}
	}
	return true;
}
bool dfs(int n){
	if(n>=81) return true;
	if(str[n] == '.'){
		for(int i=1; i<10; ++i){
			if(ok(n,i)){
				fill(n,i);
				if(cut(n) && dfs(n+1)) return true;
				unfill(n,i);
			}
		}
		return false;
	}
	else return dfs(n+1);
}
int main() {
	int n;
	while(scanf("%s",str) && str[0] != 'e'){
		memset(_map,0,sizeof(_map));
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		memset(cell,0,sizeof(cell));
		predeal();
		dfs(0);
		puts(_map);
	}
	return 0;
}
