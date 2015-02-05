/*poj 3581
  题意：给定N个数字组成的序列A1,A2,...,An。其中A1比其他数字都大。现在要把这个序列分成三段，并将每段分别反转，求能得到的字典序最小的序列是什么？要求分得的每段都不为空。
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n,
	a[N],rev[N*2];

//后缀数组模板
//注意k是全局变量不要乱用
int k;	//用于倍增法求后缀数组的全局变量
int rank[N],tmp[N];
int sa[N*2];
bool cmp_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n? rank[i+k]:-1;
		int rj=j+k<=n? rank[j+k]:-1;
		return ri<rj;
	}
}
void build_sa(int *arr,int *sa){
	//n=strlen(arr);
	for(int i=0;i<=n;++i){
		sa[i]=i;
		rank[i]=i<n?arr[i]:-1;
	}
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;++i){
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp_sa(sa[i-1],sa[i])?1:0);
		}
		for(int i=0;i<=n;++i){
			rank[i]=tmp[i];
		}
	}
}
void gao(){
	reverse_copy(a,a+n,rev);
	build_sa(rev,sa);

	//确定第一段的分割位置
	int p1;
	for(int i=0;i<n;++i){
		p1=n-sa[i];
		if(p1>=1 && n-p1>=2) break;
	}
	//将p1之后的字符串翻转并重复2次，再计算其后的后缀数组
	int m=n-p1;
	reverse_copy(a+p1,a+n,rev);
	reverse_copy(a+p1,a+n,rev+m);

	int cp=n;
	n=m*2;
	build_sa(rev,sa);

	n=cp;
	//确定后两段的分割位置
	int p2;
	for(int i=0;i<=2*m;++i){
		p2=p1+m-sa[i];
		if(p2-p1>=1 && n-p2>=1) break;
	}
	reverse(a,a+p1);
	reverse(a+p1,a+p2);
	reverse(a+p2,a+n);
	for(int i=0;i<n;++i)
		printf("%d\n",a[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	gao();
	return 0;
}
