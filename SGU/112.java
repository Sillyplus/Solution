/*******************************************************************************
	> File Name: 112.java
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun May 31 08:26:35 2015
*******************************************************************************/

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int a = cin.nextInt(), b = cin.nextInt();
        System.out.println(BigInteger.valueOf(a).pow(b).subtract(
                    BigInteger.valueOf(b).pow(a)));
    }
}

