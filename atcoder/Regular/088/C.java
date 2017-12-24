import Java.util.*;
public class C{
	public static void main(String args[]) {
		Scanner console=new Scanner(system.in);
		BigInteger x=sc.nextBigInteger();
		BigInteger y=sc.nextBigInteger();
		int ans=1;
		while(x+x<=y) {
			x.mul(2);
			ans++;
		}
		System.out.println(ans);
	}
}
