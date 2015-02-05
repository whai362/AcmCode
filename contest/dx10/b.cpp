#include <cstdio>
#include <cstring>
#include <math.h>
#include <iostream>
#define LL long long

using namespace std ;
int a[100010] ;
 
int main(){
	int T,n,casee = 1 ;
	scanf("%d",&T) ;
	while(T--){
		scanf("%d",&n) ;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",&a[i]) ;
		}
		LL ans = 1 ;
		bool flag = true ;
		for(int i = 2 ; i <= n ; i++){
			if(fabs(a[i]-a[i-1]) > 3){
				flag = false ;
			 	break ;
			}
			if(a[i] == a[i-1] && a[i] != 1){
				flag = false ;
				break ;
			}
			if(a[i] == 1 && a[i-1] == 2) ans ++ ;
			if(a[i] == 2 && a[i-1] == 1) ans ++ ;
		
		}
		printf("Case #%d: ",casee++) ;
		if(!flag){
			printf("0\n") ;
			continue;
		}
		else if(a[n] == 0){
			printf("%I64d\n",ans) ;
			continue ;
		}
		printf("%I64d\n",ans*2) ;
     }
     return 0 ;
}
