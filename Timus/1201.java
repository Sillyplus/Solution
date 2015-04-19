/*******************************************************************************
	> File Name: 1201.java
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Apr 19 23:56:01 2015
*******************************************************************************/

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        BigInteger ans = new BigInteger("36");
        BigInteger x = new BigInteger("55");
        for (int i  = 1; i < k; i++)
            ans = ans.multiply(x);
        System.out.println(ans);
    }
}
