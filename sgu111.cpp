//第一次写java                  
//Java笔记
//大数二分
import java.io.*;  
import java.math.*;  
import java.util.*;  
public class Solution
{
    public static void main(String[] args)
    {  
     BigInteger n,midd;
     BigInteger ans= new BigInteger("-1");
     BigInteger r = new BigInteger("10");
     BigInteger l = new BigInteger("1");
     Scanner cin = new Scanner(new BufferedInputStream(System.in));  
     BigInteger o = new BigInteger("1");
     BigInteger zero = new BigInteger("0");
     BigInteger mid=new BigInteger("1");
     n=cin.nextBigInteger();
     r=r.pow(500);

     while(r.subtract(l).compareTo(o)==1)
     {
      mid = r.add(l).shiftRight(1);
      midd = mid.pow(2);
      int f = n.compareTo(midd);
      if(f==1)
       l=mid.add(o);
      if(f==-1)
       r=mid;
      if(f==0)
      {
       ans=mid;
       break;
      }
     }
     if(ans.compareTo(zero)==-1)
      if(r.pow(2).compareTo(n)!=1)
       ans=r;
      else
       if(l.pow(2).compareTo(n)!=1)
        ans=l;
       else
     ans=l.subtract(o);
     System.out.print(ans);
    }  
}