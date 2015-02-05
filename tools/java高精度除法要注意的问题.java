//java高精度除法要注意的问题
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		BigDecimal a,b;
		a=in.nextBigDecimal();
		b=in.nextBigDecimal();
		System.out.println(a.divide(b, 4, BigDecimal.ROUND_HALF_UP)); 
	}
}
