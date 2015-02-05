import java.text.*; 
import java.util.*;
public class Cal{
	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		String str1,str2;
		double day;
		str1=input.next();
		str2=input.next();
		SimpleDateFormat d=new SimpleDateFormat("yyyy:MM:dd");
		Date date1=null,date2=null;
		try{
			date1=d.parse(str1);
			date2=d.parse(str2);
		}
		catch (ParseException e) {
			e.printStackTrace();
		}
		if(date1.getTime()>date2.getTime())
			day=date1.getTime()-date2.getTime()+9*1000*60*60;
		else
			day=date2.getTime()-date1.getTime()+9*1000*60*60;
		day=day/(1000*60*60*24);
		System.out.println((int)day);
	}
}
