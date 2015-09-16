import java.util.*;
class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(out);
		int T, N;
		T = in.nextInt();
		for (int TT = 1; TT <= T; TT++) {
			N = in.nextInt();
			BigInteger [] nums = new BigInteger[N];
			for (int i = 0; i < N; i++)
				nums[i] = in.nextBigInteger();
			Boolean yes = true;
			for (int i=1;i< N;i ++)
				yes &= nums[i].equals(nums[i-1]);
			if (yes)
			{
				out.println("Yes");
				continue;
			}
			yes = true;
			for (int i=0;i<N;i++)
				yes &= !nums[i].equals(new BigInteger("0"));
			if (!yes)
			{
				out.println("No");
				continue;
			}
			yes = true;
			for (int i=1;i< N- 1;i++)
				yes &= nums[i-1].multiply(nums[i+1]).equals(nums[i].multiply(nums[i]));
			if (yes)
				out.println("Yes");
			else
				out.println("No");
		}
		out.flush();
		in.close();
		out.close();
	}
}
