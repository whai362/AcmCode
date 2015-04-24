/*zoj 3344 Card Game
  题意：
  把n张写有数字(数字范围为1~n,且互不相同)的卡片打乱顺序，然后放到编号为1~n的盒子里，每轮进行的动作如下：先从剩余的编号最小的盒子里取出卡片，设卡片写着k，如果第k个盒子还没有被打开过，则继续打开第k个盒子，取出卡片...直到没有盒子可以被打开。取完最后一个盒子的为胜利者。
  EZ想知道他在m轮之内能赢得游戏的概率。
  限制：
  1 <= n <= 50; 1 <= k <= n
  思路：
  第一类斯特林数，EZ只有在分拆的份数位奇数且份数小于m的时候才是胜利的。
  n=50，要用java大数。
 */
import java.math.BigInteger;
import java.security.GuardedObject;
import java.util.*;
public class Main{
	static BigInteger[][] sti=new BigInteger[55][55];
	static void get_sti(int n){
		for(int i=1;i<=n;++i){
			sti[i][0]=BigInteger.ZERO;
			sti[i][i]=BigInteger.ONE;
		}
		for(int i=2;i<=n;++i){
			for(int j=1;j<i;++j){
				sti[i][j]=BigInteger.valueOf(i-1).multiply(sti[i-1][j]).add(sti[i-1][j-1]);
			}
		}
	}
	static void print(int n){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				System.out.print(sti[i][j]+" ");
			}
			System.out.println("");
		}
	}
	static void gao(int n,int k){
		BigInteger fz,fm,d;
		fz=fm=BigInteger.ZERO;
		for(int i=1;i<=n;++i){
			if(i%2==1 && i<=k)
				fz=fz.add(sti[n][i]);
			fm=fm.add(sti[n][i]);
		}
		d=fz.gcd(fm);
		System.out.println(fz.divide(d)+"/"+fm.divide(d));
	}
	public static void main(String args[]){
		get_sti(50);
		Scanner in=new Scanner(System.in);
		int n,k;
		while(in.hasNext()){
			n=in.nextInt();
			k=in.nextInt();
			gao(n,k);
		}
	}
}
