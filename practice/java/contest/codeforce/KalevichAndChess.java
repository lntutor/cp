//http://codeforces.com/problemset/problem/7/A
import java.io.IOException;
import java.util.Scanner;

public class Main {

    private static int SIZE = 8;

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        char[][] matrix = new char[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = line.charAt(j);
            }
        }

        int maxWhiteInRow = 0;
        int maxWhiteInCol = 0;

        for (int i = 0; i < SIZE; i++) {
            int countWhiteInRow = 0;
            int countWhiteInCol = 0;
            for (int j = 0; j < SIZE; j++) {
                if (matrix[i][j] == 'W') countWhiteInCol++;
                if (matrix[j][i] == 'W') countWhiteInRow++;
            }
            if (maxWhiteInCol < countWhiteInCol) maxWhiteInCol = countWhiteInCol;
            if (maxWhiteInRow < countWhiteInRow) maxWhiteInRow = countWhiteInRow;

        }
        if (maxWhiteInCol == 0 && maxWhiteInRow == 0) {
            System.out.println(SIZE);
        } else {
            System.out.println(2*SIZE - maxWhiteInRow - maxWhiteInCol);
        }
    }
}
