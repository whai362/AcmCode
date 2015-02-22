/*poj 1091
  题意：
  给出了n和m，要求出满足最大公约数(x1,x2,...,xn,m)=1的x1,...,xn的组数sum，其中必须满足0 <= x1,x2,...,xn <= m。
  限制：
  n <= 15 , m <= 100000000
  思路：
  容斥原理
  容斥有两种做法
  1. 枚举m的因子来容斥
  2. 枚举最大公约数(x1,x2,...,xn,m)包含的质因子来容斥
  这里是第二种做法
 */
import java.math.*;
import java.util.*;
class Dt{
	int x,t;
	Dt(){}
	Dt(int _x,int _t){
		x=_x;
		t=_t;
	}
}
public class Main {
	static int[] fac=new int[105];
	static int tot;
	static void get_fac(int n){
		tot=0;
		int lim=(int)Math.sqrt((double)n);
		for(int i=2;i<=lim;++i){
			if(n%i==0) fac[tot++]=i;
			while(n%i==0) n/=i;
		}
		if(n!=1) fac[tot++]=n;
	}
	static void gao(int n,int m){
		Map<Integer, Integer> vis=new HashMap<Integer, Integer>();
		BigInteger ans=BigInteger.valueOf(m).pow(n);
		Dt[] que=new Dt[1000005];
		int head=0,tail=0;
		for(int i=0;i<tot;++i){ que[tail++]=new Dt(fac[i],1); vis.put(fac[i], 1); }
		while(head!=tail){
			Dt now=que[head++];
			if(now.t%2==0)
				ans=ans.add(BigInteger.valueOf(m/now.x).pow(n));
			else
				ans=ans.subtract(BigInteger.valueOf(m/now.x).pow(n));
			for(int i=0;i<tot;++i)
				if(now.x%fac[i]!=0 && !vis.containsKey(now.x*fac[i])){ que[tail++]=new Dt(now.x*fac[i],now.t+1); vis.put(now.x*fac[i], 1); }
		}
		System.out.println(ans);
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n,m;
		n=in.nextInt();
		m=in.nextInt();
		get_fac(m);
		gao(n, m);
	}
}
