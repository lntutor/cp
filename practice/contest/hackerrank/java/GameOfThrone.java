//https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/game-of-thrones/submissions/code/4149531
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	private static boolean isPalindrom(String input) {
		int array[] = new int[255];
		for (int i = 0; i < 255; i++)
			array[i] = 0;

		for(int i = 0; i < input.length() ; i++){
			array[input.charAt(i)] +=1;
		}

		int odd = 0;
		for (int i = 0; i < 255; i++) {
			if (array[i] % 2 == 1) odd +=1;
		}

		if (odd <= 1) return true;

		return false;

	}
	public static void main(String[] args) {
		Scanner myScan = new Scanner(System.in);
		String inputString = myScan.nextLine();

		System.out.println(isPalindrom(inputString) ? "YES" : "NO");
//		String ans;

		// Assign ans a value of YES or NO, depending on whether or not inputString satisfies the required condition
//		System.out.println(ans);
		myScan.close();
	}
}
