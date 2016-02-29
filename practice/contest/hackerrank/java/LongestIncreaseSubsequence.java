import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	private static int calLIS(int [] array) {
		Map<Integer, List<Integer>> lis = new HashMap<>();
		for (int i = 0; i < array.length; i++) {
			lis.put(i, new LinkedList<Integer>());
		}
		lis.get(0).add(array[0]);
		int longestIncSub = 1;
		for (int i = 1 ; i < array.length; i++) {
			for (int j = 0; j < i; j++) {
				if (array[i] >= array[j] && lis.get(i).size() < lis.get(j).size() + 1) {
					lis.get(i).clear();
					lis.get(i).addAll(lis.get(j));
				}
			}
			lis.get(i).add(array[i]);
			if (lis.get(i).size() > longestIncSub) {
				longestIncSub = lis.get(i).size();
			}
		}
		return longestIncSub;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(ob.readLine());
		int [] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = Integer.parseInt(ob.readLine());
			//System.out.println(array[i]);
		}

		System.out.println(calLIS(array));

	}
}