/*
   约瑟夫问题，有n个人站成一圈，依次编号0～n，编号为m%n的人出局，然后剩下的n-1个人重新编号，让原来在m后面的那个人编号为0，剩下的依次递增，编号从1～n-1。再次让编号为m%(n-1)的人出局。不断重复此过程，直至只剩一个人为止。
*/
#include<iostream>
#include<cstdio>
using namespace std;
int k,m,n;
int Joseph(int num){
	int tmp;
	if(num==1) return 0;
	tmp=(Joseph(num-1)+k)%num;
	cout<<num<<' '<<tmp<<endl;
	return tmp;
}
int main(){
	while(scanf("%d%d%d",&n,&k,&m) && (n || k || m))
	  printf("%d\n",(Joseph(n-1)+m)%n+1);
	return 0;
}

