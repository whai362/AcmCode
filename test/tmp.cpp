#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
struct data{
	int id,value;
}a[N];
bool cmp(data a,data b){
	return a.value<b.value;
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i].value);
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;++i){
		a[a[i].id].value=i;
	}
	for(i=0;i<n;++i){
		printf("%d ",a[i].value);
	}
	printf("\n");
	return 0;
}

