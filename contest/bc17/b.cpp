#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define LL __int64
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

int m,cnt;
int sorted[N];
vector<int> _map[100005];

vector<LL> gao;

int main(){
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);

		//使用方法
		memset(num,0,sizeof(num));
		cnt=0;
		gao.clear();
		for(int i=0;i<=n*100;++i){
			_map[i].clear();
		}
		for(int i=0;i<n;++i){
			scanf("%d",&m);
			for(int j=0;j<m;++j){
				scanf("%d",&a[cnt]);
				sorted[cnt]=a[cnt];
				_map[i].push_back(a[cnt++]);
			}
		}
		sorted[cnt]=k;

		int ucnt;
		sort(sorted,sorted+cnt+1);
		ucnt=unique(sorted,sorted+cnt+1)-sorted;
		
		int _max=0;
		for(int i=0;i<cnt;++i){
			a[i]=lower_bound(sorted,sorted+ucnt,a[i])-sorted+1;
			_max=max(_max,a[i]);
			++num[a[i]];
		}
		//for(int i=0;i<cnt;++i){
		//	cout<<a[i]<<' ';
		//}
		//cout<<endl;

		//for(int i=0;i<=_max;++i){
		//	cout<<num[i]<<' ';
		//}
		//cout<<endl;

		for(int i=0;i<n;++i){
			sort(_map[i].begin(),_map[i].end());
			for(int j=0;j<_map[i].size();++j){
				_map[i][j]=lower_bound(sorted,sorted+ucnt,_map[i][j])-sorted+1;
			}
		}

		int len1=_max+1;
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
		len=_max*2;
		
		//for(int i=0;i<=len;++i){
		//	cout<<'!'<<num[i]<<' ';
		//}
		//cout<<endl;

		//减掉取两个相同的组合
		for(int i=0;i<cnt;++i){
			--num[2*a[i]];
		}

		//for(int i=0;i<=len;++i){
		//	cout<<'!'<<num[i]<<' ';
		//}
		//cout<<endl;

		//选择的无序，除以2
		for(int i=0;i<=len;++i){
			num[i]/=2;
		}
	
		//for(int i=1;i<=len;++i){
		//	cout<<'!'<<num[i]<<' ';
		//}
		//cout<<endl;

		for(int i=0;i<n;++i){
			int sz=_map[i].size();
			for(int j=0;j<sz;++j){
				for(int k=j+1;k<sz;++k){
					--num[_map[i][j]+_map[i][k]];
				}
			}
		}

		//for(int i=0;i<=len;++i){
		//	cout<<num[i]<<' ';
		//}
		//cout<<endl;
		

		sum[0]=0;
		for(int i=1;i<=len;++i){
			sum[i]=sum[i-1]+num[i];
			if(i>1){
				int a1=i/2;
				int a2=i-a1;
				//cout<<(LL)sorted[a1-1]+sorted[a2-1]<<endl;
				gao.push_back((LL)sorted[a1-1]+sorted[a2-1]);
			}
		}
		sort(gao.begin(),gao.end());
		int kk=lower_bound(gao.begin(),gao.end(),(LL)k)-gao.begin();

		//cout<<kk<<' '<<gao.size()<<endl;

		if(gao[kk]!=(LL)k) --kk;
		kk+=2;

		LL ans=sum[len]-sum[kk];
		

		printf("%I64d\n",ans);
	}
	return 0;
}

