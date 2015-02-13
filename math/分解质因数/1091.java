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
