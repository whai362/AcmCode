/*mu[d]为莫比乌斯函数，定义如下：
  (1)若d=1,则mu[d]=1;
  (2)若d=P1*P2*P3*...*Pk,Pi为互异的素数,那么mu[d]=(-1)^k;
  (3)其他情况mu[d]=0;

  mu[d]的性质：
  1. 对于任意正整数n有：
  (1)sigma(d|n,mu[d])=1,当n=1时;
  (2)sigma(d|n,mu[d])=0,当n>1时;

  2.对于任意正整数n有：
  sigma(d|n,mu[d]/d)=phi(n)/n,其中phi(n)为欧拉函数

  莫比乌斯反演公式的两种写法：
  1. F(n)=sigma(d|n,f(d)) -> f(n)=sigma(d|n,mu[d]*F(n/d))
  2. F(n)=sigma(n|d,f(d)) -> f(n)=sigma(n|d,mu[d/n]*F(d))

  写法二比较常用。
 */

//利用定义预处理
const int N=1e5+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

//素数筛法预处理
const int N=1e5+5;
int mu[N],pri[N],pcnt;
bool vis[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else{
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
}

