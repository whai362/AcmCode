#include<cstdio>
#include<cstring>
using namespace std;
char a[100020],B[100020];;
int LIS(int d[], int n){
    int left,right,mid,i,len = 1;
    B[1]=d[1]; 
    for(i=2;i<=n;++i){
        left=1,right=len;
        while(left<=right){
            mid=(left+right)/2;
            if(B[mid]<d[i]) left=mid + 1; 
            else right=mid-1;
        }
        B[left]=d[i]; 
        if(left>len) len++; 
    }
    return len;
}
int main(){
 int n,i;
 scanf("%s",a);
 LIS(a,strlen(n));
 printf("%s\n",B);
 return 0;
}

