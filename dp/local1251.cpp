/*njoj 1251 zlly长了一张包子脸
  题意：
  zlly长了一张包子脸，他特别喜欢吃糖果，现在他手头有若干种糖果，每种糖果有个口味值，每种糖果有无数多个。然后娄童鞋也非常喜欢吃糖果，他的口味特别广泛，他喜欢各种各样的口味值，他要求zlly用现有的口味值拼出新的口味值。现在，娄童鞋想知道他不能吃到的口味值最大是多少？你能帮他的忙吗？
  举个例子，现在zlly手头有3,6,10三种糖果，他拼不出口味值为1、2、4、5、7…17的糖果，所以结果就是17。
  另外，糖果种类数<=10，每种糖果的口味值<=265，可以保证最大的结果不超过2,000,000,000。如果都可以拼出或最大值不存在，输出0。
  思路：
  其实2*1e9是虚的，
  gcd(a1,...,an)!=1时，无解，
  gcd(a1,...,an)==1时，有解，解的上界为max(ai*aj)，不会证，
  所以暴力即可。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15;
const int MAX_N=1000005;
int a[N];
bool arr[MAX_N];
void gao(int n){
	memset(arr,0,sizeof(arr));
	int gcd=a[0];
	for(int i=1;i<n;++i){
		gcd=__gcd(gcd,a[i]);
	}
	if(gcd!=1){
		puts("0");
		return ;
	}
	int _min=300;
	for(int i=0;i<n;++i)
		_min=min(a[i],_min);
	int cnt=0;
	int ans;
	arr[0]=1;
	for(int i=1;i<MAX_N;++i){
		for(int j=0;j<n;++j){
			if(a[j]>i) continue;
			if(arr[i-a[j]]){
				arr[i]=1;
				break;
			}
		}
		if(arr[i]) ++cnt;
		else cnt=0;
		if(cnt==_min){
			ans=i-_min;
			break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		gao(n);
	}
	return 0;
}
