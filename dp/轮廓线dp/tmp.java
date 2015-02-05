//题意：
//求一个字符串str的所有长度为n的子串，其中原串的不同字符个数为nc，这个题用枚举找出所有的子串，遍历即可，但是需要判重，例如:
import java.util.*;
class Main{
	public static void main(String[] args){
		Map<String,Integer> hash=new HashMap<String,Integer>();
		String str="123456";
		System.out.println(str.substring(2,5));
	}
}

