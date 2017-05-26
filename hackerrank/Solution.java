import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++){
                String s1=sc.next();
                int x=sc.nextInt();
                System.out.printf(s1);
                for(int j=s1.length()+1;j<=15;++j) {
                    System.out.printf(" ");
                }
                System.out.printf("%03d\n",x);
                //Complete this line
            }
            System.out.println("================================");

    }
}
