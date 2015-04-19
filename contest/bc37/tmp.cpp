#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int next[10005];
void getNext(char T[]){
	int i,j;
	i=0;
	j=next[0]=-1;
	int tlen=strlen(T);
	while(i<tlen){
		if(j==-1 || T[i]==T[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}

/*void getNext(char *p,int next[])
{
	int len_p=strlen(p);
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<len_p-1)
	{
		if(k==-1 || p[k]==p[j])
		{
			k++;
			j++;
			//未优化 
			next[j]=k;
			//优化
//			if(p[k]!=p[j])
//				next[j]=k;
//			else
//				next[j]=next[k];
		}
		else
		{
			k=next[k];
		}
	}
}*/

//int Kmp(char *s,char *p)
//{
//	int len_s=strlen(s);
//	int len_p=strlen(p);
//	int i=0;
//	int j=0;
//	while(i<len_s && j<len_p)
//	{
//		if(j==-1 || s[i]==p[j])
//		{
//			i++;
//			j++;
//		}
//		else
//			j=next[j];
//	}
//	if(j==len_p)
//		return i-j;
//	else
//		return -1;
//}

int KmpSearch(char *s,char *p)
{
	int len_s=strlen(s);
	int len_p=strlen(p);
	int i=0;
	int j=0;
	int ans=0;
	while(i<len_s)
	{
		if(j==-1 || s[i]==p[j])
		{
			j++;
			//i++;
		}
		else
			j=next[j];
		if(j==len_p)
		{
			ans++;
			//i--;
			//--j;
			j=next[j];
		}
		++i;
	}
	return ans;
}

char s[1000005],p[10005];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		memset(next,0,sizeof(next));
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		scanf("%s",p);
		scanf("%s",s);
		getNext(p);
		//for(int i=0;i<=strlen(p);++i){
		//	cout<<next[i]<<' ';
		//}
		//cout<<endl;
		printf("%d\n",KmpSearch(s,p));
	}
	return 0;
}
