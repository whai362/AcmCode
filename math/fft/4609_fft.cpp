/*
   题意：给出10^5个边长，问任取三个组成三角形的概率。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define LL long long
const double PI=acos(-1.0);

struct complex{
    double r,i;
    complex(double _r = 0,double _i = 0){
        r = _r; i = _i;
    }
    complex operator +(const complex &b){
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b){
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b){
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(complex y[],int len){
    int i,j,k;
    for(i = 1, j = len/2;i < len-1;i++){
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k){
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}
/*
   快速傅里叶变换，求卷积
   使用方法见后面
*/
void fft(complex y[],int len,int on){
    change(y,len);
    for(int h = 2;h <= len;h <<= 1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h){
            complex w(1,0);
            for(int k = j;k < j+h/2;k++){
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

const int N = 400005;
complex x1[N];
int a[N/2];
LL num[N];	//fft的输入数组，和输出数组
LL sum[N];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);

		//使用方法
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			++num[a[i]];
		}
		sort(a,a+n);
		int len1=a[n-1]+1;
		int len=1;
		while(len<2*len1) len<<=1;
		for(int i=0;i<len1;++i){
			x1[i]=complex((double)num[i],0.0);
		}
		for(int i=len1;i<len;++i){
			x1[i]=complex(0.0,0.0);
		}
		fft(x1,len,1);
		for(int i=0;i<len;i++)
            x1[i]=x1[i]*x1[i];
        fft(x1,len,-1);
		for(int i=0;i<len;++i){
			num[i]=(LL)(x1[i].r+0.5);
		}
		len=2*a[n-1];

		//减掉取两个相同的组合
		for(int i=0;i<n;++i){
			--num[2*a[i]];
		}
		//选择的无序，除以2
		for(int i=1;i<=len;++i){
			num[i]/=2;
		}
		sum[0]=0;
		for(int i=1;i<=len;++i){
			sum[i]=sum[i-1]+num[i];
		}
		LL ans=0;
		for(int i=0;i<n;++i){
			ans+=sum[len]-sum[a[i]];
			//减掉一个取大，一个取小的
			ans-=(LL)(n-1-i)*i;
			//减掉一个取本身，另外一个取其它
			ans-=(LL)n-1;
			//减掉大于它的取两个的组合
			ans-=(LL)(n-1-i)*(n-2-i)/2;
		}
		LL tot=(LL)n*(n-1)*(n-2)/6;
		printf("%.7lf\n",(double)ans/tot);
	}
	return 0;
}
