#include<stdio.h>
int test(int k,int m)
{
 int i,j,n=2*k;
 for(i=0;i<k;i++){
  j=(j+m-1)%(n-i);
  if(j<k){
   return(0);
  }
 }
 return(1);
}
main()
{
 int a,b,k,j[15];
 for(a=1;a<15;a++){
  b=a+1;
  while(1){
   if(test(a,b)){
    j[a]=b;
    break;
   }
   if(test(a,b+1)){
    j[a]=b+1;
    break;
   }
   b+=a+1;
  }
 }
 while(scanf("%d",&k)!=EOF){
  printf("%d\n",j[k]);
 }
}
