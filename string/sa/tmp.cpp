#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxx 20010
int wsf[maxx],wa[maxx],wv[maxx],wb[maxx],s[maxx];
int height[maxx],rank[maxx],sa[maxx];
int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void getsa(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)  wsf[i]=0;
    for(i=0;i<n;i++)  wsf[x[i]=r[i]]++;
    for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
    for(i=n-1;i>=0;i--)  sa[--wsf[x[i]]]=i;
    j=1;
    p=1;
    for(;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)  y[p++]=i;
        for(i=0;i<n;i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;
        for(i=0;i<n;i++)  wv[i]=x[y[i]];
        for(i=0;i<m;i++)  wsf[i]=0;
        for(i=0;i<n;i++)  wsf[wv[i]]++;
        for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
        for(i=n-1;i>=0;i--)  sa[--wsf[wv[i]]]=y[i];
        t=x;
        x=y;
        y=t;
        x[sa[0]]=0;
        for(i=1,p=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void getheight(int *r,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++)  rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)
        k--;
        else
        k=0;
        j=sa[rank[i]-1];
        while(r[i+k]==r[j+k])
        k++;
        height[rank[i]]=k;
    }
}
int deal(int n,int p)
{
    int minx=sa[0],maxx1=sa[0];
    for(int i=0;i<=n;i++)
    {
        if(height[i]>=p)
        {
            if(minx>sa[i])
            minx=sa[i];
            if(maxx1<sa[i])
            maxx1=sa[i];
            if(maxx1-minx>p)
            return 1;
        }
        else
        minx=maxx1=sa[i];
    }
    return 0;
}
int main()
{
    int n;
	cin>>n;
    //while(scanf("%d",&n)>0&&n)
    //{
        for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
        for(int i=0;i<n-1;i++)
        {
            s[i]=s[i+1]-s[i]+90;              //这里要注意，题目相当于把数据进行平移了，但是用后一个减去前一个再加上一个最大值的做法，虽然可以将之回复，但是第一个值可能会被改变，所以在最后需要把第一个值加上.....
            //printf("%d ",s[i]);
        }
        n--;
        s[n]=0;
        getsa(s,sa,n+1,200);
        getheight(s,n);
		for(int i=0; i<=n; ++i){
			cout<<sa[i]<<' ';
		}
		cout<<endl;
        int left=0,right=n,mid,coun=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(deal(n,mid))
            {
                //printf("%d %d %d\n",mid,left,right);
                if(coun<mid)
                coun=mid;
                left=mid+1;
            }
            else  right=mid-1;
        }
        if(coun<4) coun=0;
        else
        coun++;                     //这里+1，是为了将前面被改变了的第一个值加上.....
        //printf("%d\n",coun);
    //}
    return 0;
}
