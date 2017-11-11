//水
import java.io.*;  
import java.math.*;  
import java.util.*;  
public class Solution
{
    public static void main(String[] args)
    {  
     BigInteger a,b;
     BigInteger ans= new BigInteger("-1");
     Scanner cin = new Scanner(new BufferedInputStream(System.in));  
     BigInteger o = new BigInteger("1");
     BigInteger zero = new BigInteger("0");
     a = cin.nextBigInteger();
     b = cin.nextBigInteger();
     int aa=a.intValue();
     int bb=b.intValue();
     ans=a.pow(bb).subtract(b.pow(aa));
     System.out.print(ans);
    }  
}
