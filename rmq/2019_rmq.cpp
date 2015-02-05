#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=255;
int a[N][N];
int dpmin[N][N][8][8],
	dpmax[N][N][8][8];
void initRMQ(int n,int m){
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			dpmin[i][j][0][0]=dpmax[i][j][0][0]=a[i][j];
	for(int ii=0;(1<<ii)<=n;++ii)
		for(int jj=0;(1<<jj)<=m;++jj)
			if(ii+jj)
				for(int i=0;i+(1<<ii)-1<n;++i)
					for(int j=0;j+(1<<jj)-1<m;++j){
						if(ii){
							dpmin[i][j][ii][jj] = min(dpmin[i][j][ii-1][jj],dpmin[i+(1<<(ii-1))][j][ii-1][jj]);
                            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii-1][jj],dpmax[i+(1<<(ii-1))][j][ii-1][jj]);
						}
						else{
                            dpmin[i][j][ii][jj] = min(dpmin[i][j][ii][jj-1],dpmin[i][j+(1<<(jj-1))][ii][jj-1]);
                            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii][jj-1],dpmax[i][j+(1<<(jj-1))][ii][jj-1]);
                        }
					}
}
int rmq1(int x1,int y1,int x2,int y2)
{
	int k1=(int)(log((x2-x1+1)*1.0)/log(2.0));
	int k2=(int)(log((y2-y1+1)*1.0)/log(2.0));
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dpmax[x1][y1][k1][k2],dpmax[x1][y2][k1][k2]),max(dpmax[x2][y1][k1][k2],dpmax[x2][y2][k1][k2]));
}
int rmq2(int x1,int y1,int x2,int y2)
{
    int k1=(int)(log((x2-x1+1)*1.0)/log(2.0));
	int k2=(int)(log((y2-y1+1)*1.0)/log(2.0));
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return min(min(dpmin[x1][y1][k1][k2],dpmin[x1][y2][k1][k2]),min(dpmin[x2][y1][k1][k2],dpmin[x2][y2][k1][k2]));
}
int main(){
	int n,b,k;
	while(scanf("%d%d%d",&n,&b,&k)!=EOF){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&a[i][j]);
        initRMQ(n,n);
        int x,y;
        while(k--){
            scanf("%d%d",&x,&y);
            printf("%d\n",rmq1(x-1,y-1,x-1+b-1,y-1+b-1)-rmq2(x-1,y-1,x-1+b-1,y-1+b-1));
        }
    }
	return 0;
}
