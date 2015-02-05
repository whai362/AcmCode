import java.util.*;
import java.math.*;
public class Main{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		BigInteger[][] a=new BigInteger[1005][3];
		for(int i=0;i<1005;++i){
			a[i]=new BigInteger[3];
			for(int j=0;j<3;++j){
				a[i][j]=new BigInteger("0");
			}
		}

		a[1][0]=new BigInteger("0");
		a[1][1]=new BigInteger("1");
		a[1][2]=new BigInteger("1");
		for(int i=2;i<1005;++i){
			a[i][0]=a[i-1][2];
			a[i][1]=a[i-1][1].multiply(BigInteger.valueOf(2));
			a[i][2]=a[i-1][0].add(a[i-1][1]);
		}
		while(in.hasNext()){
			int n=in.nextInt();
			System.out.println(a[n][0]);
		}
	}
}

