
// http://codeforces.com/problemset/problem/46/B
import java.io.IOException;
import java.util.*;

public class Main {
    public static final String S = "S";
    public static final String M = "M";
    public static final String L = "L";
    public static final String XL = "XL";
    public static final String XXL = "XXL";
    public static final int NUM_OF_SIZE = 5;

    public static int[] allSize = new int [NUM_OF_SIZE];
    private static int getIndexOfSize(String size) {
        switch (size) {
            case S:
                return 0;
            case M:
                return 1;
            case L:
                return 2;
            case XL:
                return 3;
            case XXL:
                return 4;
        }
        return 0;
    }

    private static String getSizeOfIndex(int index) {
        switch (index) {
            case 0:
                return S;
            case 1:
                return M;
            case 2:
                return L;
            case 3:
                return XL;
            case 4:
                return XXL;
        }
        return S;
    }
    private static String findBestSuiteSize(String size){

        int index = getIndexOfSize(size);
        if (allSize[index]>0) {
            allSize[index] -=1;
            return size;
        }
        int right = index;
        // find on the right
        while (right < NUM_OF_SIZE) {
            if (allSize[right] > 0) break;
            right++;
        }

        if (right < NUM_OF_SIZE && right - index == 1) {
            allSize[right] -=1;
            return getSizeOfIndex(right);//found on right
        }

        int left = index;
        // find on the right
        while (left >= 0) {
            if (allSize[left] > 0) break;
            left--;
        }
        if (left >=0 && left - index == 1) {
            allSize[left] -=1;
            return getSizeOfIndex(left);//found on right
        }


        if (left < 0) {
            allSize[right] -=1;
            return  getSizeOfIndex(right);
        } else if (right >= NUM_OF_SIZE){
            allSize[left] -=1;
            return getSizeOfIndex(left);
        } else {
            int diffLeft = index - left;
            int diffRight = right - index;
            if (diffLeft < diffRight) {
                allSize[left] -=1;
                return getSizeOfIndex(left);
            } else {
                allSize[right] -=1;
                return  getSizeOfIndex(right);
            }
        }


    }
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        allSize[0] = scanner.nextInt();
        allSize[1] = scanner.nextInt();
        allSize[2] = scanner.nextInt();
        allSize[3] = scanner.nextInt();
        allSize[4] = scanner.nextInt();

        int n = scanner.nextInt();
        scanner.nextLine();// go to next line of n

        for(int i = 0; i < n; i++) {
            System.out.println(findBestSuiteSize(scanner.nextLine()));
        }
    }
}
