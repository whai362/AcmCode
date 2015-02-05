#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int N=7000005;
int s[6],e[6];
int sta[]={123456,653412,563421,431256,342156,213465,436512,345612,435621,346521,651243,561234,214356,652134,562143,432165,341265,216543,126534,564312,215634,125643,654321,124365};
int step[]={0,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4};
int ans[N];
int main(){
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<24;++i){
        ans[sta[i]]=step[i];
    }
    int h[10];
    while(scanf("%d%d%d%d%d%d",&s[0],&s[1],&s[2],&s[3],&s[4],&s[5])!=EOF){
        scanf("%d%d%d%d%d%d",&e[0],&e[1],&e[2],&e[3],&e[4],&e[5]);
        memset(h,0,sizeof(h));
        for(int i=0;i<6;++i){
            h[s[i]]=i+1;
        }
        /*for(int i=1;i<7;++i){
            cout<<h[i]<<' ';
        }
        cout<<endl;*/
        int gen=0;
        for(int i=0;i<6;++i){
            gen=gen*10+h[e[i]];
        }
        //cout<<gen<<endl;
        printf("%d\n",ans[gen]);
    }
    return 0;
}
