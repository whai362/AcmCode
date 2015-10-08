#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1000001;
int a[N], f[N], d[N]; // d[i]用于记录a[0...i]的最大长度
int bsearch(const int *f, int size, const int &a)

{

    int l=0, r=size-1;

    while( l <= r )

    {

        int mid = (l+r)/2;

        if( a >= f[mid-1] && a < f[mid] ) return mid; // >&&<= 换为: >= && <

        else if( a < f[mid] ) r = mid-1;

        else l = mid+1;

    }

}

int LIS(const int *a, const int &n){

     int i, j, size = 1;

     f[0] = a[0]; d[0] = 1;

     for( i=1; i < n; ++i ){

          if( a[i] < f[0] ) j = 0;                 // <= 换为: <

         else if( a[i] >= f[size-1] ) j = size++;   // > 换为: >=

         else j = bsearch(f, size, a[i]);

         f[j] = a[i]; d[i] = j+1;

     }

     return size;

}
int main(int argc, char const *argv[])
{
    int n,t;
    scanf("%d%d",&n,&t);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int m=min(t,t);
    for (int i=1;i<m;i++)
        for (int j=0;j<n;j++)
            a[i*n+j]=a[j];
    int ans=LIS(a,n*m);
	cout<<ans<<endl;
	//cout<<ans<<endl;
    //sort(a,a+n);
    //int MAX=0,cnt=1;
	//for (int i=1;i<n;i++) {
	//	if (a[i]==a[i-1]) cnt++;
	//	else
	//	{
	//		//cout<<a[i]<<' '<<cnt<<endl;
	//		MAX=max(MAX,cnt);
	//		cnt=1;
	//	}
	//}
    //MAX=max(MAX,cnt);
    //printf("%d\n",ans+MAX*(t-m) );
    return 0;
}
