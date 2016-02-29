// https://www.hackerrank.com/challenges/candies
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(ob.readLine());
		int [] rate = new int[n];
		for (int i = 0; i < n; i++) {
			rate[i] = Integer.parseInt(ob.readLine());
		}
		int [] candy = new int[n];
		candy[0] = 1;
		for (int i = 1; i < n; i++) {
			if (rate[i] <= rate[i-1]) {
				candy[i] = 1;
			} else if (rate[i] > rate[i-1]) {
				candy[i] = candy[i-1] + 1;
			}
		}
		for (int i = n-2; i >=0; i--) {
			if (rate[i] > rate[i+1] && candy[i] <= candy[i+1]) {
				candy[i] = candy[i + 1] + 1;
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += candy[i];
		}


		System.out.println(sum);

	}
}