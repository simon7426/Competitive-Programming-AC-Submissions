/**
 * Created by ASUS on 10/22/2016.
 */
import java.util.Scanner;
import java.util.Arrays;
 
public class c723a {
    public static void main(String args[])
    {
        int[] a;
        a=new int[3];
        Scanner s;
        s=new Scanner(System.in);
        a[0]=s.nextInt();
        a[1]=s.nextInt();
        a[2]=s.nextInt();
        Arrays.sort(a);
        System.out.println(a[2]-a[0]);
    }
}