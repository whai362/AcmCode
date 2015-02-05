#include<cstdio>
#include<iostream>
using namespace std;
void dfs(int a){
	dfs(a);
}
int main(){
	dfs(1);
	return 0;
}
