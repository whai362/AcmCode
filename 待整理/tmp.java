import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger a,b;
		while(in.hasNext()){
			a=in.nextBigInteger();
			b=in.nextBigInteger();
			System.out.println(a.add(b));
		}
	}
}

