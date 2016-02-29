import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(ob.readLine());
		BigInteger [] array = new BigInteger [n];
		String [] tmp = ob.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			array[i] = new BigInteger(tmp[i]);
		}
		Arrays.sort(array);
		BigInteger minDiff = new BigInteger(Integer.MAX_VALUE+"");
		int minIndex = 1;
		for (int i = 1; i < n; i++) {
			if (minDiff.compareTo(array[i].subtract(array[i-1])) > 0) {
				minDiff = array[i].subtract(array[i-1]);
				minIndex = i;
			}
		}

		StringBuilder builder = new StringBuilder();
		for (int i = 1; i < n; i++) {
			if (minDiff.equals(array[i].subtract(array[i-1]))) {
				builder.append(array[i-1] + " " + array[i] + " ");
			}
		}
		System.out.print(builder.toString().trim());
	}
}