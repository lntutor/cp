// https://www.hackerrank.com/challenges/stockmax/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(ob.readLine());
		while(testcase-->0){
			int n = Integer.parseInt(ob.readLine());
			BigInteger [] stock = new BigInteger[n];
			String[] tmp = ob.readLine().split(" ");
			for (int i = 0; i < n; i++) {
				stock[i] = new BigInteger(tmp[i]);
			}

			BigInteger profit = new BigInteger("0");
			BigInteger currentMax = stock[n-1];
			for (int i = n-2; i >=0 ; i--) {
				if (currentMax.compareTo(stock[i]) < 0) {
					currentMax = stock[i];
				}
				profit = profit.add(currentMax.subtract(stock[i]));
			}
			System.out.println(profit);
		}
	}
}