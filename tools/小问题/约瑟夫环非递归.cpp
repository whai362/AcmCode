/*
   约瑟夫问题，有n个人站成一圈，依次编号0～n，编号为m%n的人出局，然后剩下的n-1个人重新编号，让原来在m后面的那个人编号为0，剩下的依次递增，编号从1～n-1。再次让编号为m%(n-1)的人出局。不断重复此过程，直至只剩一个人为止。
*/
#include <cstdio>
int main(){
    int i,k,m,n,s;
    while(scanf("%d%d%d",&n,&k,&m) &&(n || k || m)){
		s=0;
		for (i=2;i<n;i++){
		    s=(s+k)%i;
		}
		printf ("%d\n",(s+m)%n+1);
	}
	return 0;
}
