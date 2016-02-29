//https://www.hackerrank.com/challenges/fibonacci-modified/submissions/code/14925272

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	private static BigInteger fib(int first, int second, int n){
		BigInteger[] array = new BigInteger[n];
		for (int i = 0; i < n ; i++) {
			if (i == 0) array[i] = new BigInteger(first+"");
			else if (i == 1) array[i] = new BigInteger(second + "");
			else {
				array[i] = array[i-1].multiply(array[i-1]).add(array[i-2]);
			}
		}
		return array[n-1];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader ob=new BufferedReader(new InputStreamReader(System.in));
		String [] line = ob.readLine().split(" ");
		int first = Integer.parseInt(line[0]);
		int second = Integer.parseInt(line[1]);
		int n = Integer.parseInt(line[2]);
		System.out.println(fib(first, second, n));

	}
}