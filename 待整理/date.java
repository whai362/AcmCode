import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
public class date{
	public static void main(String[] args) throws Exception {
		//年月日加减
		/*SimpleDateFormat sdf=new SimpleDateFormat("yyyyMMdd");
		  String str="17770430";
		  Date date1=sdf.parse(str);
		  Calendar cal=Calendar.getInstance();
		  cal.setTime(date1);	//Date转Calendar
		//cal.add(Calendar.YEAR,-1);//日期减1年
		//cal.add(Calendar.MONTH,3);//日期加3个月
		cal.add(Calendar.DAY_OF_YEAR,5343);//日期加5343天
		Date date2=cal.getTime();	//Calendar转Date
		String s=sdf.format(date2);
		System.out.println(s);*/

		//星期
		SimpleDateFormat sdf=new SimpleDateFormat("yyyyMMdd");
		String s="22991231";
		Date date=sdf.parse(s);
		Calendar cal=Calendar.getInstance();
		cal.setTime(date);
		int week=cal.get(Calendar.DAY_OF_WEEK);
		System.out.println(week);	//星期表示1-7，是从星期日开始
	}
}

/*Calendar转化为Date()
  Calendar cal=Calendar.getInstance();
  Date() date=cal.getTime();

  Date转化为Calendar
  Date date=new Date();
  Calendar cal=Calendar.getInstance();
  cal.setTime(date);*/

/*日期格式
  yyyy-MM-dd hh:mm:ss*/

/*计算相隔天数
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
  */
/*
import java.util.Calendar;
import java.util.Date;
public class Main {
	public static void main(String[] args) {
		for (int i = 1999;; i += 100) {
			Calendar calendar = Calendar.getInstance();
			calendar.setTime(new Date(i - 1900, 11, 31));
			if (calendar.get(Calendar.DAY_OF_WEEK) - 1 == 0) {
				System.out.println(i);
				return;
			}
		}
	}
}
*/
